//Simple app convert string type to ascii characters.
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "enter your name: ";
    std::cin >> name;

    std::cout << '\n'; 
    for (char c : name) {
        std::cout << static_cast<int>(c) << " ";
    }
    return 0;
}
