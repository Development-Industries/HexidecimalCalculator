#include "Helper.h"

int main() {
    int number = Helper::GetValidatedInt("Enter a number between 1 and 10: ", 1, 10);
    std::cout << "You entered: " << number << "\n";

    int randomNum = Helper::GetRandomNumberInRange(5, 15);
    std::cout << "Random number: " << randomNum << "\n";

    Helper::PrintIntegerInFormat(number, "binary");
    Helper::PrintIntegerInFormat(number, "hex");
    Helper::PrintIntegerInFormat(number, "octal");

    return 0;
}

