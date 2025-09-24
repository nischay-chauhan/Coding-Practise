#include <bits/stdc++.h>
using namespace std;

// Returns true if n is odd, false if even
bool isOdd(int n) { return n & 1; }

// Multiply and divide by 2 using bit shifts
int multiplyBy2(int n) { return n << 1; }
int divideBy2(int n) { return n >> 1; }

// Check if k-th bit (0-based from right) is set
bool isKthBitSet(int n, int k) { return n & (1 << k); }

// Set/Clear/Toggle k-th bit
int setKthBit(int n, int k) { return n | (1 << k); }
int clearKthBit(int n, int k) { return n & ~(1 << k); }
int toggleKthBit(int n, int k) { return n ^ (1 << k); }

string toBinary(int n) {
    return bitset<32>(static_cast<unsigned>(n)).to_string();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    // Input format: n k
    // Example: 13 2
    if (!(cin >> n >> k)) return 0;

    cout << "n = " << n << " (bin: " << toBinary(n) << ")\n";
    cout << "k = " << k << "\n";

    cout << "Even/Odd: " << (isOdd(n) ? "Odd" : "Even") << "\n";
    cout << "n << 1 (n*2) = " << multiplyBy2(n) << " (bin: " << toBinary(multiplyBy2(n)) << ")\n";
    cout << "n >> 1 (n/2) = " << divideBy2(n) << " (bin: " << toBinary(divideBy2(n)) << ")\n";

    cout << "k-th bit set? " << (isKthBitSet(n, k) ? "Yes" : "No") << "\n";

    int setN = setKthBit(n, k);
    cout << "Set k-th bit: " << setN << " (bin: " << toBinary(setN) << ")\n";

    int clearN = clearKthBit(n, k);
    cout << "Clear k-th bit: " << clearN << " (bin: " << toBinary(clearN) << ")\n";

    int toggleN = toggleKthBit(n, k);
    cout << "Toggle k-th bit: " << toggleN << " (bin: " << toBinary(toggleN) << ")\n";

    return 0;
}