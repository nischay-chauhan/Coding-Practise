#include <iostream>
#include <vector>
using namespace std;

void generateAllBinaryStrings(string& pattern, int index, vector<string>& result) {
    if (index == pattern.length()) {
        result.push_back(pattern);
        return;
    }

    if (pattern[index] == '?') {
        // Replace with '0'
        pattern[index] = '0';
        generateAllBinaryStrings(pattern, index + 1, result);

        // Replace with '1'
        pattern[index] = '1';
        generateAllBinaryStrings(pattern, index + 1, result);

        // Backtrack to original '?'
        pattern[index] = '?';
    } else {
        generateAllBinaryStrings(pattern, index + 1, result);
    }
}

int main() {
    string pattern = "1?0?";
    vector<string> allStrings;

    generateAllBinaryStrings(pattern, 0, allStrings);

    cout << "All binary strings for pattern \"" << pattern << "\":" << endl;
    for (const string& s : allStrings) {
        cout << s << endl;
    }

    return 0;
}
