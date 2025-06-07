#include <iostream>
#include <queue>
#include <string>
using namespace std;

void generateBinaryNumbers(int N) {
    queue<string> q;
    q.push("1");

    for (int i = 0; i < N; ++i) {
        string current = q.front();
        q.pop();
        cout << current << endl;

        q.push(current + "0");
        q.push(current + "1");
    }
}

int main() {
    int N = 10;
    cout << "Binary numbers from 1 to " << N << ":\n";
    generateBinaryNumbers(N);
    return 0;
}
