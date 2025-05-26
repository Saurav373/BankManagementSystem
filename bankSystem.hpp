#ifndef BANK_SYSTEM_HPP
#define BANK_SYSTEM_HPP
#include <string>
using namespace std;

namespace bankSystem {
class BankSystem {
   private:
    string password;
    double balance;
    bool isLoggedIn;
    
   public:
    string Fname;
    string Lname;
    string phoneNo;
    string email;
    long long int AccountNumber;
    void registerUser(string Fname, string Lname, string phoneNo, string email, string password);
    void deposit(long long accountNumber,double amount);
    void withdraw(double amount);
    bool login(long long accountNumber,string password);
};
}  // namespace bankSystem
#endif