/* djikstra algorithm */
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
#include <iostream>

vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int src, int dest) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX), parent(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[src] = 0;
    pq.push({0, src});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto& [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    
    // Reconstruct path
    vector<int> path;
    if (dist[dest] == INT_MAX) {
        return path;
    }
    for (int at = dest; at != -1; at = parent[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int n, m;
    std::cout << "Enter number of nodes and edges: ";
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> graph(n);
    std::cout << "Enter edges (u v w) as 0-based indices and weight:\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u].push_back({v, w});
        // Uncomment next line for undirected graph:
        // graph[v].push_back({u, w});
    }
    int src, dest;
    std::cout << "Enter source and destination (0-based): ";
    std::cin >> src >> dest;
    std::vector<int> path = dijkstra(graph, src, dest);
    if (path.empty()) {
        std::cout << "No path found from " << src << " to " << dest << ".\n";
    } else {
        std::cout << "Shortest path: ";
        for (size_t i = 0; i < path.size(); ++i) {
            std::cout << path[i];
            if (i + 1 < path.size()) std::cout << " -> ";
        }
        std::cout << "\n";
    }
    return 0;
}