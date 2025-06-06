#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> allLexicographicNextPermutations(string str) {
    vector<string> result;

    // Step 1: Sort the string
    sort(str.begin(), str.end());

    // Step 2: Keep generating next permutations
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
