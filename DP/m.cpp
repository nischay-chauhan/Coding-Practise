/* Coin exchange problem with coin tracking */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        vector<int> last_coin(amount + 1, -1); 
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                    if (dp[i] > dp[i - coin] + 1) {
                        dp[i] = dp[i - coin] + 1;
                        last_coin[i] = coin; 
                    }
                }
            }
        }
        
        if (dp[amount] == INT_MAX) {
            return -1;
        }
        
        // Print the coins used
        cout << "Coins used: ";
        int remaining = amount;
        while (remaining > 0) {
            int coin = last_coin[remaining];
            cout << coin << " ";
            remaining -= coin;
        }
        cout << endl;
        
        return dp[amount];
    }
};

int main() {
    Solution solution;
    
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    
    int result = solution.coinChange(coins, amount);
    cout << "Minimum coins needed: " << result << endl;
    
    return 0;
}

    