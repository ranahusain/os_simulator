#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string getComputerChoice() {
    int choice = rand() % 3;
    if (choice == 0) return "rock";
    else if (choice == 1) return "paper";
    else return "scissors";
}

string getResult(string user, string computer) {
    if (user == computer) return "It's a draw!";
    else if ((user == "rock" && computer == "scissors") ||
             (user == "paper" && computer == "rock") ||
             (user == "scissors" && computer == "paper")) {
        return "You win!";
    } else {
        return "Computer wins!";
    }
}

int main() {
    srand(time(0));
    string userChoice;
    char playAgain;

    cout << " Welcome to Rock, Paper, Scissors!\n";

    do {
        cout << "\nEnter rock, paper, or scissors: ";
        cin >> userChoice;

        string computerChoice = getComputerChoice();
        cout << "Computer chose: " << computerChoice << endl;
        cout << getResult(userChoice, computerChoice) << endl;

        cout << "Play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}

