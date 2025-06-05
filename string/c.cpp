#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string numberToExcelColumn(int n) {
    string result = "";
    
    while (n > 0) {
        n--;  // Adjust for 1-based indexing
        char ch = 'A' + (n % 26);
        result += ch;
        n /= 26;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int num1 = 1;
    cout << num1 << " → " << numberToExcelColumn(num1) << endl;

    int num2 = 28;
    cout << num2 << " → " << numberToExcelColumn(num2) << endl;

    int num3 = 701;
    cout << num3 << " → " << numberToExcelColumn(num3) << endl;

    int num4 = 702;
    cout << num4 << " → " << numberToExcelColumn(num4) << endl;

    int num5 = 703;
    cout << num5 << " → " << numberToExcelColumn(num5) << endl;

    return 0;
}
