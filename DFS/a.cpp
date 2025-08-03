#include <bits/stdc++.h>
using namespace std;

void dfs(int room , vector<vector<int>>& rooms , vector<bool>& visited){
    visited[room] = true;
    for(int key : rooms[room]){
        if(!visited[key]){
            dfs(key , rooms , visited);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>>& rooms){
    int n = rooms.size();
    vector<bool> visited(n+1 , false);
    dfs(0 , rooms , visited);
    for(int i = 0 ; i < n ; i++){
        if(!visited[i]) return false;
    }
    return true;
}

int main(){
    vector<vector<int>> rooms = {{1}, {2}, {3}, {}};
    cout << canVisitAllRooms(rooms) << endl;
    return 0;
}