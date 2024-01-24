#include <iostream>
#include <unordered_set>
#include <string>

void uniqueString(const std::string& s) {
    std::unordered_set<char> uniqueChars;

    for (char ch : s) {
        if (uniqueChars.find(ch) == uniqueChars.end()) {
            uniqueChars.insert(ch);
        }
    }

    for (char uniqueChar : uniqueChars) {
        std::cout << uniqueChar;
    }
}

int main() {
    std::string s;
    std::cout << "Enter a string: ";
    getline(std::cin, s);
    uniqueString(s);
    return 0;
}
