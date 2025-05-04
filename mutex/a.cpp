#include <mutex>
#include <thread>
#include <iostream>
#include <vector>
#include <functional>
#include <condition_variable>

using namespace std;

class DiningPhilosophers {
private:
    int room = 4;
    std::mutex room_mutex;
    std::condition_variable room_cv;
    std::mutex forks[5];

public:
    DiningPhilosophers() {}

    void wantsToEat(int philosopher,
                    std::function<void()> pickLeftFork,
                    std::function<void()> pickRightFork,
                    std::function<void()> eat,
                    std::function<void()> putLeftFork,
                    std::function<void()> putRightFork) {
        
        int left = philosopher;
        int right = (philosopher + 1) % 5;

        // Acquire room (at most 4 philosophers)
        {
            std::unique_lock<std::mutex> lock(room_mutex);
            room_cv.wait(lock, [&]{ return room > 0; });
            --room;
        }

        forks[left].lock();
        forks[right].lock();

        pickLeftFork();
        pickRightFork();

        eat();

        putLeftFork();
        putRightFork();

        forks[right].unlock();
        forks[left].unlock();

        // Release room
        {
            std::lock_guard<std::mutex> lock(room_mutex);
            ++room;
        }
        room_cv.notify_one();
    }
};

int main() {
    DiningPhilosophers dp;

    auto pickLeftFork = []() { cout << "Pick left fork\n"; };
    auto pickRightFork = []() { cout << "Pick right fork\n"; };
    auto eat = []() { cout << "Eating\n"; };
    auto putLeftFork = []() { cout << "Put left fork\n"; };
    auto putRightFork = []() { cout << "Put right fork\n"; };

    vector<thread> philosophers;
    for (int i = 0; i < 5; ++i) {
        philosophers.emplace_back([&, i]() {
            dp.wantsToEat(i, pickLeftFork, pickRightFork, eat, putLeftFork, putRightFork);
        });
    }

    for (auto& t : philosophers) {
        t.join();
    }

    return 0;
}