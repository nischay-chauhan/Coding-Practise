#include <iostream>
#include <vector>
using namespace std;

void findInterleavings(string A, string B, string result, int i, int j, vector<string>& output) {
    // Base case: if both strings are completely used
    if (i == A.size() && j == B.size()) {
        output.push_back(result);
        return;
    }

    // If characters left in A, take one and recurse
    if (i < A.size()) {
        findInterleavings(A, B, result + A[i], i + 1, j, output);
    }

    // If characters left in B, take one and recurse
    if (j < B.size()) {
        findInterleavings(A, B, result + B[j], i, j + 1, output);
    }
}

int main() {
    string A = "ab";
    string B = "cd";
    vector<string> interleavings;

    findInterleavings(A, B, "", 0, 0, interleavings);

    cout << "All interleavings of \"" << A << "\" and \"" << B << "\":" << endl;
    for (const string& s : interleavings) {
        cout << s << endl;
    }

    return 0;
}
