#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    // Initialize variables
    int guess = 0;
    int attempts = 0;

    std::cout << "Welcome to the Guess the Number Game!" << std::endl;
    std::cout << "I've selected a number between 1 and 100. Try to guess it." << std::endl;

    while (guess != secretNumber) {
        // Get user input
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        // Increment attempts
        attempts++;

        // Check if the guess is correct, too high, or too low
        if (guess == secretNumber) {
            std::cout << "Congratulations! You guessed the correct number " << secretNumber << " in " << attempts << " attempts." << std::endl;
        } else if (guess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else {
            std::cout << "Too high! Try again." << std::endl;
        }
    }

    return 0;
}
