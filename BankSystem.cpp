#include "bankSystem.hpp"

#include <fstream>
#include <iostream>

#include "helper.hpp"

using namespace std;

static long long int CurrAccNumber = helper::getLastAccount()+1;

namespace bankSystem {
    BankSystem::BankSystem(string Fname, string Lname, string phoneNo, string email, string password) {
        this->Fname = Fname;
        this->Lname = Lname;
        this->phoneNo = phoneNo;
        this->email = email;
        this->password = password;
    }

    void BankSystem::registerUser() {
        if (!this->Fname.length()) {
            cout << "First Name Required!" << endl;
            return;
        }
        if (!this->Lname.length()) {
            cout << "Last Name Required!" << endl;
            return;
        }
        if (!this->email.length()) {
            cout << "Email Required!" << endl;
            return;
        }
        if (!this->password.length()) {
            cout << "Password Required!" << endl;
            return;
        }
        if (!this->phoneNo.length()) {
            cout << "PhoneNo Required!" << endl;
            return;
        }

        this->AccountNumber = helper::saveUserDetails(Fname, Lname, email, password, phoneNo, CurrAccNumber);
        cout << "Account Successfully Created!" << endl;
        cout << "AccountNumber -> " << this->AccountNumber << endl;
        CurrAccNumber++;
    }

    void BankSystem::deposit(double amount,long long accountNumber){
        helper::updateValue(accountNumber,"Balance",to_string(this->balance+amount));
        helper::createStatement(accountNumber,"DEPOSIT",amount);
    }

}  // namespace bankSystem
