#include <bits/stdc++.h>
using namespace std;

int findCheapestFlight(int n, vector<vector<int>>& flights, int src, int dest, int k) {
    vector<vector<pair<int, int>>> adj(n);
    for (const auto& flight : flights) {
        adj[flight[0]].push_back({flight[1], flight[2]});
    }
    
    // Min-heap: {cost, current_node, stops_used}
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    // {node, stops} -> min cost to reach
    vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
    
    // Start from source with 0 cost and 0 stops
    pq.push({0, src, 0});
    dist[src][0] = 0;
    
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        int cost = curr[0];
        int node = curr[1];
        int stops = curr[2];
        
        if (node == dest) return cost;
        
        if (stops > k) continue;
        
        for (const auto& [neighbor, price] : adj[node]) {
            int newCost = cost + price;
            int newStops = stops + 1;
            
            // If we found a cheaper path with <= k stops
            if (newCost < dist[neighbor][newStops] && newStops <= k + 1) {
                dist[neighbor][newStops] = newCost;
                pq.push({newCost, neighbor, newStops});
            }
        }
    }
    
    return -1;
}

int main() {
    int n = 4;
    vector<vector<int>> flights = {{0,1,200}, {1,2,100}, {1,3,300}, {2,3,100}};
    int src = 0, dest = 3, k = 1;
    
    int result = findCheapestFlight(n, flights, src, dest, k);
    cout << "Cheapest price from " << src << " to " << dest 
         << " with at most " << k << " stops: " << result << endl;
    
    return 0;
}