#include <iostream>
#include <vector>
using namespace std;

void generateBinary(int n, string current, int count1, int count0, vector<string> &result) {
    if (current.length() == n) {
        if (count1 > count0)
            result.push_back(current);
        return;
    }

    // Always allowed to place '1'
    generateBinary(n, current + '1', count1 + 1, count0, result);

    // Only place '0' if count1 > count0
    if (count1 > count0)
        generateBinary(n, current + '0', count1, count0 + 1, result);
}

vector<string> getValidBinaryStrings(int n) {
    vector<string> result;
    generateBinary(n, "", 0, 0, result);
    return result;
}

int main() {
    int n = 4;
    vector<string> result = getValidBinaryStrings(n);

    cout << "Binary strings of length " << n << " with every prefix having more 1’s than 0’s:\n";
    for (string s : result)
        cout << s << endl;

    return 0;
}
