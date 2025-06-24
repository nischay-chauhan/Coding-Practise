#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool isNiceString(const string& s) {
    int n = s.size();
    bool hasPair = false, hasRepeat = false;

    // Rule 1: Pair repeats without overlapping
    unordered_map<string, int> seenPairs;
    for (int i = 0; i < n - 1; ++i) {
        string pair = s.substr(i, 2);
        if (seenPairs.count(pair)) {
            // Must not overlap: previous index should be at least i-1
            if (i - seenPairs[pair] >= 2) {
                hasPair = true;
            }
        } else {
            seenPairs[pair] = i;
        }

        // Always update to latest index to prevent false positives
        if (!hasPair) seenPairs[pair] = i;
    }

    // Rule 2: One letter repeats with one letter between
    for (int i = 0; i < n - 2; ++i) {
        if (s[i] == s[i + 2]) {
            hasRepeat = true;
            break;
        }
    }

    return hasPair && hasRepeat;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    if (isNiceString(s)) {
        cout << "The string is nice!" << endl;
    } else {
        cout << "The string is not nice." << endl;
    }

    return 0;
}
