#ifndef BANK_SYSTEM_HPP
#define BANK_SYSTEM_HPP
#include <string>
using namespace std;

namespace bankSystem {
class BankSystem {
   private:
    string phoneNo;
    string email;
    string password;
    double balance;
    

   public:
    BankSystem(string Fname, string Lname, string phoneNo, string email, string password);
    string Fname;
    string Lname;
    long long int AccountNumber;
    void registerUser();
    void deposit(double amount,long long accountNumber);
    void withdraw(double amount,long long accountNumber);
};
}  // namespace bankSystem
#endif