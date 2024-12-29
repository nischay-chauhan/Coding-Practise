#include <bits/stdc++.h>
using namespace std;

// Function to insert an element in sorted order into a stack
void insertSorted(stack<int> &s, int x) {
    if (s.empty() || s.top() >= x) {
        s.push(x);
        return;
    }

    int topElement = s.top();
    s.pop();
    insertSorted(s, x);
    s.push(topElement);
}

// Function to sort the stack
void sortedStack(stack<int> &s) {
    if (s.empty()) {
        return;
    }

    int topElement = s.top();
    s.pop();

    // Recursively sort the remaining stack
    sortedStack(s);

    // Insert the top element back in sorted order
    insertSorted(s, topElement);
}

// Helper function to print the stack
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;

    // Example stack
    s.push(30);
    s.push(-5);
    s.push(18);
    s.push(14);
    s.push(-3);

    cout << "Original Stack: ";
    printStack(s);

    // Sort the stack
    sortedStack(s);

    cout << "Sorted Stack: ";
    printStack(s);

    return 0;
}
