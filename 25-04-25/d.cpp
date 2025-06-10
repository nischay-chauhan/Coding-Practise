#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void findDuplicateRows(const vector<vector<int>>& matrix) {
    unordered_map<string, int> rowMap;
    int rowCount = matrix.size();
    int colCount = matrix[0].size();

    cout << "Duplicate rows (0-based index):" << endl;

    for (int i = 0; i < rowCount; ++i) {
        string rowKey;
        for (int j = 0; j < colCount; ++j) {
            rowKey += to_string(matrix[i][j]);
        }

        if (rowMap[rowKey]) {
            cout << "Row " << i << " is a duplicate of row " << rowMap[rowKey] - 1 << endl;
        } else {
            rowMap[rowKey] = i + 1;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 0}
    };

    findDuplicateRows(matrix);

    return 0;
}
