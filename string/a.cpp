#include <iostream>
#include <unordered_set>

void findMissingChars(const std::string &s)
{
    std::unordered_set<char> uniqueChars;
    for (char ch : s)
    {
        if (isalpha(ch))
        {
            uniqueChars.insert(tolower(ch));
        }
    }
    std::cout << "Missing characters to make it a pangram: ";
    for (char ch = 'a'; ch <= 'z'; ++ch)
    {
        if (uniqueChars.count(ch) == 0)
        {
            std::cout << ch;
        }
    }

    std::cout << std::endl;
}

int main()
{
    std::string inputString;
    std::cout << "Enter a string: ";
    getline(std::cin, inputString);

    findMissingChars(inputString);

    return 0;
}
