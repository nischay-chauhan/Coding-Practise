/* Problem Statement: Given two arrays representing children’s green factor and cookie sizes, the goal is to maximise the number of content children.
Each child i has a greed factor of g[i], which is the minimum size of a cookie that will make the child content. Each cookie j has a size of s[j]. If s[j] >= g[j], we can assign cookie j to child i, making the child content. Each child can only receive one cookie. */

#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& c) {
    int n = g.size();
    int m = c.size();
    sort(g.begin(), g.end());
    sort(c.begin(), c.end());
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < n && j < m) {
        if (g[i] <= c[j]) {
            count++;
            i++;
            j++;
        } else {
            j++;
        }
    }
    return count;
}

int main(){
    vector<int> g = {1 , 5 , 3 , 3 , 4};
    vector<int> c = {4 , 2 , 1 , 2 , 1 , 3};

    for(int i =0; i < g.size();i++){
        cout << g[i] << " ";
    }
    cout << endl;

    for(int i = 0 ; i < c.size() ; i++){
        cout << c[i] << " ";
    }
    cout << endl;

    int ans = findContentChildren(g , c);
    cout << ans << endl;
}