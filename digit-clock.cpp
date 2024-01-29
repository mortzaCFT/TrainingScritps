/*
Simple digital clock using ctime.
No descriptions.
Enjoy.
*/


#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <Windows.h>
int main()
{
  while (true)
    {
      auto now = std::chrono::system_clock::now();
      std::time_t time = std::chrono::system_clock::to_time_t(now);
      std::tm local_time= *std::localtime(&time);

        system("cls");
         std::cout << "Current time is"  << ":";
         std::cout << local_time.tm_hour << ":";
         std::cout << local_time.tm_min  << ":";
         std::cout << local_time.tm_sec  << std::endl;

       std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
    return 0;
}
