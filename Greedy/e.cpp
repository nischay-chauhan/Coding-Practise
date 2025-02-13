/* N meetings in one room  */
/* Problem Statement: There is one meeting room in a firm. You are given two arrays, start and end each of size N.For an index ‘i’, start[i] denotes the starting time of the ith meeting while end[i]  will denote the ending time of the ith meeting. Find the maximum number of meetings that can be accommodated if only one meeting can happen in the room at a  particular time. Print the order in which these meetings will be performed. */

#include <bits/stdc++.h>
using namespace std;

struct Meeting {
    int start;
    int end;
    int pos;
};

bool comparator(Meeting m1, Meeting m2) {
    if (m1.end < m2.end) return true;
    else if (m1.end > m2.end) return false;
    else if (m1.pos < m2.pos) return true;
    return false;
}

void findMaxMeetings(int start[], int end[], int n) {
    struct Meeting meet[n];
    for(int i = 0; i < n; i++) {
        meet[i].start = start[i];
        meet[i].end = end[i];
        meet[i].pos = i + 1;
    }
    
    sort(meet, meet + n, comparator);
    
    vector<int> answer;
    answer.push_back(meet[0].pos);
    int limit = meet[0].end;
    
    for(int i = 1; i < n; i++) {
        if(meet[i].start > limit) {
            limit = meet[i].end;
            answer.push_back(meet[i].pos);
        }
    }
    
    cout << "Maximum meetings that can be held: " << answer.size() << endl;
    cout << "Order of meetings: ";
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of meetings: ";
    cin >> n;
    
    int start[n], end[n];
    cout << "Enter start times: ";
    for(int i = 0; i < n; i++) {
        cin >> start[i];
    }
    
    cout << "Enter end times: ";
    for(int i = 0; i < n; i++) {
        cin >> end[i];
    }
    
    findMaxMeetings(start, end, n);
    return 0;
}
