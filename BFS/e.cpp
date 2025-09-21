#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            vector<vector<pair<int, int>>> adj(n);
            for (auto& f : flights) {
                int u = f[0], v = f[1], w = f[2];
                adj[u].push_back({v, w});
            }
    
            priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
            pq.push({0, src, 0});
    
            while (!pq.empty()) {
                auto [cost, node, stops] = pq.top();
                pq.pop();
                if (node == dst) return cost;
                if (stops > k) continue;
    
                for (auto& [nei, price] : adj[node]) {
                    pq.push({cost + price, nei, stops + 1});
                }
            }
    
            return -1;
        }
    };

int main() {
    Solution sol;
    
    // Test case 1
    vector<vector<int>> flights1 = {{0,1,100},{1,2,100},{0,2,500}};
    int n1 = 3, src1 = 0, dst1 = 2, k1 = 1;
    cout << "Test Case 1: " << sol.findCheapestPrice(n1, flights1, src1, dst1, k1) << endl;  // Expected: 200
    
    // Test case 2
    vector<vector<int>> flights2 = {{0,1,100},{1,2,100},{0,2,500}};
    int n2 = 3, src2 = 0, dst2 = 2, k2 = 0;
    cout << "Test Case 2: " << sol.findCheapestPrice(n2, flights2, src2, dst2, k2) << endl;  // Expected: 500
    
    // Test case 3 - No path exists
    vector<vector<int>> flights3 = {{0,1,100}};
    int n3 = 3, src3 = 0, dst3 = 2, k3 = 1;
    cout << "Test Case 3: " << sol.findCheapestPrice(n3, flights3, src3, dst3, k3) << endl;  // Expected: -1
    
    return 0;
}