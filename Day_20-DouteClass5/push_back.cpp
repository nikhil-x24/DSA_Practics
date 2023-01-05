#include <cassert>
#include <string>
#include <iomanip>
#include <iostream>
 
int main()
{
    std::string str{"Short string"};
    std::cout << "before=" << std::quoted(str) << '\n';
    assert(str.size() == 12);
 
    str.push_back('!');
    std::cout << " after=" << quoted(str) << '\n';
    assert(str.size() == 13);
}