#include <fstream>
#include <iostream>
#include "bankSystem.hpp"
#include "helper.hpp"
#include "bcrypt_cpp.h"
#include "userAuth.hpp"

using namespace std;

static long long int CurrAccNumber = helper::getLastAccount() + 1;

namespace bankSystem {

void BankSystem::registerUser(string Fname, string Lname, string phoneNo,string email, string password) {
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
    string passwordHash = bcrypt::generateHash(password);
    this->Fname = Fname;
    this->Lname = Lname;
    this->email = email;
    this->password = passwordHash;
    this->phoneNo = phoneNo;
    this->AccountNumber = helper::saveUserDetails(Fname, Lname, email, passwordHash, phoneNo, CurrAccNumber);
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
    bool result = helper::updateValue(accountNumber, "Balance", to_string(this->balance + amount));
    if(!result){
        cout<<"Failed To Deposit!"<<endl;
        return;
    }
    helper::createStatement(accountNumber, "DEPOSIT", amount);
    this->balance += amount;
    cout<<"Deposited Successfully!"<<endl;
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
    if (!this->isLoggedIn) {
        cout << "Please Login To withdraw!"<<endl;
        return;
    }
    if (this->balance < amount) {
        cout << "Insufficient Balance!"<<endl;
        return;
    }
    this->balance -= amount;
    cout<<"Withdraw SuccessFully!"<<endl;
    cout<<"Remaining Balance : "<<this->balance<<endl;
    helper::createStatement(this->AccountNumber,"WITHDRAW",amount);
}
void BankSystem::getStatement(){
    if(!this->isLoggedIn){
        cout<<"Login To View Statement !"<<endl;
        return;
    }

    ifstream file("./data/Statements/"+to_string(this->AccountNumber)+".txt");
    if(!file){
        cout<<"Failed To Access Statement!"<<endl;
        return;
    }
    string data;
    while(getline(file,data)){
        cout<<data<<endl;
    }
    file.close();
    cout<<endl;
    string balance = helper::getValue(this->AccountNumber,"Balance");
    cout<<"Balance : "<<balance<<endl;
    cout<<endl;
    return;
}

}  // namespace bankSystem
