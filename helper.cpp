#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

namespace helper {

long long int getLastAccount() {
    ifstream lastAccNum("./data/lastAccNum.txt");
    if (!lastAccNum) {
        cout<<"lastAccNum.txt file missing inside data/ !";
        return 1784512845;
    }
    long long int AccNum;
    lastAccNum >> AccNum;
    lastAccNum.close();
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
        size_t position = data.find(key);
        if (position != string::npos) {
            size_t colonPos = data.find(":");
            if (colonPos != string::npos && colonPos + 2 < data.size()) {
                return data.substr(colonPos + 2);
            }
        }
    }

    Userfile.close();
    return "";
};

bool updateValue(long long accountNumber, string key, string value) {
    string path = "./data/Users/" + to_string(accountNumber) + ".txt";
    fstream file(path, ios::in);

    if (!file.is_open()) {
        cout << "Failed To Update!\n";
        return false;
    }

    vector<string> lines;
    string line;

    while (getline(file, line)) {
        size_t pos = line.find(key + " : ");
        if (pos != string::npos) {
            line = key + " : " + value;
        }
        lines.push_back(line);
    }
    file.close();

    // Re-open for writing (truncate old content)
    ofstream outFile(path, ios::out | ios::trunc);
    if (!outFile.is_open()) {
        cout << "Failed To Update!\n";
        return false;
    }

    for (const string& l : lines) {
        outFile << l << "\n";
    }

    outFile.close();
    return true;
}

long long saveUserDetails(string Fname, string Lname, string email, string password, string phoneNo, long long AccountNumber) {
    ofstream UserFile;
    UserFile.open("./data/Users/" + to_string(AccountNumber) + ".txt");

    if (!UserFile.is_open()) {
        cout << "Error in Saving Info!" << endl;
        return 0;
    }

    UserFile << "Fname : " << Fname << '\n';
    UserFile << "Lname : " << Lname << '\n';
    UserFile << "Email : " << email << '\n';
    UserFile << "PhoneNo : " << phoneNo << '\n';
    UserFile << "AccountNo : " << AccountNumber << '\n';
    UserFile << "Password : " << password << '\n';
    UserFile << "Balance : " << 0 << '\n';
    UserFile.close();

    saveLastAccountNumber(AccountNumber);
    return AccountNumber;
}

void createStatement(long long accountNumber, string type, double amount) {
    ofstream file("./data/Statements/" + to_string(accountNumber) + ".txt", ios::app);
    if (!file) {
        cout << "Error in Depositing Money!";
        return;
    }
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    ostringstream oss;
    oss << std::put_time(std::localtime(&now_time), "%Y-%m-%d");
    string date = oss.str();
    file << left << setw(15) << ("[" + date + "]") << setw(10) << amount << "  " << type << '\n';

    file.close();
    return;
}

void generateStatementTempelate(long long accountNumber) {
    ofstream file("./data/Statements/" + to_string(accountNumber) + ".txt");
    string Fname = helper::getValue(accountNumber, "Fname");
    string Lname = helper::getValue(accountNumber, "Lname");
    string email = helper::getValue(accountNumber, "Email");
    string phoneNo = helper::getValue(accountNumber, "PhoneNo");
    if (!file || !Fname.length()) {
        return;
    }
    file << "==============================================\n";
    file << "            BANK ACCOUNT STATEMENT\n";
    file << "==============================================\n\n";
    file << "Account Holder :      " << Fname << " " << Lname << "\n";
    file << "Account Number :      " << accountNumber << "\n";
    file << "Phone Number   :      " << phoneNo << "\n";
    file << "Email          :      " << email << "\n\n";
    file << "-------------------------------------------\n";
    file << left << setw(15) << "DATE" << setw(10) << "AMOUNT" << "  TYPE\n";
    file << "-------------------------------------------\n";

    file.close();
}

}  // namespace helper