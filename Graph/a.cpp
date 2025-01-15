/* Number of Provinces

 Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Pre-req: Connected Components, Graph traversal techniques

 */
#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
        void dfs(int node , vector<int> adjLs[] , int vis[]){
            vis[node] = 1;
            for(auto neighbor : adjLs[node]){
                if(!vis[neighbor]){
                    dfs(neighbor, adjLs, vis);
                }
            }
        }
    public:
        int numberProvinces(vector<vector<int>> adj , int V){
            vector<int> adjLs[V];

            for(int i = 0 ; i < V ; i++){
                for(int j = 0 ; j < V ; j++){
                    if(adj[i][j] == 1 && i != j){
                        adjLs[i].push_back(j);
                        adjLs[j].push_back(i);
                    }
                }
            }

            int vis[V] = {0};
            int cnt = 0;
            for(int i =0 ; i < V ; i++){
                if(!vis[i]){
                    cnt++;
                    dfs(i , adjLs , vis);
                }
            }

            return cnt;

        }
};

int main(){
    vector<vector<int>> adj{
  {0, 1, 0, 0},
  {1, 0, 1, 0},
  {0, 1, 0, 1},
  {0, 0, 1, 0}
};

    Solution ob;
    cout << ob.numberProvinces(adj , 4) << endl;

    return 0;
}