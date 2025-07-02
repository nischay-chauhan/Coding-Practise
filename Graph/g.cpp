/* Bellman-Ford Algorithm for negtive weights graph*/
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> bellmanFord(vector<vector<int>>& edges , int n , int src , int dest){
    vector<int> dist(n , INT_MAX);
    vector<int> parent(n , -1);
    dist[src] = 0;
    //relax all edges n-1 times
    for(int i = 0 ; i < n - 1 ; i++){
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if(dist[u] != INT_MAX && dist[u] + w < dist[v]){}
        }
    }

    //check for negative cycle
    for(auto& edge : edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
            return {};
        }
    }

    //reconstuct path 
    vector<int> path;
    for(int at = dest ; at != -1 ; at = parent[at]){
        path.push_back(at);
    }
    reverse(path.begin() , path.end());
    return path;
}

int main(){
    int n , m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for(int i = 0 ; i < m ; i++){
        int u , v , w;
        cin >> u >> v >> w;
        edges.push_back({u , v , w});
    }
    int src , dest;
    cin >> src >> dest;
    vector<int> path = bellmanFord(edges , n , src , dest);
    if(path.empty()){
        cout << "Negative cycle detected" << endl;
    }
    else{
        cout << "Shortest path from " << src << " to " << dest << " is " << path.size() << endl;
    }
}