#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
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

    std::ifstream tempFile;
    bool fileExists;
    tempFile.open("database.txt");
    if (tempFile.is_open()) {
        fileExists = true;
        tempFile.close();
    } else {
        fileExists = false;
    }

    std::ofstream outputFile;
    std::cout << "[+] Opening output file to save database." << std::endl;
    outputFile.open("database.txt", std::ios_base::app);

    if (!outputFile.fail()) {
        std::cout << "[+] Saving database to output file." << std::endl;
        if (!fileExists) {
            outputFile << "+==================+" << std::endl;
            outputFile << "  CUSTOMER RECORDS  " << std::endl;
            outputFile << "+==================+\n" << std::endl;
        }

        for (int i = 0; i < database.size(); i++) {
            outputFile << "Customer Details" << std::endl;
            outputFile << "\tNAME: " << database[i].name << std::endl;
            outputFile << "\tADDRESS: " << database[i].address << std::endl;
            outputFile << "\tCITY: " << database[i].city << std::endl;
            outputFile << "\tSTATE: " << database[i].state << std::endl;
            outputFile << "\tPOSTCODE: " << database[i].postcode << std::endl;
            outputFile << "\tTELEPHONE: " << database[i].telephoneNumber << std::endl;
            outputFile.precision(2);
            outputFile << "\tACCOUNT BALANCE: RM" << std::fixed << database[i].accountBalance << std::endl;
            outputFile << "\tDATE OF LAST PAYMENT: " << database[i].dateOfLastPayment.day << '/'
                       << database[i].dateOfLastPayment.month << '/' << database[i].dateOfLastPayment.year << '\n'
                       << std::endl;
        }
    } else {
        std::cerr << "[-] Output file failed to open. Database not saved." << std::endl;
    }

    if (outputFile.is_open()) {
        std::cout << "[+] Closing output file." << std::endl;
        outputFile.close();
    }
    return 0;
}