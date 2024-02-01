/*
Strong Password generatro.
Created for everyone,By mortzaCFT
Copyright: free for anychanges.
*/

#include <iostream>
#include <string>
#include <cctype>
#include <random>

bool contains_upper(const std::string& password)
{
    for (char c : password)
    {
        if (std::isupper(c))
        {
            return true;
        }
    }
    return false;
}

bool contains_symbols(const std::string& password)
{
    for (char c : password)
    {
        if (ispunct(c))
        {
            return true;
        }
    }
    return false;
}

std::string generate_password(int length, bool symbols, bool uppercase)
{
    std::string combination = "abcdefghijklmnopqrstuvwxyz0123456789";
  
    if (symbols)
    {
        combination += "!@#$%^&*()_-+=<>?/{}[]";
    }
  
    if (uppercase)
    {
        combination += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
  
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, combination.length() - 1);
  
    std::string new_password;
  
    for (int i = 0; i < length; ++i)
    {
        new_password += combination[dis(gen)];
    }
  
    return new_password;
}

int main()
{
    for (int i = 1; i <= 5; ++i)
    {
        std::string new_pass = generate_password(15, true, true);
        std::string specs = "U: " + std::to_string(contains_upper(new_pass)) + ", S: " + std::to_string(contains_symbols(new_pass));
      
        std::cout << i << " -> " << new_pass << " (" << specs << ")\n";
    }
  
    return 0;
}
