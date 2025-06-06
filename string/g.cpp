#include <iostream>
#include <unordered_map>
using namespace std;

/* 
 for (int right = 0; right < s.length(); ++right) {
        freq[s[right]]++;

        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) {
                freq.erase(s[left]);
            }
            left++;
        }

        if (freq.size() == k && right - left + 1 > maxLen) {
            maxLen = right - left + 1;
            start = left;
        }
    }

    if (maxLen == 0) return "";
    return s.substr(start, maxLen);
*/

/* Longest Substring with At Most K Distinct Characters */
string longestSubstringKDistinct(string s, int k) {
    int left = 0, maxLen = 0, start = 0;
    unordered_map<char, int> freq;

    for(int right = 0; right < s.length(); ++right){
        freq[s[right]]++;
        while(freq.size()  > k){
            freq[s[left]]--;
            if(freq[s[left]] == 0){
                freq.erase(s[left]);
            }
            left++;
        }
        if(freq.size() == k && right - left + 1 > maxLen){
            maxLen = right - left + 1;
            start = left;
        }
    }
    if(maxLen == 0) return "";
    return s.substr(start, maxLen);
}

int main() {
    string s = "eceba";
    int k = 2;

    string result = longestSubstringKDistinct(s, k);
    cout << "Longest substring with " << k << " distinct characters: " << result << endl;

    return 0;
}
