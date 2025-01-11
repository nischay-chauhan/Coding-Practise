/* Subarray sum equals k
Find the number of subarrays in the array whose sum equals a given integer k.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subarraySum(vector<int>& nums , int k ){
    unordered_map<int , int> prefixsumFreq;
    prefixsumFreq[0] = 1;
    int count = 0;
    int prefixSum = 0;

    for(int num : nums){
        prefixSum += num;
        if(prefixsumFreq.find(prefixSum - k) != prefixsumFreq.end()){
            count += prefixsumFreq[prefixSum - k];
        }
        prefixsumFreq[prefixSum]++;
    }
    return count;
}

int main(){
    vector<int> nums = {1 , 1 , 1};
    int k = 2;
    cout << "Number ofo Subarrays with sum equal to " << k << " is: " << subarraySum(nums , k);
}
