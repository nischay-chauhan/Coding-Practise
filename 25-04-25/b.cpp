#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

vector<string> splitWords(const string &s) {
    vector<string> words;
    stringstream ss(s);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}

void topKFrequentWords(const vector<string>& strings, int k) {
    unordered_map<string, int> freq;

    for (const auto& s : strings) {
        vector<string> words = splitWords(s);
        for (const auto& word : words) {
            freq[word]++;
        }
    }

    auto comp = [](const pair<int, string>& a, const pair<int, string>& b) {
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    };

    priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> minHeap(comp);

    for (const auto& entry : freq) {
        minHeap.push({entry.second, entry.first});
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    vector<string> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    reverse(result.begin(), result.end());

    // Output the results
    for (const auto& word : result) {
        cout << word << endl;
    }
}

int main() {
    vector<string> input = {
        "hello world",
        "hello",
        "world hello",
        "hi there",
        "hi"
    };
    
    int k = 2;
    cout << "Top " << k << " frequent words:" << endl;
    topKFrequentWords(input, k);
    
    return 0;
}
