#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <semaphore> // Requires C++20

std::mutex mtx;
std::counting_semaphore<3> sem(3); // Allow up to 3 threads in the critical section
int shared_counter = 0;

void worker(int id) {
    sem.acquire(); // Wait for a slot in the semaphore
    {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Thread " << id << " entered critical section.\n";
        ++shared_counter;
        std::cout << "Thread " << id << " incremented counter to " << shared_counter << ".\n";
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate work
    {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Thread " << id << " leaving critical section.\n";
    }
    sem.release(); // Release the slot in the semaphore
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 8; ++i) {
        threads.emplace_back(worker, i);
    }
    for (auto& t : threads) {
        t.join();
    }
    std::cout << "Final counter value: " << shared_counter << std::endl;
    return 0;
}
