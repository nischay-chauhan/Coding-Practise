/* Maximize maximum adjacent difference in a path from top left to bottom right */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int minimizeMaxDifference(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0, {0, 0}}); 

    vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));
    distance[0][0] = 0;

    while (!pq.empty()) {
        auto [maxDiff, cell] = pq.top();
        pq.pop();
        int x = cell.first;
        int y = cell.second;

        if (x == rows - 1 && y == cols - 1) {
            return maxDiff;
        }
        for (const auto& [dx, dy] : directions) {
            int newX = x + dx;
            int newY = y + dy;

            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                int currentDiff = abs(matrix[newX][newY] - matrix[x][y]);
                int newMaxDiff = max(maxDiff, currentDiff);
                
                if (newMaxDiff < distance[newX][newY]) {
                    distance[newX][newY] = newMaxDiff;
                    pq.push({newMaxDiff, {newX, newY}});
                }
            }
        }
    }

    return -1; 
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 2},
        {4, 7, 5},
        {6, 8, 9}
    };

    int result = minimizeMaxDifference(matrix);
    cout << "The minimum maximum adjacent difference in a path is: " << result << endl;

    return 0;
}
