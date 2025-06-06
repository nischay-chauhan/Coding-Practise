#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void backtrack(string& half, int l, int r, set<string>& result) {
    if (l == r) {
        result.insert(half);
        return;
    }
    for (int i = l; i <= r; ++i) {
        if (i != l && half[i] == half[l]) continue;  
        swap(half[i], half[l]);
        backtrack(half, l + 1, r, result);
        swap(half[i], half[l]); 
    }
}

vector<string> generatePalindromicPermutations(string s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;

    int oddCount = 0;
    char midChar = 0;
    string half = "";

    for (auto& entry : freq) {
        if (entry.second % 2 == 1) {
            oddCount++;
            midChar = entry.first;
        }
        half += string(entry.second / 2, entry.first);
    }

    if (oddCount > 1) return {};  

    sort(half.begin(), half.end());  
    set<string> halfPerms;
    backtrack(half, 0, half.size() - 1, halfPerms);

    vector<string> palindromes;
    for (const string& h : halfPerms) {
        string rev = h;
        reverse(rev.begin(), rev.end());
        palindromes.push_back(h + (oddCount == 1 ? string(1, midChar) : "") + rev);
    }

    return palindromes;
}

int main() {
    string input = "aabb";
    vector<string> results = generatePalindromicPermutations(input);

    cout << "Palindromic permutations of \"" << input << "\":" << endl;
    for (string& p : results) {
        cout << p << endl;
    }

    return 0;
}
