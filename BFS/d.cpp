#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>

using namespace std;

void BFS(const unordered_map<int, list<int>>& graph, int start, int target) {
    queue<int> q;
    unordered_map<int, int> distance;
    unordered_map<int, int> parent;
    
    for (const auto& node : graph) {
        distance[node.first] = -1;
    }
    
    q.push(start);
    distance[start] = 0;
    parent[start] = -1;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        for (int neighbor : graph.at(current)) {
            if (distance[neighbor] == -1) {  // Not visited
                q.push(neighbor);
                distance[neighbor] = distance[current] + 1;
                parent[neighbor] = current;
                
                if (neighbor == target) {
                    cout << "Shortest path length is: " << distance[target] << endl;
                    cout << "Path: ";
                    int temp = target;
                    while (temp != -1) {
                        cout << temp << " ";
                        temp = parent[temp];
                    }
                    cout << endl;
                    return;
                }
            }
        }
    }
    
    cout << "Target node not reachable from start node." << endl;
}

int main() {
    unordered_map<int, list<int>> graph;
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 5, 6};
    graph[3] = {1};
    graph[4] = {1};
    graph[5] = {2};
    graph[6] = {2};
    
    int start = 0;
    int target = 6;
    
    BFS(graph, start, target);
    
    return 0;
}
