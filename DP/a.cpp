#include <bits/stdc++.h>
using namespace std;

int fib(int n, vector<int>& dp) {
    if (n <= 1) {
        return n;
    }
    
    if (dp[n] != -1) {
        return dp[n];
    }
    
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

int main() {
    int n = 10; 
    vector<int> dp(n + 1, -1); 
    int result = fib(n, dp);
    cout << "The " << n << "th Fibonacci number is: " << result << endl;
    
    return 0;
}
