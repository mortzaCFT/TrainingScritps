/*
Dice simulator can simulator throwing dice :D
Really simple but Good for get started with vector or simple cpp libs. 
I know I can write this code more simply,But,who care...
Created for everyone,By mortzaCFT
Copyright: free for anychanges.
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<int> roll_dice(int amount)
{
    if (amount <= 0)
    {
        throw std::invalid_argument("Invalid amount");
    }

    std::vector<int> rolls;
    srand(time(0));
    for (int i = 0; i < amount; i++)
    {
        int random_roll = rand() % 6 + 1;
        rolls.push_back(random_roll);
    }

    return rolls;
}

int main()
{
    while (true)
    {
        try
        {
            std::string user_input;
            std::cout << "How many dice would you like to roll? ";
            std::cin >> user_input;

            if (user_input == "exit")
            {
                std::cout << "Thanks for using it." << std::endl;
                break;
            }

            std::cout << roll_dice(std::stoi(user_input)) << std::endl;
        }
        catch (std::invalid_argument const &e)
        {
            std::cout << "Please enter a valid number." << std::endl;
        }
    }

    return 0;
}
