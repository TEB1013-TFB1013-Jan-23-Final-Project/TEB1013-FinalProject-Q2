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

    CustomerDetails createNewCustomerDetails();
    void addNewCustomerDetails(std::vector<CustomerDetails> &database);
    void displayParticularCustomerDetails(std::vector<CustomerDetails> &database);
    void removeParticularCustomerDetails(std::vector<CustomerDetails> &database);
    void changeParticularCustomerDetails(std::vector<CustomerDetails> &database);
    void displayAllCustomerDetails(std::vector<CustomerDetails> &database);

}
#endif //TEB1013_FINALPROJECT_Q2_QUESTION2_H
