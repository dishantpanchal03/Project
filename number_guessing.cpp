#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void playGame() {
    int randomNumber =  rand() % 100 + 1; // Random number between 1 and 100
    int guess;

     cout << "Guess the number between 1 and 100: ";
    do {
         cin >> guess;
        if (guess < randomNumber) {
             cout << "Too low! Try again: ";
        } else if (guess > randomNumber) {
             cout << "Too high! Try again: ";
        }
    } while (guess != randomNumber);

     cout << "Congratulations! You guessed the number!" <<  endl;
}

int main() {
     srand(static_cast<unsigned int>( time(0))); // Seed random number generator

    char playAgain;
    do {
        playGame();
         cout << "Do you want to play again? (y/n): ";
         cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}

