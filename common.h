    //
// Created by ammar on 26/3/2023.
//

#ifndef TEB1013_FINALPROJECT_Q2_COMMON_H
#define TEB1013_FINALPROJECT_Q2_COMMON_H

#include "common.inl"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

namespace common {
    struct Date {
        int day;
        int month;
        int year;
    };

    /**
     * Checks if the year is a leap year or not.
     * @param year year in yyyy format
     * @return is or is not leap year
     */
    bool isLeapYear(int year);

    /**
     * This function is meant to handle accepting date in dd/mm/yyyy format.
     * It checks whether the year is leap, month is valid, and day is valid.
     * @param message the message that is printed out before waiting for an input
     * @return a Date struct with valid date
     */
    Date getDateInput(const char* message);

    /**
     * This function is meant to be used when a string input is needed from the user.
     * The message is printed out first before accepting input.
     * It keeps asking for the input if the user types values outside of the input constraint(s).
     * @param message the message that is printed out before waiting for an input
     * @param func a function that accepts the input as its parameter and returns a bool, to check for input constraints.
     * @return returns a valid--well within constraint(s)--string.
     */
    std::string getStrInput(const char* message);
}

#endif //TEB1013_FINALPROJECT_Q2_COMMON_H
