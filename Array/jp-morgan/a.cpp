/* For a given string, if all characters are the same then no rearrangement can change any position (answer 0). Otherwise, if there are exactly 2 distinct characters and the length is odd then the best you can do is leave one character “fixed” (answer = n–1). In all other cases you can achieve a full derangement (answer = n). */

#include<iostream>
#include<string>
#include<set>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();

        set<char> distinct(s.begin() , s.end());
        
        if(distinct.size() == 1){
            cout << 0 << "\n";
        }else if (distinct.size() == 2 && (n & 1)){
            cout << n-1 << "\n";
        }else{
            cout << n << "\n";;
        }
    }

    return 0;
}