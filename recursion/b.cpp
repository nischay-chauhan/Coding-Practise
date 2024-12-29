/* Generate binary string to print all binary strings of length n */

#include <iostream>
#include <vector>
using namespace std;

void generateBinaryStrings(int n, string currentString) {
    if (currentString.length() == n) {
        cout << currentString << endl;
        return;
    }

    generateBinaryStrings(n, currentString + "0");

    generateBinaryStrings(n, currentString + "1");
}

int main() {
    int n;
    cout << "Enter the length of binary strings: ";
    cin >> n;

    cout << "All binary strings of length " << n << " are:" << endl;
    generateBinaryStrings(n, "");

    return 0;
}
