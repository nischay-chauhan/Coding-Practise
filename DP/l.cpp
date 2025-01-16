/* Maximum sum of non adjacent elements 

Given an array of ‘N’  positive integers, we need to return the maximum sum of the subsequence such that no two elements of the subsequence are adjacent elements in the array.

Note: A subsequence of an array is a list with elements of the array where some elements are deleted ( or not deleted at all) and the elements should be in the same order in the subsequence as in the array.

*/
#include <bits/stdc++.h>
using namespace std;

int solveUtil(int ind , vector<int>& arr , vector<int>& dp){
    if(dp[ind] != -1){
        return dp[ind];
    }

    if(ind == 0){
        return arr[ind];
    }

    if(ind < 0){
        return 0;
    }

    int pick = arr[ind] + solveUtil(ind-2 , arr , dp);
    int notPick = 0 + solveUtil(ind-1 , arr , dp);

    return dp[ind] = max(pick , notPick);
}

int solve(int n , vector<int>& arr){
    vector<int> dp(n , -1);
    return solveUtil(n-1 , arr , dp);
}

int main(){
    vector<int> arr = {2 , 1 , 4 , 9};
    int n = arr.size();

    cout << solve(n, arr);

    return 0;
}