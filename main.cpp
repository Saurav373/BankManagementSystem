#include<iostream>
#include "bankSystem.hpp"
#include "helper.hpp"
#include "userAuth.hpp"
using namespace std;

int main(){
    bankSystem::BankSystem User;
    User.registerUser("saurav","kattel","9846615564","abc@gmail.com","123456");
    bool isLoggedIn = User.login(158694689029,"123456");
    if(isLoggedIn){
        cout<<"Login SuccessFully!"<<endl;
    }else{
        cout<<"Invalid AccountNumber or Password!"<<endl;
    }
    User.deposit(User.AccountNumber,100000000.0);
    User.withdraw(1000);
    return 0;
}