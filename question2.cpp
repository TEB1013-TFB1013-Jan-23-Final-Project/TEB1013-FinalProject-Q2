//
// Created by ammar on 26/3/2023.
//

#include <iostream>
#include "question2.h"

namespace question2 {
    /**
     * This function acts as the menu that lists the options that the user can choose.
     * @return option listed
     */
    int menu() {
        int customerChoice;

        std::cout << "\n";
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "            WELCOME TO DREAM BANK            " << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "MAIN MENU" << std::endl;
        std::cout << "1. ENTER NEW CUSTOMER'S RECORD" << std::endl;
        std::cout << "2. DISPLAY PARTICULAR CUSTOMER'S RECORD" << std::endl;
        std::cout << "3. REMOVE CUSTOMER'S RECORD" << std::endl;
        std::cout << "4. CHANGE CUSTOMER'S RECORD" << std::endl;
        std::cout << "5. DISPLAY ALL CUSTOMER'S RECORD" << std::endl;
        std::cout << "6. QUIT" << std::endl;
        customerChoice = common::getNumInput<int>("CHOOSE AN OPTION (FROM 1 - 6)",
                                                  [](int input) { return input >= 1 && input <= 6; });
        std::system(CLEAR);
        return customerChoice;
    }

    /**
     *This function asks to create and input new customer details.
     * @return valid details for new customers
     */
    CustomerDetails createNewCustomerDetails() {
        CustomerDetails result{};

        std::cin.ignore();
        result.name = common::getStrInput("Enter customer's name");
        result.address = common::getStrInput("Enter customer's address");
        result.city = common::getStrInput("Enter customer's city");
        result.state = common::getStrInput("Enter customer's state");
        result.postcode = common::getNumInput<int>("Enter customer's postcode (XXXXX)",
                                                   [](int input) { return input >= 10000 && input <= 99999; });
        std::cin.ignore();
        result.telephoneNumber = common::getStrInput("Enter phone number");
        result.accountBalance = common::getNumInput<float>("Enter customer's account balance (in RM)",
                                                           [](float input) { return input >= 0.0f; });
        result.dateOfLastPayment = common::getDateInput("Enter customer's last payment date (dd/mm/yyyy)");
        return result;
    }

    /**
     *This function is meant to display the customers details.
     * @param customer CustomerDetails object
     */
    void printDetails(CustomerDetails &customer) {
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << " CUSTOMER DETAILS " << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "NAME: " << customer.name << std::endl;
        std::cout << "ADDRESS: " << customer.address << std::endl;
        std::cout << "CITY: " << customer.city << std::endl;
        std::cout << "STATE: " << customer.state << std::endl;
        std::cout << "POSTCODE: " << customer.postcode << std::endl;
        std::cout << "TELEPHONE NUMBER: " << customer.telephoneNumber << std::endl;
        std::cout.precision(2);
        std::cout << std::fixed << "ACCOUNT BALANCE: RM" << customer.accountBalance << std::endl;
        std::cout << "DATE OF LAST PAYMENT: " << customer.dateOfLastPayment.day << '/'
                  << customer.dateOfLastPayment.month << '/' << customer.dateOfLastPayment.year << std::endl;
    }
    /**
     * This function meant to create new customer details.
     * Using the createNewCustomerDetails' function
     * @param database adds it to the database vector
     */
    void addNewCustomerDetails(std::vector<CustomerDetails> &database) {
        CustomerDetails newCustomer = createNewCustomerDetails();
        database.push_back(newCustomer);
    }
    /**
     * This function is meant to search for a customer by name.
     * Displays their details if found.
     * @param database if found from the database vector
     */
    void displayParticularCustomerDetails(std::vector<CustomerDetails> &database) {
        if (database.empty()) {
            std::cout << "[-] NO CUSTOMER DETAILS RECORD." << std::endl;
            return;
        }
        std::cin.ignore();
        std::string customerName = common::getStrInput("Enter customer's name");
        bool isFound = false;

        for (auto &customer: database) {
            if (customer.name == customerName) {
                isFound = true;
                printDetails(customer);
            }
        }

        if (!isFound) {
            std::cout << "[-] No customer with name " << customerName << " is found in the database." << std::endl;
        }
    }
    /**
     * This function is meant to remove a customer by name.
     * @param database if found from the database vector
     */
    void removeParticularCustomerDetails(std::vector<CustomerDetails> &database) {
        if (database.empty()) {
            std::cout << "[-] NO CUSTOMER DETAILS RECORD." << std::endl;
            return;
        }
        std::cin.ignore();
        std::string customerName = common::getStrInput("Enter customer's name that needs to be removed");
        bool isFound = false;
        int indexToRemove = -1;

        for (int i = 0; i < database.size(); i++) {
            if (database[i].name == customerName) {
                indexToRemove = i;
                isFound = true;
            }
        }

        if (isFound) {
            if (indexToRemove == 0) {
                database.erase(database.begin());
            } else {
                database.erase(database.begin() + indexToRemove);
            }
        } else {
            std::cout << "[-] No customer with name " << customerName << " is found in the database." << std::endl;
        }
    }
    /**
     * This function is meant to modify a customer details by name.
     * @param database if found from the database vector
     */
    void changeParticularCustomerDetails(std::vector<CustomerDetails> &database) {
        if (database.empty()) {
            std::cout << "[-] NO CUSTOMER DETAILS RECORD." << std::endl;
            return;
        }
        std::cin.ignore();
        std::string customerName = common::getStrInput("Enter customer's name whose details need to be modified");
        CustomerDetails newCustomer;
        bool isFound = false;

        for (auto &customer: database) {
            if (customer.name == customerName) {
                isFound = true;
                newCustomer = createNewCustomerDetails();
                customer = newCustomer;
                break;
            }
        }

        if (!isFound) {
            std::cout << "[-] No customer with name " << customerName << " is found in the database." << std::endl;
        }
    }
    /**
     * This function is meant to diplay details of all customers.
     * @param database from the database vector
     */
    void displayAllCustomerDetails(std::vector<CustomerDetails> &database) {
        if (database.empty()) {
            std::cout << "[-] NO CUSTOMER DETAILS RECORD." << std::endl;
            return;
        }
        std::cout << "+===========================================+" << std::endl;
        std::cout << "            ALL CUSTOMER DETAILS             " << std::endl;
        std::cout << "+===========================================+" << std::endl;

        for (CustomerDetails &customer: database) {
            printDetails(customer);
            std::cout << "+-------------------------------------------+" << std::endl;
        }
    }
}
