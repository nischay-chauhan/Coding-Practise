/* Given N, The task is to find the total number of unique BSTs that can be made using values from 1 to N. 

Examples: 

Input: N = 3 
Output: 5
Explanation: For N = 3, preorder traversal of Unique BSTs are:
1 2 3
1 3 2
2 1 3
3 1 2
3 2 1

Input: N = 4 
Output: 14

 */

#include <bits/stdc++.h>
using namespace std;

int NumberofBst(int n){
    vector <int> dp(n+1 , 0);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2 ; i <= n ; i++){
        for(int j = 1 ; j <= i ; j++){
            dp[i] += dp[j-1] * dp[i-j];
        }
    }
    return dp[n];

}

int main(){
    int n;
    cout << "Enter the value of n : " << endl;
    cin >> n;
    cout << NumberofBst(n) << endl;

}

