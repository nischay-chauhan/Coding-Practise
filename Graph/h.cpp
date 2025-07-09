/* Binary matrix (8 directions) */

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<vector<int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
    int n = mat.size();
    int m = mat[0].size();
    queue<pair<int, int>> q;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(mat[i][j] == 0){
                q.push({i, j});
            }
        }
    }

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(auto& dir : directions){
            int nx = x + dir[0];
            int ny = y + dir[1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == 1){
                mat[nx][ny] = mat[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return mat;
}

int main(){
    int n , m;
    cin >> n >> m;
    vector<vector<int>> mat(n , vector<int>(m));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> mat[i][j];
        }
    }
    vector<vector<int>> result = updateMatrix(mat);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << result[i][j] << " ";
        }
    }
    cout << endl;
    return 0;
}