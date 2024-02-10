/* Walking  */
#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

void reachHome(int src, int dest) {
    if (src == dest) {
        cout << "Reached Home" << endl;
        return;
    }

    if (dp[src] != -1) {
        return; 
    }

    dp[src] = 1; 
    cout << "Source: " << src << " Destination: " << dest << endl;

    reachHome(src + 1, dest);
}

int main() {
    int dest = 10;
    int src = 1;
    
    dp.resize(dest + 1, -1); 
    reachHome(src, dest);
}
