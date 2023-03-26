//
// Created by ammar on 26/3/2023.
//

#ifndef TEB1013_FINALPROJECT_Q2_QUESTION2_H
#define TEB1013_FINALPROJECT_Q2_QUESTION2_H

#include <string>
#include <vector>
#include "common.h"

namespace question2 {
    struct CustomerDetails {
        std::string name;
        std::string address;
        std::string city;
        std::string state;
        int postcode;
        std::string telephoneNumber;
        float accountBalance;
        common::Date dateOfLastPayment;
    };

    /**
     * This function acts as the menu that lists the options that the user can choose.
     * @return option listed
     */
    int menu();
    /**
     * This function asks to create and input new customer details.
     * @return valid details for new customers
     */
    CustomerDetails createNewCustomerDetails();
    /**
     * This function meant to create new customer details.
     * Using the createNewCustomerDetails' function
     * @param database adds it to the database vector
     */
    void addNewCustomerDetails(std::vector<CustomerDetails> &database);
    /**
     * This function is meant to search for a customer by name.
     * Displays their details if found.
     * @param database if found from the database vector
     */
    void displayParticularCustomerDetails(std::vector<CustomerDetails> &database);
    /**
     * This function is meant to remove a customer by name.
     * @param database if found from the database vector
     */
    void removeParticularCustomerDetails(std::vector<CustomerDetails> &database);
    /**
     * This function is meant to modify a customer details by name.
     * @param database if found from the database vector
     */
    void changeParticularCustomerDetails(std::vector<CustomerDetails> &database);
    /**
     * This function is meant to display details of all customers.
     * @param database from the database vector
     */
    void displayAllCustomerDetails(std::vector<CustomerDetails> &database);

}
#endif //TEB1013_FINALPROJECT_Q2_QUESTION2_H
