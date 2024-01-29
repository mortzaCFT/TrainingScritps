/*
Speaking of witch,when i used cpp for my security team(what a fucking team was...),
My mission was creating viruses.it was simple and enjoyble task,but i was looking for more funny things.
So i replace all my text commends using this printSlowy function.
I like when it's showing,are you also into this?
*/
#include <iostream>
//omg,i forgot to tell you, i use asynch libs like this...
#include <chrono>
#include <thread>
#include <string>



//function that can get text and rythm and print it slowly
void printSlowly(const std::string& sentence, int delayMilliseconds) {
    for (char c : sentence) {
        std::cout << c;
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMilliseconds));
    }
}

int main() {
	//Performing The Printing text 
	int delayMilliseconds = 125; 
    std::string inputSentence = "Information Gathering is now lunching ...";
	printSlowly(inputSentence, delayMilliseconds);
	std::cout << "\n";
    return 0;
}
