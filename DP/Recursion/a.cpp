#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n = 10; 
    int result = fib(n);
    cout << "The " << n << "th Fibonacci number is: " << result << endl;
    return 0;
}
