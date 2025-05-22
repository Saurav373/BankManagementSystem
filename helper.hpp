#ifndef HELPER_HPP
#define HELPER_HPP
#include<string>


namespace helper {
    long long int getLastAccount();
    void saveLastAccountNumber(long long AccountNo);
    bool verifyUser(long long AccountNumber,std::string password);
}

#endif