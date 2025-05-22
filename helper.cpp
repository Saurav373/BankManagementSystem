#include <fstream>
#include <iostream>
using namespace std;

namespace helper {

long long int getLastAccount() {
    ifstream lastAccNum("./data/lastAccNum.txt");
    long long int AccNum;
    lastAccNum >> AccNum;
    return AccNum;
};

void saveLastAccountNumber(long long AccountNo) {
    ofstream file("./data/lastAccNum.txt");
    file << AccountNo;
    file.close();
};

string getValue(long long AccountNumber, string key) {
    ifstream Userfile;
    Userfile.open("./data/Users/" + to_string(AccountNumber) + ".txt");
    if (!Userfile.is_open()) {
        return "";
    }
    string data;
    string value;
    while (getline(Userfile, data)) {
        int position = data.find(key);
        if (position != string::npos) {
            int idx = data.find(":");
            return data.substr(idx + 2);
        }
    }
    return "";
};

void saveUserDetails(string Fname, string Lname, string email, string password, string phoneNo,long long AccountNumber) {
    ofstream UserFile;
    UserFile.open("./data/Users/" + to_string(AccountNumber) + ".txt");

    if (!UserFile.is_open()) {
        cout << "Error in Saving Info!" << endl;
        return;
    }

    UserFile << "Fname : " << Fname << '\n';
    UserFile << "Lname : " << Lname << '\n';
    UserFile << "Email : " << email << '\n';
    UserFile << "PhoneNo : " << phoneNo << '\n';
    UserFile << "AccountNo : " << AccountNumber << '\n';
    UserFile << "Password : " << password << '\n';
    UserFile.close();

    saveLastAccountNumber(AccountNumber);
    
}

void createStatement(long long accountNumber, string type, double amount) {}
}  // namespace helper