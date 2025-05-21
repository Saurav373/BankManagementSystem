#include <iostream>
#include <fstream>
using namespace std;

static int CurrAccNumber = 3623773;
class BankSystem
{
private:
    string phoneNo;
    string email;
    string password;
    double balance;
    int AccountNumber;

    void saveUserDetails()
    {
        //! Save Last Accessed Account Number in a file ~ deconstructor
        this->AccountNumber = ++CurrAccNumber;
        this->balance = 0.0;

        ofstream UserFile;
        UserFile.open("./data/Users/" + to_string(this->AccountNumber) + ".txt");
        UserFile << "Fname : " << Fname << '\n';
        UserFile << "Lname : " << Lname << '\n';
        UserFile << "Email : " << email << '\n';
        UserFile << "PhoneNo : " << phoneNo << '\n';
        UserFile << "AccountNo : " << AccountNumber << '\n';
        UserFile << "Password : " << password << '\n';
        UserFile.close();
    }

public:
    string Fname;
    string Lname;

    BankSystem(string Fname, string Lname, string phoneNo, string email, string password)
    {
        this->Fname = Fname;
        this->Fname = Fname;
        this->Lname = Lname;
        this->phoneNo = phoneNo;
        this->email = email;
        this->password = password;
    }

    string registerUser()
    {
        if (!this->Fname.length())
            return "First Name Required!";
        if (!this->Lname.length())
            return "Last Name Required!";
        if (!this->email.length())
            return "Email Required!";
        if (!this->password.length())
            return "Password Required!";
        if (!this->phoneNo.length())
            return "PhoneNo Required!";

        saveUserDetails();
        return "Account Successfully Created";
    }
};
