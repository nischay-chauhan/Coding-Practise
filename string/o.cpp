#include <iostream>
#include <string>
using namespace std;

string replacePattern(string s, const string& pattern, const string& replacement) {
    size_t pos = 0;
    while ((pos = s.find(pattern, pos)) != string::npos) {
        s.replace(pos, pattern.length(), replacement);
        pos += replacement.length(); // move ahead to avoid overlapping
    }
    return s;
}

int main() {
    string s = "ababab";
    string pattern = "ab";
    string replacement = "x";

    string result = replacePattern(s, pattern, replacement);
    cout << "Result: " << result << endl; // Output: xxx

    return 0;
}
