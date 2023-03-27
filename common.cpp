#include <iostream>
#include <string>
#include "common.h"

namespace common {
    /**
     * This function is meant to handle accepting date in dd/mm/yyyy format.
     * It checks whether the year is leap, month is valid, and day is valid.
     * @param message the message that is printed out before waiting for an input
     * @return a Date struct with valid date
     */
    Date getDateInput(const char* message) {
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        Date date{};
        char firstDelimiter, secondDelimiter;
        bool validDelimiter, validMonth, validYear, validDate;
        int maxValidDay;

        do {
            std::cout << "[*] " << message << " (dd/mm/yyyy): ";
            std::cin >> date.day >> firstDelimiter >> date.month >> secondDelimiter >> date.year;
            std::cin.ignore();
            validDelimiter = firstDelimiter == '/' && secondDelimiter == '/';
            validYear = date.year >= 1000 && date.year <= 9999;
            validMonth = date.month >= 1 && date.month <= 12;

            if (validYear && validMonth) {
                if (isLeapYear(date.year) && date.month == 2) {
                    maxValidDay = 29;
                } else {
                    maxValidDay = daysInMonth[date.month - 1];
                }

                if (date.day >= 0 && date.day <= maxValidDay) {
                    validDate = true;
                } else {
                    validDate = false;
                }
            } else {
                validDate = false;
            }
        } while (!(validDelimiter && validDate));
        return date;
    }

    /**
     * This function is meant to be used when a string input is needed from the user.
     * The message is printed out first before accepting input.
     * @param message the message that is printed out before waiting for an input
     * @return returns a string.
     */
    std::string getStrInput(const char* message) {
        std::string input;
        std::cout << "[*] " << message << ": ";
        std::getline(std::cin, input);
        return input;
    }

    /**
     * Checks if the year is a leap year or not.
     * @param year year in yyyy format
     * @return is or is not leap year
     */
    bool isLeapYear(int year) {
        return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    }
}
