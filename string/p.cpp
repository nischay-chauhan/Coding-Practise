/* Given 2 strings , the SCS is the shortest string that has both x and y as its subsequence */

#include <bits/stdc++.h>
using namespace std;

int main() {
    string x = "AGGTAB";
    string y = "GXTXAYB";
    int m = x.length();
    int n = y.length();
    int t[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else if (x[i - 1] == y[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }
    cout << "SCS: " << m + n - t[m][n]  << endl;
    return 0;
}