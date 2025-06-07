#include <iostream>
#include <vector>
using namespace std;

void findNumbers(int n, int sum, string current, vector<string>& result) {
    if (n == 0) {
        if (sum == 0)
            result.push_back(current);
        return;
    }

    int start = current.empty() ? 1 : 0; // First digit must not be 0

    for (int digit = start; digit <= 9; ++digit) {
        if (digit <= sum) {
            findNumbers(n - 1, sum - digit, current + to_string(digit), result);
        }
    }
}

vector<string> getNDigitNumbersWithSum(int n, int sum) {
    vector<string> result;
    findNumbers(n, sum, "", result);
    return result;
}

int main() {
    int n = 3, sum = 6;
    vector<string> numbers = getNDigitNumbersWithSum(n, sum);

    cout << "All " << n << "-digit numbers with sum " << sum << ":\n";
    for (string num : numbers)
        cout << num << endl;

    return 0;
}
