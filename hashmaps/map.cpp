#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> val;
    unordered_map<int, int> freqMap;

    for (int i = 0; i < n; i++) {
        int num;
        cout << "Enter the number " << i + 1 << ": ";
        cin >> num;
        freqMap[num]++;
        val.push_back(num);
    }

    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end()); 
    for (auto it : val) {
        cout << it << " : " << freqMap[it] << endl;
    }

    return 0;
}
