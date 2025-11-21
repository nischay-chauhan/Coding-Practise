#include <string>
#include <iostream>

std::string semi_reverse(std::string s)
{
    int i = 0, j = s.size() - 1;

    while (i < j) {
        if (!isalpha(s[i])) {
            i++;
        } else if (!isalpha(s[j])) {
            j--;
        } else {
            std::swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    return s;
}

int main(int argc, char *argv[])
{
 std::cout << semi_reverse("ab-cd") << '\n'
           << semi_reverse("a-bC-dEf=ghlj!!") << '\n';
}
