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
    void saveUserDetails();

   public:
    BankSystem(string Fname, string Lname, string phoneNo, string email, string password) {};
    string Fname;
    string Lname;
    long long int AccountNumber;
    void registerUser();
    void depositMoney(double amount);
};
}  // namespace bankSystem
#endif