#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][W];
}

string lcs(string X, string Y) {
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i-1] == Y[j-1]) {
            lcs = X[i-1] + lcs;
            i--; j--;
        }
        else if (dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }
    return lcs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Example of knapsack
    int W = 50;  // Weight capacity
    vector<int> wt = {10, 20, 30};
    vector<int> val = {60, 100, 120};
    int n = wt.size();
    
    cout << "Maximum value in Knapsack: " << knapsack(W, wt, val, n) << "\n";
    
    // Example of LCS
    string str1 = "ABCDGH";
    string str2 = "AEDFHR";
    cout << "Longest Common Subsequence: " << lcs(str1, str2) << "\n";
    
    return 0;
}
