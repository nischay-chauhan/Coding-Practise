/* 2. Climbing Stairs

Ways to reach top with 1 or 2 steps.
Example: n=3 → 3
Concept: 1D DP
 */

 #include "bits/stdc++.h"
 using namespace std;
 
 int stairs(int n){
    if(n <= 1) return 1;
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
 }
 int main(){
    int n;
    cin >> n;
    cout << stairs(n) << "\n";
 }