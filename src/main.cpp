#include "../include/Account.h"
#include <iostream>

int main(){

Account account(1001, "Albert", 50000);

std::cout << "ID - " << account.getId() << std::endl;
std::cout << "Name - " << account.getHolderName() << std::endl;
std::cout << "Balance - " << account.getBalance() << std::endl;

account.deposit(10000);

std::cout<< "after deposit: " <<account.getBalance() << std::endl;

return 0;

}