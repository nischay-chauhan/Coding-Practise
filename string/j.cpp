#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generatePermutations(string& str, vector<bool>& visited, string& current, vector<string>& result) {
    if (current.length() == str.length()) {
        result.push_back(current);
        return;
    }

    for (int i = 0; i < str.length(); ++i) {
        if (visited[i])
            continue;

        if (i > 0 && str[i] == str[i - 1] && !visited[i - 1])
            continue;

        visited[i] = true;
        current.push_back(str[i]);

        generatePermutations(str, visited, current, result);

        current.pop_back();
        visited[i] = false;
    }
}

vector<string> getLexicographicPermutations(string str) {
    sort(str.begin(), str.end());  
    vector<bool> visited(str.length(), false);
    vector<string> result;
    string current;

    generatePermutations(str, visited, current, result);
    return result;
}

int main() {
    string str = "abc";
    vector<string> permutations = getLexicographicPermutations(str);

    cout << "Lexicographically sorted permutations:\n";
    for (const string& perm : permutations) {
        cout << perm << endl;
    }

    return 0;
}
