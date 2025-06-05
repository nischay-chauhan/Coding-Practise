/* To check whether a given string is a rotated palindrome, you need to determine if any rotation of the string is a palindrome.
 */

 /* If you concatenate the string to itself (i.e., s + s), all possible rotations of the original string become substrings of that doubled string.
Then just check all substrings of length n in this s + s, and see if any of them is a palindrome. */

#include <iostream>
using namespace std;

bool isPalindrome(const string& str, int start, int end) {
    while (start < end) {
        if (str[start++] != str[end--])
            return false;
    }
    return true;
}

bool isRotatedPalindrome(string s) {
    int n = s.length();
    string double_s = s + s;

    // Check all substrings of length n
    for (int i = 0; i < n; ++i) {
        if (isPalindrome(double_s, i, i + n - 1)) {
            return true;
        }
    }
    return false;
}

int main() {
    string s1 = "aab";
    cout << "Is '" << s1 << "' a rotated palindrome? "
         << (isRotatedPalindrome(s1) ? "Yes" : "No") << endl;

    string s2 = "abc";
    cout << "Is '" << s2 << "' a rotated palindrome? "
         << (isRotatedPalindrome(s2) ? "Yes" : "No") << endl;

    return 0;
}
