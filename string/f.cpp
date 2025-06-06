#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>
using namespace std;

bool isIPv4(string IP) {
    stringstream ss(IP);
    string token;
    int count = 0;

    while (getline(ss, token, '.')) {
        count++;
        if (token.empty() || token.size() > 3)
            return false;
        if (token.size() > 1 && token[0] == '0')  // No leading 0s
            return false;
        for (char ch : token)
            if (!isdigit(ch))
                return false;

        int num = stoi(token);
        if (num < 0 || num > 255)
            return false;
    }

    return count == 4;
}

bool isIPv6(string IP) {
    stringstream ss(IP);
    string token;
    int count = 0;

    while (getline(ss, token, ':')) {
        count++;
        if (token.empty() || token.size() > 4)
            return false;
        for (char ch : token) {
            if (!isxdigit(ch))  // check hexadecimal
                return false;
        }
    }

    return count == 8;
}

string validIPAddress(string IP) {
    if (IP.find('.') != string::npos) {
        return isIPv4(IP) ? "IPv4" : "Neither";
    } else if (IP.find(':') != string::npos) {
        return isIPv6(IP) ? "IPv6" : "Neither";
    }
    return "Neither";
}

int main() {
    vector<string> inputs = {
        "172.16.254.1",
        "256.256.256.256",
        "2001:0db8:85a3:0:0:8A2E:0370:7334",
        "02001:0db8:85a3:0000:0000:8a2e:0370:7334"
    };

    for (string& ip : inputs) {
        cout << ip << " → " << validIPAddress(ip) << endl;
    }

    return 0;
}
