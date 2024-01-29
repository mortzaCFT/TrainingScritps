/*
This can revers a multi word.
No description.
Enjoy.
*/

#include <iostream>
#include <Windows.h>
#include <string>

std::string reverse(std::string str)
{
   std::string reversed(str.rbegin(), str.rend());
   return reversed;
}

int main()
{
  std::string str;
  system("cls");
 
  while (true)
  { 
    std::cout << "Enter something:"  << std::endl;
    std::cin >> str;
    std::cout << reverse(str) << std::endl;
  }
    return 0;
}
