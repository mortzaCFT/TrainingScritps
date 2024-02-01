/*
Simple Rock,paper,scissors game.
Created for learning classes,vector lib and random lib.
Created for everyone,By mortzaCFT,
Copyright: free for anychanges.
*/
#include <iostream>
#include <map>
#include <vector>
#include <random>

class RPS {
private:
    std::map<std::string, std::string> moves;
    std::vector<std::string> valid_moves;
    int score;

public:
    RPS() {
        std::cout << "Welcome to RPS 9000!" << std::endl;

        moves = {{"rock", " 🪨"}, {"paper", "📃"}, {"scissors", "✂️"}};
        valid_moves = {"rock", "paper", "scissors"};
        score = 0;
    }

    void play_game() {
        std::string user_move;
        std::cout << "Rock, paper, or scissors? >> ";
        std::cin >> user_move;
        std::transform(user_move.begin(), user_move.end(), user_move.begin(), ::tolower);

        if (user_move == "exit") {
            std::cout << "Thanks for playing!" << std::endl;
            exit(0);
        }

        if (std::find(valid_moves.begin(), valid_moves.end(), user_move) == valid_moves.end()) {
            std::cout << "Invalid move..." << std::endl;
            play_game();
            return;
        }

        std::random_device rd;
        std::mt19937 eng(rd());
        std::uniform_int_distribution<> distr(0, valid_moves.size() - 1);
        std::string ai_move = valid_moves[distr(eng)];

        display_moves(user_move, ai_move);
        check_move(user_move, ai_move);
    }

    void display_moves(const std::string& user_move, const std::string& ai_move) {
        std::cout << "--__--" << std::endl;
        std::cout << "You: " << moves[user_move] << std::endl;
        std::cout << "Ai: " << moves[ai_move] << std::endl;
        std::cout << "__--__" << std::endl;
    }

    void check_move(const std::string& user_move, const std::string& ai_move) {
        if (user_move == ai_move) {
            std::cout << "It's a tie!" << std::endl;
        } else if ((user_move == "rock" && ai_move == "scissors") || (user_move == "scissors" && ai_move == "paper") || (user_move == "paper" && ai_move == "rock")) {
            std::cout << "You win!" << std::endl;
            score += 1;
            std::cout << "Your score: " << score << std::endl;
        } else {
            std::cout << "Ai wins..." << std::endl;
        }
    }
};

int main() {
    RPS rps;
    while (true) {
        rps.play_game();
    }

    return 0;
}
