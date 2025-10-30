#include <bits/stdc++.h>
using namespace std;


void  sortedStack(stack<int> &s){
    stack<int> temp;

    while(!s.empty()){
        int curr = s.top(); s.pop();
        while(!temp.empty() && temp.top() > curr){
            s.push(temp.top()); temp.pop();
        }
        temp.push(curr);
    }
    swap(s , temp);
}

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    sortedStack(s);
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}