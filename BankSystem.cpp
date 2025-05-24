#include "bankSystem.hpp"

#include <fstream>
#include <iostream>

#include "helper.hpp"
#include "userAuth.hpp"

using namespace std;

static long long int CurrAccNumber = helper::getLastAccount() + 1;

namespace bankSystem {

void BankSystem::registerUser(string Fname, string Lname, string phoneNo,
                              string email, string password) {
    system("cls");
    if (!Fname.length()) {
        cout << "First Name Required!" << endl;
        return;
    }
    if (!Lname.length()) {
        cout << "Last Name Required!" << endl;
        return;
    }
    if (!email.length()) {
        cout << "Email Required!" << endl;
        return;
    }
    if (!password.length()) {
        cout << "Password Required!" << endl;
        return;
    }
    if (!phoneNo.length()) {
        cout << "PhoneNo Required!" << endl;
        return;
    }
    this->Fname = Fname;
    this->Lname = Lname;
    this->email = email;
    this->password = password;
    this->phoneNo = phoneNo;
    this->AccountNumber = helper::saveUserDetails(Fname, Lname, email, password, phoneNo, CurrAccNumber);
    if (this->AccountNumber) {
        cout << "Account Successfully Created!" << endl;
        cout << "AccountNumber -> " << this->AccountNumber << endl;
        CurrAccNumber++;
        this->isLoggedIn = true;
        helper::generateStatementTempelate(this->AccountNumber);
    } else {
        cout << "Error In Registration!";
    }
}

void BankSystem::deposit(long long accountNumber, double amount) {
    helper::updateValue(accountNumber, "Balance", to_string(this->balance + amount));
    helper::createStatement(accountNumber, "DEPOSIT", amount);
    this->balance += amount;
}

bool BankSystem::login(long long accountNumber, string password) {
    if (userAuth::verifyUser(accountNumber, password)) {
        this->isLoggedIn = true;
        this->Fname = helper::getValue(accountNumber, "Fname");
        this->Lname = helper::getValue(accountNumber, "Lname");
        this->email = helper::getValue(accountNumber, "Email");
        this->phoneNo = helper::getValue(accountNumber, "PhoneNo");
        this->balance = stod(helper::getValue(accountNumber, "Balance"));
        this->AccountNumber = accountNumber;
        return true;
    }
    return false;
}
void BankSystem::withdraw(double amount) {
    if (!isLoggedIn) {
        cout << "Please Login To withdraw!";
        return;
    }
    if (this->balance < amount) {
        cout << "Insufficient Balance!";
        return;
    }
    this->balance -= amount;
    cout<<"Withdraw SuccessFully!";
    helper::createStatement(this->AccountNumber,"WITHDRAW",amount);
}

}  // namespace bankSystem
