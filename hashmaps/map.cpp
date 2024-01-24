// Hashmaps COding problem practise to get used to use Hashmaps

/** 1 : You are given an array of integers. Your task is to find the frequency of each distinct element in the array and print them.*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of ELements : ";    
    cin >> n;
    unordered_map<int , int> freqMap;
    for(int i = 0;i<n;i++){
        int num;
        cout << "Enter the number " << i+1 << " : ";
        cin>>num;
        freqMap[num]++;
    }

    for(auto it : freqMap){
        cout<<it.first<<" : "<<it.second<<endl;
    }

    return 0;
}