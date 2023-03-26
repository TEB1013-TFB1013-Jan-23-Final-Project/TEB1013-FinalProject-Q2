#include <iostream>
#include <vector>
#include "question2.h"

int main() {
    bool continueRunning = true;
    int choice;
    std::vector<question2::CustomerDetails> database;

    std::system(CLEAR);
    while (continueRunning) {
        choice = question2::menu();

        switch (choice) {
            case 1:
                question2::addNewCustomerDetails(database);
                break;
            case 2:
                question2::displayParticularCustomerDetails(database);
                break;
            case 3:
                question2::removeParticularCustomerDetails(database);
                break;
            case 4:
                question2::changeParticularCustomerDetails(database);
                break;
            case 5:
                question2::displayAllCustomerDetails(database);
                break;
            case 6:
                continueRunning = false;
                break;
            default:
                std::cerr << "[-] CONGRATULATIONS! YOU HAVE SUCCESSFULLY BREAK THE PROGRAM!" << std::endl;
                return 1;
        }
    }
    return 0;
}