#include <iostream>
#include <vector>
#include <memory>
#include <set>
#include <cctype>

using namespace std;

/* Is Valid for string based on different rules
A word is considered valid if:

It contains a minimum of 3 characters.
It contains only digits (0-9), and English letters (uppercase and lowercase).
It includes at least one vowel.
It includes at least one consonant.
You are given a string word.

Return true if word is valid, otherwise, return false.
*/

static const set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

class RuleInterface{
    public:
        virtual bool isValid(const string& word) const = 0;
        virtual ~RuleInterface() = default;
};

// r1
class MinimumLength : public RuleInterface{
    public:
    bool isValid(const string& word) const override{
        return word.length() >= 3;
    }
};

// r2
class CharacterRule : public RuleInterface{
    public:
        bool isValid(const string& word) const override{
            for(char c : word){
                if(!isalpha(c) && !isdigit(c)) return false;
            }
            return true;
        }
};

// r3 
class MinimumVowelRule : public RuleInterface{
    public:
        bool isValid(const string& word) const override{
            for(char c : word){
                if(vowels.count(c)) return true;
            }
            return false;
        }
};

// r4
class MinimumConsonantRule : public RuleInterface{
    public:
        bool isValid(const string& word) const override{
            for(char c : word){
                if(isdigit(c)) continue;
                if(!vowels.count(c)) return true;
             }
             return false;
        }
};

class Solution{
    public:
        bool isValid(const string& word) const{
            vector<shared_ptr<RuleInterface>> rules = {
                make_shared<MinimumLength>(),
                make_shared<CharacterRule>(),
                make_shared<MinimumVowelRule>(),
                make_shared<MinimumConsonantRule>()
            };
            for(const auto& rule : rules){
                if(!rule->isValid(word)) return false;
            }
            return true;
        }
};

int main() {
    Solution validator;
    
    // Test cases
    vector<string> test_strings = {
        "234Adas",  // Valid - meets all criteria
        "b3",       // Invalid - less than 3 characters
        "a1 /",     // Invalid - contains invalid character '/'
        "123",      // Invalid - no letters
        "a1e",      // Invalid - no consonants
        "abc123"   // Valid - meets all criteria
    };

    for (const auto& test : test_strings) {
        cout << '"' << test << '"' << " is " << (validator.isValid(test) ? "valid" : "invalid") << endl;
    }
    
    return 0;
}
