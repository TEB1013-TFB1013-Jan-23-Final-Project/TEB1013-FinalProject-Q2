//header files
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//using structure for customer details
struct CustomerDetails {

    string name;
    string address;
    string city;
    string state;
    int postcode;
    double telephoneNumber;
    double accountBalance;
    string dateOfLastPayment;

};

//to display menu selection
void menu() {

    int customerChoice;

    cout << "   ⋆｡ ﾟ☁︎｡ ⋆ WELCOME TO DREAM BANK ｡ ﾟ☾ ﾟ｡ ⋆  " << endl;
    cout << "---------------------------------------------" << endl;
    cout << "MAIN MENU" << endl;
    cout << "ෆ ENTER NEW CUSTOMER'S RECORD [1]" << endl;
    cout << "ෆ DISPLAY CUSTOMER'S RECORD [2]" << endl;
    cout << "ෆ CHANGE CUSTOMER'S RECORD [3]" << endl;
    cout << "ෆ REMOVE CUSTOMER'S RECORD [4]" << endl;
    cout << "ෆ QUIT [5]" << endl;
    cout << "CHOOSE AN OPTION FROM 1 - 4 ˙ᵕ˙ ";
    cin >> customerChoice;
}

CustomerDetails getDetails(CustomerDetails &obj) {

    cout << endl;

    //prompt and read customer's name
    cout << "Enter name of customer : ";
    cin >> obj.name;

    //prompt and read customer's address
    cout << "Enter customer's address : ";
    cin >> obj.address;

    //prompt and read customer's city
    cout << "Enter customer's city : ";
    cin >> obj.city;

    //prompt and read customer's state
    cout << "Enter customer's state : ";
    cin >> obj.state;

    //prompt and read customer's postcode
    cout << "Enter customer's postcode : ";
    cin >> obj.postcode;

    //prompt and read customer's telephone number
    cout << "Enter customer's telephone number : ";
    cin >> obj.telephoneNumber;

    //prompt and read customer's account balance
    cout << "Enter customer's account balance : ";
    cin >> obj.accountBalance;

    //prompt and read date of customer's last payment
    cout << "Enter date of customer's last payment : ";
    cin >> obj.dateOfLastPayment;

    return obj;
}

//method to display customer's record
void displayDetails(CustomerDetails customers[], int size) {

    //if-else condition
    if (size == 0) {

        //display
        cout << endl << "There's no customer's record to display" << endl;
    } else {

        for (int i = 0; i < size; i++) {

            cout << "☾ CUSTOMER'S NAME ⋆｡°✩";
            cout << "\n" << customers[i].name << endl;

            cout << "☾ CUSTOMER'S ADDRESS ⋆｡°✩";
            cout << "\n" << customers[i].address << endl;

            cout << "☾ CUSTOMER'S CITY ⋆｡°✩";
            cout << "\n" << customers[i].city << endl;

            cout << "☾ CUSTOMER'S STATE ⋆｡°✩";
            cout << "\n" << customers[i].state << endl;

            cout << "☾ CUSTOMER'S POSTCODE ⋆｡°✩";
            cout << "\n" << customers[i].postcode << endl;

            cout << "☾ CUSTOMER'S TELEPHONE NUMBER ⋆｡°✩";
            cout << "\n" << customers[i].telephoneNumber << endl;

            cout << "☾ CUSTOMER'S ACCOUNT BALANCE ⋆｡°✩";
            cout << "\n" << customers[i].accountBalance << endl;

            cout << "☾ DATE OF CUSTOMER'S LAST PAYMENT ⋆｡°✩";
            cout << "\n" << customers[i].dateOfLastPayment << endl;
        }
    }
}

//to change customer's record
void
change_record(string name[], string address[], string city[], string state[], int postcode[], double telephoneNumber[],
              double accountBalance[], string dateOfLastPayment[]) {

    int change;
    string nameInput;
    string customers;

    cout << endl << "Enter name of customer to be modified : ";
    getline(cin, nameInput);
    cin.ignore();

    change = getCustomer(customers, count, name);

    //if name not valid
    //print message and break from case

    if (change == -1) {

        cout << endl << "Wrong customer name to change : " << endl;
    } else {

        customers[change] = getDetails(customers);
    }
}

int getCustomer()