/* Majority ELement  */
#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {

    int n = nums.size();
    int count = 1;
    int major = nums[0];
    for(int i = 1; i < n; i++){
        if(nums[i] == major) count++;
        else count--;
        if(count == 0){
            major = nums[i];
            count = 1;
        }
    }
    return major;
}

int main(){
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(nums) << endl;
    return 0;
}