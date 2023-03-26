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
int menu() {

    //int customerChoice;

    cout << "\n";
    cout << "   ⋆｡ ﾟ☁︎｡ ⋆ WELCOME TO DREAM BANK ｡ ﾟ☾ ﾟ｡ ⋆  " << endl;
    cout << "---------------------------------------------" << endl;
    cout << "MAIN MENU" << endl;
    cout << "ෆ ENTER NEW CUSTOMER'S RECORD [1]" << endl;
    cout << "ෆ DISPLAY CUSTOMER'S RECORD [2]" << endl;
    cout << "ෆ CHANGE CUSTOMER'S RECORD [3]" << endl;
    cout << "ෆ REMOVE CUSTOMER'S RECORD [4]" << endl;
    cout << "ෆ QUIT [5]" << endl;
    //cout << "\nCHOOSE AN OPTION FROM 1 - 4 ˙ᵕ˙ : ";
    //cin >> customerChoice;

    //return customerChoice;
}

CustomerDetails getDetails (CustomerDetails obj) {

    cout << endl;

    //prompt and read customer's name
    cout << "Enter name of customer : ";
    cin.ignore();
    getline(cin, obj.name);//user getline for string to accept whitespaces

    //prompt and read customer's address
    cout << "Enter customer's address : ";
    getline(cin, obj.address);

    //prompt and read customer's city
    cout << "Enter customer's city : ";
    getline(cin, obj.city);

    //prompt and read customer's state
    cout << "Enter customer's state : ";
    getline(cin, obj.state);

    //prompt and read customer's postcode
    cout << "Enter customer's postcode : ";
    cin >> obj.postcode;

    //prompt and read customer's telephone number
    cout << "Enter customer's telephone number : +6";
    cin >> obj.telephoneNumber;

    //prompt and read customer's account balance, will keep loop if user's input is 0
    do
    {
        cout << "Enter customer's account balance : RM";
        cin >> obj.accountBalance;
    }
    while(obj.accountBalance <0);

    //prompt and read date of customer's last payment
    cout << "Enter date of customer's last payment (dd/mm/yyyy) : ";
    cin.ignore();
    getline(cin, obj.dateOfLastPayment);

    return obj;
}

//method to display customer's record
void displayDetails (CustomerDetails customers[], int size) {

    //if-else condition
    if (size == 0) {

        //display
        cout << endl << "There's no customer's record to display."
                        "" << endl;
    }

    else {

        for ( int i = 0; i < size; i++) {
            cout << "\nCustomer [" << (i+1) << "]\n";
            cout << "\n";
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

            cout << "CUSTOMER'S DETAILS HAS BEEN RECORDED";
            cout << "\n---------------------------------------------------------------------\n";
        }
    }
}

//to change customer's record
CustomerDetails change_record (CustomerDetails customers[], int size) {
    bool found = false;
    string name;

    cout << endl << "Enter name of customer to be modified : ";
    cin.ignore();
    getline(cin, name);//use getline for string to accept whitespaces

    for (int i = 0; i < size; i++) {
        if (customers[i].name == name) {//if the string contains the searched query

            //had to redundant to avoid double usage of cin.ignore()

            //prompt and read customer's name
            cout << "Enter name of customer : ";
            getline(cin, customers[i].name);//user getline for string to accept whitespaces

            //prompt and read customer's address
            cout << "Enter customer's address : ";
            getline(cin, customers[i].address);

            //prompt and read customer's city
            cout << "Enter customer's city : ";
            getline(cin, customers[i].city);

            //prompt and read customer's state
            cout << "ENTER CUSTOMER'S STATE : ";
            getline(cin, customers[i].state);

            //prompt and read customer's postcode
            cout << "Enter customer's postcode : ";
            cin >> customers[i].postcode;

            //prompt and read customer's telephone number
            cout << "Enter customer's telephone number : +6";
            cin >> customers[i].telephoneNumber;

            //prompt and read customer's account balance
            cout << "Enter customer's account balance : RM";
            cin >> customers[i].accountBalance;

            //prompt and read date of customer's last payment
            cout << "Enter date of customer's last payment (dd/mm/yyyy) : ";
            cin.ignore();
            getline(cin, customers[i].dateOfLastPayment);

            found = true;
            return customers[i];//returns the object value


        }
    }

    if (found == false) {
        cout << endl << "WRONG CUSTOMER NAME TO CHANGE." << endl;
    }

}

//to remove customer's record
CustomerDetails remove_record (CustomerDetails customers[], int &size) {

    string name;
    bool found = false;

    cout << "Enter customer's name to remove : ";
    cin.ignore();
    getline(cin, name);//use getline for string to accept whitespaces

    for (int i = 0; i < size; i++) {
        if (customers[i].name == name) {
            cout << customers[i].name << " has been removed from the record." << endl;
            for (int j = i; j < size - 1; j++) {
                customers[j] = customers[j+1];
            }
            size--;
            found = true;
            return customers[size];
        }
    }

    if (found == false) {
        cout << name << " not found in the record." << endl;
    }
}

void quit() {

    cout << "THANK YOU SEE YOU AGAIN!" << endl;
    exit(0);
}

int main() {

    const int MAX_SIZE = 50;
    CustomerDetails customers[MAX_SIZE];
    int size = 0;

    int choice;

    do {
        choice = menu();

        cout << "\nCHOOSE AN OPTION FROM 1 - 5 ˙ᵕ˙ : ";
        cin >> choice;

        switch (choice) {
            case 1:
                customers[size] = getDetails(customers[size]);
                size++;
                break;

            case 2:
                displayDetails(customers, size);
                break;

            case 3:
                customers[size] = change_record(customers, size);
                break;

            case 4:
                customers[size] = remove_record(customers, size);
                break;

            case 5:
                quit();
                break;

            default:
                cout << "INVALID CHOICE" << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}