#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> digitToChar = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        vector<string> result;
        string currentCombination;
        backtrack(digits, digitToChar, 0, currentCombination, result);
        return result;
    }

private:
    void backtrack(const string& digits, const vector<string>& digitToChar, 
                   int index, string& currentCombination, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(currentCombination);
            return;
        }
        
        string letters = digitToChar[digits[index] - '0'];
        
        for (char letter : letters) {
            currentCombination.push_back(letter);
            backtrack(digits, digitToChar, index + 1, currentCombination, result);
            currentCombination.pop_back(); // Backtrack
        }
    }
};

int main() {
    Solution solution;
    string digits;
    cout << "Enter digits (2-9): ";
    cin >> digits;
    vector<string> combinations = solution.letterCombinations(digits);
    
    cout << "Letter combinations are:\n";
    for (const string& combination : combinations) {
        cout << combination << "\n";
    }
    return 0;
}
