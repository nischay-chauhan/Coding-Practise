/* Number of Islands... */
#include<bits/stdc++.h>
using namespace std;

class Solution{
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    public:
        int numLands(vector<vector<char>>& grid){
            int ROWS=grid.size();
            int COLS=grid[0].size();
            
            int islands = 0;

            for(int i = 0 ; i < ROWS; i++){
                for(int j = 0 ; j < COLS; j++){
                    if(grid[i][j] == '1'){
                        islands++;   
                    }
                }
            }
            return islands;
        }

        void dfs(int r , int j , vector<vector<char>>& grid){
            if(r < 0 || j < 0 || r >= grid.size() || j >= grid[0].size() || grid[r][j] == '0') return;
            grid[r][j] = '0';
            for(auto& dir : directions){
                int nr = r + dir[0];
                int nj = j + dir[1];
                dfs(nr , nj , grid);
            }
        }
};

