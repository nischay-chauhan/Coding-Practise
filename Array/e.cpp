#include <iostream>

struct __console                                        
{
    void log(const auto& ...args)
    {
        (std::clog << ... << args) << std::endl;
    }
}
console;

int main()                                              
{
    console.log("i am ", 69, " years old");
}

/* 
compile with  g++ e.cpp -std=c++20 -o d
 and run with ./d 
 */