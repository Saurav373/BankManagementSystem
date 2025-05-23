#include<iostream>
#include "bankSystem.hpp"
#include "helper.hpp"
#include "userAuth.hpp"
using namespace std;

int main(){
    bankSystem::BankSystem User("Saurav","Kattel","9842447520","abc@gmail.com","123456");
    User.registerUser();
    cout<<userAuth::verifyUser(212544678,"123456");
    helper::generateStatementTempelate(User.AccountNumber);
    User.deposit(5645646,User.AccountNumber);

    return 0;
}