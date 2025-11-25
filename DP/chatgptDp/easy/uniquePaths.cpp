/**

\9. Unique Paths

Robot moves to bottom-right in grid.
Example: 3x2 → 3
Concept: DP on grid

**/

#include <bits/stdc++.h>
using namespace std;

int uniquePaths(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1) dp[i][j] = 0;
            else{
                if(i > 0) dp[i][j] += dp[i-1][j];
                if(j > 0) dp[i][j] += dp[i][j-1];
            }
        }
    }
    return dp[n-1][m-1];
}

int main(){
    vector<vector<int>> grid = {{0,0,0},{0,1,0},{0,0,0}};
    cout << uniquePaths(grid) << "\n";
}