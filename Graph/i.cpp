/* perimeter of the island */

#include <bits/stdc++.h>
using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int perimeter = 0;
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                perimeter += 4;
                
                if (j > 0 && grid[i][j - 1] == 1) {
                    perimeter -= 2; 
                }
                
                if (i > 0 && grid[i - 1][j] == 1) {
                    perimeter -= 2; 
                }
            }
        }
    }
    
    return perimeter;
}

int main() {
    vector<vector<int>> grid = {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };
    
    int result = islandPerimeter(grid);
    cout << "Perimeter of the island: " << result << endl;
    
    return 0;
}
