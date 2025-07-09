#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int perimeter = 0;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        
                        for (auto& dir : directions) {
                            int nx = x + dir[0], ny = y + dir[1];
                            // If out of bounds or water, add to perimeter
                            if (nx < 0 || ny < 0 || nx >= rows || ny >= cols || grid[nx][ny] == 0) {
                                perimeter++;
                            } 
                            // If land and not visited, add to queue
                            else if (!visited[nx][ny]) {
                                visited[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        return perimeter;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<vector<int>> grid1 = {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };
    
    // Test case 2 - Single cell island
    vector<vector<int>> grid2 = {{1}};
    
    // Test case 3 - No island
    vector<vector<int>> grid3 = {{0}};
    
    cout << "Test 1 - Expected: 16, Got: " << sol.islandPerimeter(grid1) << endl;
    cout << "Test 2 - Expected: 4, Got: " << sol.islandPerimeter(grid2) << endl;
    cout << "Test 3 - Expected: 0, Got: " << sol.islandPerimeter(grid3) << endl;
    
    return 0;
}