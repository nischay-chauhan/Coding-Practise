#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> allLexicographicNextPermutations(string str) {
    vector<string> result;
    sort(str.begin(), str.end());

    do {
        result.push_back(str);
    } while (next_permutation(str.begin(), str.end()));

    return result;
}

int main() {
    string str = "abc";
    vector<string> permutations = allLexicographicNextPermutations(str);

    cout << "All lexicographically sorted permutations of \"" << str << "\":" << endl;
    for (const string& s : permutations) {
        cout << s << endl;
    }

    return 0;
}
