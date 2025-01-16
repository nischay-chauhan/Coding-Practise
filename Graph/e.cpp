#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> bfsOfGraph(int V , vector<int> adj[]){
            vector<int> vis(V, 0);
            vis[0] = 1;
            queue<int> q;

            q.push(0);
            vector<int> bfs;

            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for(auto it: adj[node]){
                    if(!vis[it]){
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
            return bfs;

        }

        vector<int> dfsOfGraph(int V, vector<int> adj[]){
            vector<int> vis(V, 0);
            vector<int> dfs;

            dfsUtil(0, vis, adj, dfs);
            return dfs;
        }

        void dfsUtil(int node, vector<int>& vis, vector<int> adj[], vector<int>& dfs){
            vis[node] = 1;
            dfs.push_back(node);

            for(auto it: adj[node]){
                if(!vis[it]){
                    dfsUtil(it, vis, adj, dfs);
                }
            }
        }
};

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int> ans){
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> adj[6];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 0);
    Solution obj;
    vector<int> bfs =  obj.bfsOfGraph(6, adj);
    vector<int> dfs =  obj.dfsOfGraph(6, adj);

    cout << "BFS Traversal: ";
    printAns(bfs);
    cout << "DFS Traversal: ";
    printAns(dfs);
}