#include "../include/Account.h"
#include "../include/Customer.h"

#include <iostream>

int main(){

    Account account(1001, "Albert", 50000);

    std::cout << "Account Holder: " << account.getHolderName() << std::endl;

    std::cout << " Balance: " << account.getBalance() << std::endl;

    Customer customer{
        504,
        "Albert",
        "+37493241079",
        "barseghyan@mail.ru"
    };

    std::cout << "\n Customer ID: " << customer.getId() << std::endl;
    std::cout << "\n Customer Name: " << customer.getName() << std::endl;
    std::cout << "\n Customer Phone: " << customer.getPhone() << std::endl;
    std::cout << "\n Customer Email: " << customer.getEmail() << std::endl;

    customer.setPhone("+37498546543");

    std::cout << "New Phone: " << customer.getPhone() << std::endl;

return 0;

}