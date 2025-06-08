#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            adj[i].push_back(i + 1);  
        }

        auto shortest_path = [&]() -> int {
            queue<pair<int, int>> q;
            vector<bool> visited(n, false);
            q.push({0, 0});  
            visited[0] = true;

            while (!q.empty()) {
                auto [cur, length] = q.front();
                q.pop();

                if (cur == n - 1)
                    return length;

                for (int nei : adj[cur]) {
                    if (!visited[nei]) {
                        visited[nei] = true;
                        q.push({nei, length + 1});
                    }
                }
            }

            return -1;  
        };

        vector<int> res;
        for (const auto& q : queries) {
            int src = q[0], dst = q[1];
            adj[src].push_back(dst);            
            res.push_back(shortest_path());     
        }

        return res;
    }
};
