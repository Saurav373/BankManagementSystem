#include <fstream>
#include <iostream>
using namespace std;

namespace helper {
long long int getLastAccount() {
    ifstream lastAccNum("./data/lastAccNum.txt");
    long long int AccNum;
    lastAccNum >> AccNum;
    return AccNum;
}
void saveLastAccountNumber(long long AccountNo) {
    ofstream file("./data/lastAccNum.txt");
    file << AccountNo;
    file.close();
};

bool verifyUser(long long AccountNumber,string password){
    ifstream Userfile;
    Userfile.open("./data/Users/"+to_string(AccountNumber)+".txt");
    if(!Userfile.is_open()){
        return false;
    }
    string data;
    string findKey = "Password";
    string passwordValue;
    while(getline(Userfile,data)){
        int position = data.find(findKey);
        if(position!=string::npos){
            int idx = data.find(":");
            passwordValue = data.substr(idx+2);
        }
    }
    if(password == passwordValue){
        return true;
    }
    return false;

}

} 