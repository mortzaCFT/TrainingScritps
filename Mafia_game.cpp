  /*
  Simple Mafia Game.
  This script can help you to underestanding better "Monte Carlo" Algoritm.
  Also i used vector and structurs.
  I hope you will earn a simple thing from here.
  With love.
  Copyright: free for anychanges.
  */
#include <iostream>
#include <string>
#include <ctime>
#include <random>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

std::vector<std::string> players_name;
std::vector<std::string> players_roles;

void PlayersRols() {
    std::vector<std::string> available_roles = { "Mafia Boss", "Detective", "Guard", "Simple citizen", "Shilder" };

    // Shuffle the available roles
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(available_roles.begin(), available_roles.end(), rng);

    // Assign roles to players
    for (int i = 0; i < 10; i++) {
        players_roles.push_back(available_roles[i]);
    }

    for (int i = 0; i < 10; i++) {
        cout << "Player " << i + 1 << " role is: " << players_roles[i] << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int main() {
    srand(time(0));

    cout << "Welcome to Mafia 2000!" << endl;
    cout << "Please enter the players' names (just 10 players required):" << endl;

    std::string name;
    for (int i = 0; i < 10; i++) {
        cout << "Enter player " << i + 1 << ": ";
        cin >> name;
        players_name.push_back(name);
    }

    PlayersRols();
    return 0;
}
