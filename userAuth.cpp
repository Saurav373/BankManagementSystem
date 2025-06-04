#include <fstream>
#include <string>

#include "userAuth.hpp"
#include "bcrypt_cpp.h"
#include "helper.hpp"
using namespace std;

namespace userAuth {
bool verifyUser(long long AccountNumber, std::string password) {
    string passwordHash = helper::getValue(AccountNumber, "Password");
    bool isValid = bcrypt::validatePassword(password,passwordHash);
    if (isValid) {
        return true;
    }
    return false;
};

}  // namespace userAuth