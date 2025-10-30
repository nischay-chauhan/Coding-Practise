#include "bits/stdc++.h"
using namespace std;

/* swap number with temp 

a = a ^ b;
b = a ^ b;
a = a ^ b;

*/

int main(){
    int a = 5, b = 10;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << a << " " << b << endl;
    return 0;
}