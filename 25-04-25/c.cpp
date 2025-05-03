#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int solve(vector<int>& stones , int l , int r , vector<vector<int>> & dp , vector<int>& prefix){
            if(l == r) return 0;
            if(dp[l][r] != -1) return dp[l][r];

            int maxScore = 0;
            for(int i = l ; i < r ; i++){
                int leftSum = prefix[i+1] - prefix[l];
                int rightSum = prefix[r+1] - prefix[i+1];

                if(leftSum < rightSum){
                    maxScore = max(maxScore , leftSum + solve(stones , l , i , dp , prefix));
                }else if (leftSum > rightSum){
                    maxScore = max(maxScore , rightSum + solve(stones , i+1 , r , dp , prefix));
                } else {
                    maxScore = max(maxScore , leftSum + max(solve(stones , l , i , dp , prefix) , solve(stones , i+1 , r , dp , prefix)));
                }
            }

            return dp[l][r] = maxScore;
        }
        int stoneGameMaxScore(vector<int>& stoneValue) {
                int n = stoneValue.size();
                vector<vector<int>> dp(n, vector<int>(n, -1));
                vector<int> prefix(n + 1, 0);

                for (int i = 0; i < n; ++i) {
                    prefix[i + 1] = prefix[i] + stoneValue[i];
                }

                return solve(stoneValue, 0, n - 1, dp, prefix);
            }
};


int main() {
    vector<int> stones = {6, 2, 3, 4, 5, 5};
    Solution sol;
    cout << sol.stoneGameMaxScore(stones) << endl;
    return 0;
}