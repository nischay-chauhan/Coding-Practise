// Question: Implement a stack using an array. Include methods for push, pop, and checking if the stack is empty. 
// Additionally, implement a method to return the top element of the stack without removing it.

#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
    int* arr;  
    int top;   
    int capacity; 

public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;  
    }

    ~Stack() {
        delete[] arr; 
    }

    void push(int x) {
        if (top == capacity - 1) {
            std::cout << "Stack Overflow" << std::endl;
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top == -1) {
            std::cout << "Stack Underflow" << std::endl;
            return -1; 
        }
        return arr[top--];
    }

    int peek() {
        if (top == -1) {
            std::cout << "Stack is empty" << std::endl;
            return -1; 
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};