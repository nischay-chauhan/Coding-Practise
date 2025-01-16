/*

*/

#include <bits/stdc++.h>
using namespace std;

void printBeautifully(int **adj, int n){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n, m;
    cout << "Enter the number of vertices (n): ";
    cin >> n;
    cout << "Enter the number of edges (m): ";
    cin >> m;

    // adjency matrix for undirected graph 
    // time complexity : O(n)

    int **adj = new int*[n+1];
    for(int i = 0; i <= n; i++){
        adj[i] = new int[n+1];
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            adj[i][j] = 0;
        }
    }

    cout << "Enter the edges (u v) where u and v are vertices between 1 and " << n << ":" << endl;
    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u][v]  = 1;
        adj[v][u] = 1;
    }

    cout << "Adjacency matrix:" << endl;
    printBeautifully(adj, n);

    for(int i = 0; i <= n; i++){
        delete[] adj[i];
    }
    delete[] adj;

    return 0;
}