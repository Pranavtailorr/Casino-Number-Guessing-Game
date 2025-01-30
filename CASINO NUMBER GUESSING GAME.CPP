#include <iostream>
#include <random>
#include <ctime>

using namespace std;

class GuessingGame {
private:
    int numberToGuess;
    int numberOfAttempts;
    int maxAttempts;

public:
    GuessingGame(int maxAttempts) : maxAttempts(maxAttempts) {
        random_device rd; // Obtain a random number from hardware
        mt19937 gen(rd()); // Seed the generator
        uniform_int_distribution<> distr(1, 100); // Define the range

        numberToGuess = distr(gen);
        numberOfAttempts = 0;
    }

    bool makeGuess(int guess) {
        numberOfAttempts++;
        if (guess == numberToGuess) {
            cout << "Congratulations! You guessed the number in " << numberOfAttempts << " attempts.\n";
            return true;
        } else if (guess < numberToGuess) {
            cout << "Too low! Try again.\n";
        } else {
            cout << "Too high! Try again.\n";
        }
        return false;
    }

    bool isGameOver() {
        return numberOfAttempts >= maxAttempts;
    }

    void showGameSummary() {
        cout << "Game Over! The number was " << numberToGuess << ".\n";
    }
};

int main() {
    int maxAttempts = 6; // Set the difficulty level of the game
    GuessingGame game(maxAttempts);
    int guess;

    cout << "Guess the number between 1 and 100. You have " << maxAttempts << " attempts.\n";
    while (!game.isGameOver()) {
        cout << "Enter your guess: ";
        cin >> guess;
        if (game.makeGuess(guess)) {
            break;
        }
    }
    if (game.isGameOver()) {
        game.showGameSummary();
    }

    return 0;
}
