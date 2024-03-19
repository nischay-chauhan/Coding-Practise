/* Find four elements a, b, c and d in an array such that a+b = c+d*/
#include<bits/stdc++.h>
using namespace std;

vector<pair<int , int>> findPair(vector<int> & arr){
    unordered_map<int , pair<int , int>> sumPairs;
    int n = arr.size();
    vector<pair<int , int>> result;

    for(int i = 0; i<n;i++){
        for(int j = 0;j<n;j++){
            int sum = arr[i] + arr[j];
            if(sumPairs.find(sum) == sumPairs.end()){
                sumPairs[sum] = {i , j};
            }else{
                auto pair1 = sumPairs[sum];
                result.push_back({arr[pair1.first] , arr[pair1.second]});
                result.push_back({arr[i] , arr[j]});
                return result;

            }
        }
    }
    return result;
}

int main(){
    vector <int> arr = {3 , 4 , 7 , 1 , 2 , 9 , 8};
    vector <pair<int , int>> pairs = findPair(arr);

    for(auto pair : pairs){
        cout << "(" << pair.first << " , " << pair.second << ")" << endl;
    }
}