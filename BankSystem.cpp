#include <fstream>
#include <iostream>
#include "helper.hpp"
#include "bankSystem.hpp"

using namespace std;

static long long int CurrAccNumber = helper::getLastAccount();

class BankSystem {
   private:
    string phoneNo;
    string email;
    string password;
    double balance;
    

   public:
    string Fname;
    string Lname;
    long long int AccountNumber;

    BankSystem(string Fname, string Lname, string phoneNo, string email, string password){
        this->Fname = Fname;
        this->Fname = Fname;
        this->Lname = Lname;
        this->phoneNo = phoneNo;
        this->email = email;
        this->password = password;
    }

    void registerUser() {
        if (!this->Fname.length()) {
            cout << "First Name Required!"<<endl;
            return;
        }
        if (!this->Lname.length()) {
            cout << "Last Name Required!"<<endl;
            return;
        }
        if (!this->email.length()) {
            cout << "Email Required!"<<endl;
            return;
        }
        if (!this->password.length()) {
            cout << "Password Required!"<<endl;
            return;
        }
        if (!this->phoneNo.length()) {
            cout << "PhoneNo Required!"<<endl;
            return;
        }

        helper::saveUserDetails(Fname, Lname, email,password,phoneNo,CurrAccNumber);
        cout << "Account Successfully Created!"<<endl;
        cout<<"AccountNumber -> "<<this->AccountNumber<<endl;
        CurrAccNumber++;
    }
    
    void depositMoney(double amount){
        
    }
    ~BankSystem() { helper::saveLastAccountNumber(CurrAccNumber); }
};
