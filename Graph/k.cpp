#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c]) {
                    res += 4;
                    if (r && grid[r - 1][c]) {
                        res -= 2;
                    }
                    if (c && grid[r][c - 1]) {
                        res -= 2;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> grid1 = {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };
    
    vector<vector<int>> grid2 = {{1}};
    
    vector<vector<int>> grid3 = {{0}};
    
    vector<vector<int>> grid4 = {
        {1,1},
        {1,1}
    };
    
    cout << "Test 1 - Expected: 16, Got: " << sol.islandPerimeter(grid1) << endl;
    cout << "Test 2 - Expected: 4, Got: " << sol.islandPerimeter(grid2) << endl;
    cout << "Test 3 - Expected: 0, Got: " << sol.islandPerimeter(grid3) << endl;
    cout << "Test 4 - Expected: 8, Got: " << sol.islandPerimeter(grid4) << endl;
    
    return 0;
}