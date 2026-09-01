#include "../include/Account.h"
#include <iostream>

int main(){

Account account(1001, "Albert", 50000);

std::cout << "Initial Balance: " << account.getBalance() << std::endl;

account.deposit(10000);

std::cout << " After deposit: " << account.getBalance() << std::endl;

bool success = account.withdraw(20000);

std::cout << " Withdraw Success: " << success << std::endl;

std::cout<<" After Withdraw: " << account.getBalance() << std::endl;

account.deactivate();
account.deposit(10000);

std::cout<< " After deposit to inactive Account: " << account.getBalance() << std::endl;

return 0;

}