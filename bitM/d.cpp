#include <bits/stdc++.h>
using namespace std;

/*

Count set bits

Check power of two

Find XOR of numbers from 1 to n (pattern based)

*/

int countSetBits(int n){
    int count = 0;
    while(n){
        count += n & 1;
        n >>= 1;
    }
    return count;  
}

int countSetBitsUsingBuiltInFunction(int n){
    return __builtin_popcount(n);
}

int checkPowerOfTwo(int n){
    return (n && !(n & (n - 1)));
}

int findXOR(int n){
    if(n % 4 == 0) return n;
    if(n % 4 == 1) return 1;
    if(n % 4 == 2) return n + 1;
    if(n % 4 == 3) return 0;
}

/* 
Single number I (LC 136)

Single number II (LC 137)

Subsets generation

Find the rightmost set bit

Reverse bits

*/

int findRightMostSetBit(int n){
    return n & -n;
}

int reverseBits(int n){
    int count = 0;
    while(n){
        count += n & 1;
        n >>= 1;
    }
    return count;  
}

int subsetsGeneration(int n){
    for(int i = 0; i < (1 << n); i++){
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                cout << j << " ";
            }
        }
        cout << endl;
    }   
}

int main(){
    int n;
    cin >> n;
    cout << countSetBits(n) << endl;
    cout << countSetBitsUsingBuiltInFunction(n) << endl;
    cout << checkPowerOfTwo(n) << endl;
    cout << findXOR(n) << endl;
    return 0;
}