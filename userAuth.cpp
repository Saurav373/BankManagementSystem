#include "userAuth.hpp"
#include "helper.hpp"
#include <fstream>
#include <string>
using namespace std;

namespace userAuth {
bool verifyUser(long long AccountNumber, std::string password) {
    string passwordValue = helper::getValue(AccountNumber,"Password");
    if (password == passwordValue) {
        return true;
    }
    return false;
};
}  // namespace userAuth