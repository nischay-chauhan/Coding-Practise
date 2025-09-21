#include <iostream>
#include <vector>

using namespace std;

/* 797. All Paths From Source to Target */
class Solution {
    public:
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
            vector<vector<int>> result;
            vector<int> path;
            dfs(0, graph, path, result);
            return result;
        }
        
        void dfs(int node, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& result) {
            path.push_back(node);
            
            if (node == graph.size() - 1) {
                result.push_back(path);
            } else {
                for (int neighbor : graph[node]) {
                    dfs(neighbor, graph, path, result);
                }
            }
    
            path.pop_back(); // backtrack
        }
    };

void printResult(const vector<vector<int>>& result) {
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "\n  [";
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j != result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i != result.size() - 1) cout << ",";
    }
    cout << "\n]\n";
}

int main() {
    Solution sol;
    
    // Test case 1: Simple graph with two paths
    cout << "Test Case 1:\n";
    vector<vector<int>> graph1 = {{1,2}, {3}, {3}, {}};
    auto result1 = sol.allPathsSourceTarget(graph1);
    printResult(result1);
    /* Expected Output:
    [
      [0,1,3],
      [0,2,3]
    ]
    */

    // Test case 2: Graph with multiple paths
    cout << "\nTest Case 2:\n";
    vector<vector<int>> graph2 = {{4,3,1}, {3,2,4}, {3}, {4}, {}};
    auto result2 = sol.allPathsSourceTarget(graph2);
    printResult(result2);
    /* Expected Output:
    [
      [0,4],
      [0,3,4],
      [0,1,3,4],
      [0,1,2,3,4],
      [0,1,4]
    ]
    */

    // Test case 3: Single node graph
    cout << "\nTest Case 3:\n";
    vector<vector<int>> graph3 = {{}};
    auto result3 = sol.allPathsSourceTarget(graph3);
    printResult(result3);
    /* Expected Output:
    [
      [0]
    ]
    */

    return 0;
}