/* Word Break Problem | Using Trie Data Structure*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TrieNode {
    bool isEnd;
    TrieNode* children[26];

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    
    void search(const string& s, int pos, vector<bool>& dp) {
        TrieNode* node = root;
        for (int i = pos; i < s.length(); ++i) {
            int idx = s[i] - 'a';
            if (!node->children[idx]) return;
            node = node->children[idx];
            if (node->isEnd)
                dp[i + 1] = true;
        }
    }
};

bool wordBreak(const string& s, const vector<string>& dict) {
    Trie trie;

    for (const auto& word : dict)
        trie.insert(word);

    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true; // Empty string can be segmented

    for (int i = 0; i < n; ++i) {
        if (dp[i])
            trie.search(s, i, dp);
    }

    return dp[n];
}

// Driver code
int main() {
    vector<string> dictionary = {"leet", "code", "love", "you"};
    string s = "code";

    if (wordBreak(s, dictionary))
        cout << "Can be segmented\n";
    else
        cout << "Cannot be segmented\n";

    return 0;
}
