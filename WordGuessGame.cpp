/*
Simple word guess game.
Good for learning vector and functionall programing.
Also if you about to learn how to create list of string,using vecotr,it's for you.
Created for everyone,By mortzaCFT
Copyright: free for anychanges.
*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

std::string chooseWord()
{
        //Using arry instead of that vector list.
        std::string words[] = { "logic", "matter", "hehe" };
        
        int numWords = 3;
        //You can use this for any size list.
        //int numWords = sizeof(words) / sizeof(words[0]);

        srand(time(0));

        int randomIndex = rand() % numWords;

        return words[randomIndex];

/*
* The old one.
* 
    std::vector<std::string> words{ "logic", "matter", "hehe" };
    std::srand(std::time(0));
    return words[std::rand() % words.size()];
*/
}

void run_game()
{
    std::string word = chooseWord();
    std::string username;

    std::cout << "What is your name? >> ";
    std::getline(std::cin, username);
    std::cout << "Welcome to game, " << username << std::endl;

    std::string guessed = "";
    int tries = 3;

    while (tries > 0)
    {
        int blanks = 0;
        std::cout << "Word: ";

        for (char c : word)
        {
            if (guessed.find(c) != std::string::npos)
            {
                std::cout << c;
            }
            else
            {
                std::cout << "_";
                blanks++;
            }
        }

        std::cout << std::endl;

        if (blanks == 0)
        {
            std::cout << "You got it!" << std::endl;
            break;
        }

        std::string guess;
        std::cout << "Enter a letter: ";
        std::getline(std::cin, guess);

        if (guessed.find(guess) != std::string::npos)
        {
            std::cout << "You already used: \"" << guess << "\". Please try with another letter!" << std::endl;
            continue;
        }

        guessed += guess;

        if (word.find(guess) == std::string::npos)
        {
            tries--;
            std::cout << "Sorry, that was wrong... (" << tries << " tries remaining)" << std::endl;

            if (tries == 0)
            {
                std::cout << "No more tries remaining... You lose." << std::endl;
                break;
            }
        }
    }
}

int main()
{
    run_game();
    return 0;
}
