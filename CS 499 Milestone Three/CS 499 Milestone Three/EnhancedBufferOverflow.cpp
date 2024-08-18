// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

int main()
{
    std::cout << "Buffer Overflow Example" << std::endl;

    const std::string account_number = "CharlieBrown42";
    char user_input[20];
    std::cout << "Enter a value: ";
    std::cin.getline(user_input, sizeof(user_input));

    if (std::cin.fail()) {
        std::cin.clear(); // Eliminate the warning
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore remaining input
        std::cerr << "Error: Input exceeded buffer size." << std::endl;
        return 1; // Reject the current execution.
    }

    std::cout << "You entered: " << user_input << std::endl;
    std::cout << "Account Number = " << account_number << std::endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu




