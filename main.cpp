#include <filesystem>
#include <iostream>
#include <limits>
#include <fstream>
#include "bankSystem.hpp"
using namespace std;

void createDBFolderStructure() {
    filesystem::path usersDir("data/Users");
    filesystem::path statementsDir("data/Statements");
    // lastAccNum.txt
    
    if (!exists(usersDir)) {
        create_directories(usersDir);
    }
    if (!exists(statementsDir)) {
        create_directories(statementsDir);
    }
    ofstream historyFile("data/lastAccNum.txt");
    if(!historyFile){
        return;
    }
    historyFile.seekp(0, std::ios::end);
     if (historyFile.tellp() == 0) {
        // File is empty, write initial value
        historyFile << "2345986543";
    }
}

int greetUser() {
    
    system("cls");
    int choice;
    cout << "============================================\n";
    cout << "       WELCOME TO NEPAL RASTRYA BANK\n";
    cout << "============================================\n\n";
    cout << "1) Register\n";
    cout << "2) Login\n";
    cout << "3) Deposit\n";
    cout << "4) Withdraw\n";
    cout << "5) View Statement\n";
    cout << "6) Exit\n";
    cout << "\nEnter your choice: ";
    cin >> choice;
    if (cin.fail()) {
        cin.clear();                                          // reset failbit
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // discard bad input
        choice = -1;                                          // invalid choice
    }
    return choice;
    return choice;
}

int main() {
    createDBFolderStructure();
    bankSystem::BankSystem User;
    while (true) {
        int choice = greetUser();

        if (choice == 1) {
            system("cls");
            cout << "Enter your Details:\n";
            cout << "First Name: ";
            cin >> User.Fname;
            cout << "Last Name: ";
            cin >> User.Lname;
            cout << "Phone Number: ";
            cin >> User.phoneNo;
            cout << "Email: ";
            cin >> User.email;
            string pass;
            cout << "Password: ";
            cin >> pass;

            User.registerUser(User.Fname, User.Lname, User.phoneNo, User.email, pass);
            system("pause");
        }

        else if (choice == 2) {
            system("cls");
            long long acc;
            string pass;
            cout << "Account Number: ";
            cin >> acc;
            cout << "Password: ";
            cin >> pass;

            if (User.login(acc, pass)) {
                cout << "Login successful!\n";
            } else {
                cout << "Invalid account number or password!\n";
            }
            system("pause");
        }

        else if (choice == 3) {
            system("cls");
            long long acc;
            double amt;
            cout << "Account Number: ";
            cin >> acc;
            cout << "Amount to Deposit: ";
            cin >> amt;
            User.deposit(acc, amt);
            system("pause");
        }

        else if (choice == 4) {
            system("cls");
            double amt;
            cout << "Amount to Withdraw: ";
            cin >> amt;
            User.withdraw(amt);
            system("pause");
        } else if (choice == 5) {
            system("cls");
            User.getStatement();
            system("pause");
        } else if (choice == 6) {
            cout << "Thank you for using NEPAl RASTRYA BANK. Goodbye!\n";
            break;
        }

        else {
            cout << "Invalid choice. Please try again.\n";
            system("pause");
        }
    }
    return 0;
}