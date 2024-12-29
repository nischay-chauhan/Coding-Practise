#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive function to find all combinations
void findCombinations(vector<int> &candidates, int target, int index, vector<int> &current, vector<vector<int>> &result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }

    for (int i = index; i < candidates.size(); i++) {
        if (candidates[i] > target) break;
        current.push_back(candidates[i]);

        
        findCombinations(candidates, target - candidates[i], i, current, result);

        current.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
   
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> result;
    vector<int> current;

    findCombinations(candidates, target, 0, current, result);

    return result;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    cout << "Combinations that sum to " << target << " are:" << endl;

    vector<vector<int>> result = combinationSum(candidates, target);

    // Print the result
    for (const auto &combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
