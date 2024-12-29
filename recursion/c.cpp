/* generate all teh subsequence and powerset */

#include <iostream>
#include <vector>
using namespace std;

void generateSubsequences(string input, string current, int index) {
    if (index == input.size()) {
        cout << current << endl;
        return;
    }

    generateSubsequences(input, current, index + 1);

    generateSubsequences(input, current + input[index], index + 1);
}

int main() {
    string input;
    cout << "Enter the string: ";
    cin >> input;

    cout << "All subsequences (powerset) of the string are:" << endl;
    generateSubsequences(input, "", 0);

    return 0;
}
