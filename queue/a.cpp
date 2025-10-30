#include <bits/stdc++.h>
using namespace std;


class Queue{
    int *arr;
    int front , rear , capacity , count;

    public:
    Queue(int size){
        arr = new int[size];
        front = 0;
        rear = -1;
        capacity = size;
        count = 0;
    }

    void enqueue(int val){
        if(count == capacity){
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        count++;
    }

    void dequeue(){
        if(count == 0){
            cout << "Queue is empty" << endl;
            return;
        }
        front = (front + 1) % capacity;
        count--;
    }

    int peek(){
        if(count == 0) return -1;
        return arr[front];
    }

    bool isEmpty(){
        return count == 0;
    }

    bool isFull(){
        return count == capacity;
    }
};