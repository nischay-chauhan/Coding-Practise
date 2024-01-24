/** Write a program to sort a string of characters */
#include <bits/stdc++.h>
using namespace std;


void sortString(string& str) {
    unordered_map<char, int> charCount;

    for (char ch : str) {
        charCount[ch]++;
    }

    vector<pair<char, int>> charFrequency(charCount.begin(), charCount.end());

    sort(charFrequency.begin(), charFrequency.end());

    for (const auto& entry : charFrequency) {
        for (int i = 0; i < entry.second; ++i) {
            cout << entry.first;
        }
    }
}

int main() {
    string s = "edddewcsdasbaaa";
    sortString(s);
    return 0;
}