/*
  An 2d gif like animated heart for those who like valentain!
  This code for valentain day!
  Creator : mortzaCFT
*/
#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>

void print_heart(int rotated_degrees)
 {

    std::string heart[] = 
    {
        "0001000000100000",
        "0011100001110000",
        "0111111011111000",
        "0111111111111000",
        "1111111111111100",
        "1111111111111100",
        "0111111111111000",
        "0111111111111000",
        "0011111111110000",
        "0001111111100000",
        "0000111111000000",
        "0000011110000000",
        "0000001100000000"
    };

    std::string rotated_heart[sizeof(heart) / sizeof(heart[0])];
    std::string rotated_row = "";
    
    for (int i = 0; i < sizeof(heart) / sizeof(heart[0]); i++) 
    {
        
        for (int j = 0; j < heart[i].length(); j++)
        {
            int rotated_col = (j + rotated_degrees) % heart[i].length();
            rotated_row += heart[i][rotated_col];
        }
        rotated_heart[i] = rotated_row;
    }

    for (int i = 0; i < sizeof(rotated_heart) / sizeof(rotated_heart[0]); i++)
    {
        for (int j = 0; j < rotated_heart[i].length(); j++)
         {
            if (rotated_heart[i][j] == '1') 
            {
                std::cout << "*";
            }
            else 
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

void rotate_heart() 
{
    int degrees = 0;
    while (true) 
    {
        print_heart(degrees);
        std::cout << "Valentain mobarak!" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(60));
        std::cout << system("cls");
        degrees += 1;
    }
}

int main() 
{
    rotate_heart();
    return 0;
}
