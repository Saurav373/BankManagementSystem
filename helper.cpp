#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

namespace helper {

long long int getLastAccount() {
    ifstream lastAccNum("./data/lastAccNum.txt");
    if (!lastAccNum)
        return 158694689012;
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
    Userfile.close();
    return "";
};

void updateValue(long long accountNumber, string key, string value) {
    string path = "./data/Users/" + to_string(accountNumber) + ".txt";
    fstream file(path, ios::in);

    if (!file.is_open()) {
        cout << "Failed To Update!\n";
        return;
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
        return;
    }

    for (const string& l : lines) {
        outFile << l << "\n";
    }

    outFile.close();
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
    file << left << setw(15) << "[2025-09-06]" << setw(12) << amount << type << '\n';
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
    file << "===========================================\n";
    file << "            BANK ACCOUNT STATEMENT\n";
    file << "===========================================\n\n";
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