#ifndef HELPER_HPP
#define HELPER_HPP
#include <string>
using namespace std;

namespace helper {
    long long int getLastAccount();
    void saveLastAccountNumber(long long AccountNo);
    string getValue(long long AccountNumber, string key);
    void createStatement(long long accountNumber, string type);
    void saveUserDetails(string Fname, string Lname, string email, string password, string phoneNo,long long AccountNumber);
}  // namespace helper

#endif