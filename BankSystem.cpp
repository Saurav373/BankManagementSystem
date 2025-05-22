#include <fstream>
#include <iostream>
#include "helper.hpp"

using namespace std;

static long long int CurrAccNumber = helper::getLastAccount();

class BankSystem {
   private:
    string phoneNo;
    string email;
    string password;
    double balance;
    

    void saveUserDetails() {
        this->AccountNumber = ++CurrAccNumber;
        this->balance = 0.0;
        ofstream UserFile;
        UserFile.open("./data/Users/" + to_string(this->AccountNumber) + ".txt");

        if (!UserFile.is_open()) {
            cout << "Error in Saving Info!"<<endl;
            CurrAccNumber--;
            return;
        }

        UserFile << "Fname : " << Fname << '\n';
        UserFile << "Lname : " << Lname << '\n';
        UserFile << "Email : " << email << '\n';
        UserFile << "PhoneNo : " << phoneNo << '\n';
        UserFile << "AccountNo : " << AccountNumber << '\n';
        UserFile << "Password : " << password << '\n';
        UserFile.close();

        helper::saveLastAccountNumber(CurrAccNumber);
    }

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

        saveUserDetails();
        cout << "Account Successfully Created!"<<endl;
        cout<<"AccountNumber -> "<<this->AccountNumber<<endl;
    }
    
    bool login(long long AccountNumber,string password){
        return helper::verifyUser(AccountNumber,password);
    }
    
    ~BankSystem() { helper::saveLastAccountNumber(CurrAccNumber); }
};
