/* Walking using Tabulation */
#include <bits/stdc++.h>
using namespace std;

void reachHome(int src, int dest) {
    vector<bool> dp(dest + 1, false); 
    while (src < dest) {
        cout << "Source: " << src << " Destination: " << dest << endl;
        src++;
        dp[src] = true; 
    }

    if (src == dest) {
        cout << "Source: " << src << " Destination: " << dest << endl;
        cout << "Reached Home" << endl;
    }
}

int main() {
    int dest = 10;
    int src = 1;

    reachHome(src, dest);
}
