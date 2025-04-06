/* 2. New Number System
Each character ‘a’ to ‘t’ represents numbers 1–20 respectively. Convert the given string (interpreted as a base‑20 number) into its decimal value. */
#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    cin >> s;
    long long ans = 0;
    for(char c: s){
        ans = ans * 20 + (c - 'a' + 1);
    }
    cout << ans;
    return 0;
}