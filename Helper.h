#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <string>
#include <bitset>

namespace Helper {

    // Function to get a validated integer input from the user
    int GetValidatedInt(const char* strMessage, int nMinimumRange = 0, int nMaximumRange = 0) {
        int userInput;
        bool inputValid = false;

        while (!inputValid) {
            std::cout << strMessage;
            std::cin >> userInput;

            // Check if the input is a valid integer
            if (std::cin.fail()) {
                std::cin.clear();  // Clear the error flag on cin
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore any remaining input in the buffer
                std::cout << "Invalid input. Please enter a valid integer.\n";
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the buffer even if the input was successful

                // Check if the input is within the specified range
                if ((nMinimumRange == 0 && nMaximumRange == 0) || (userInput >= nMinimumRange && userInput <= nMaximumRange)) {
                    inputValid = true;
                }
                else {
                    std::cout << "Input out of range. Please enter a value between " << nMinimumRange << " and " << nMaximumRange << ".\n";
                }
            }
        }

        return userInput;
    }

    // Function to generate a random number within a specified range
    int GetRandomNumberInRange(int min, int max) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));  // Seed random number generator
        return std::rand() % (max - min + 1) + min;
    }

    // Function to print a provided integer in binary, hex, or octal format
    void PrintIntegerInFormat(int number, const std::string& format) {
        if (format == "binary") {
            std::cout << "Binary: " << std::bitset<32>(number) << "\n";
        }
        else if (format == "hex") {
            std::cout << "Hexadecimal: " << std::hex << number << std::dec << "\n";
        }
        else if (format == "octal") {
            std::cout << "Octal: " << std::oct << number << std::dec << "\n";
        }
        else {
            std::cout << "Invalid format. Please choose 'binary', 'hex', or 'octal'.\n";
        }
    }

}

#endif // HELPER_H
