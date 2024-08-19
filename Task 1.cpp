#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator
    std::srand(std::time(0));

    // Generate a random number between 1 and 100
    int number_to_guess = std::rand() % 100 + 1;
    int user_guess;

    std::cout << "Welcome to the 'Guess the Number' game!" << std::endl;
    std::cout << "I've selected a number between 1 and 100. Can you guess it?" << std::endl;

    do {
        // Get the user's guess
        std::cout << "Enter your guess: ";
        std::cin >> user_guess;

        // Provide feedback
        if (user_guess < number_to_guess) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (user_guess > number_to_guess) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You've guessed the correct number: " << number_to_guess << std::endl;
        }
    } while (user_guess != number_to_guess);

    return 0;
}


