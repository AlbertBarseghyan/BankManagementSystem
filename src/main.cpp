#include "../include/Account.h"
#include "../include/Customer.h"
#include "../include/Transaction.h"

#include <iostream>

int main(){

    Customer customer{
        504,
        "Albert",
        "+37493241079",
        "barseghyan@mail.ru"
    };

    Account account1(1001, "Albert", 50000);
    Account account2(1002, "Albert", 120000);
    customer.addAccount(account1);
    customer.addAccount(account2);

    std::cout << "Customer: " << customer.getName() << std::endl;

    for(const Account& account : customer.getAccounts()){
        std::cout << "Account ID: " << account.getId() << std::endl;

        std::cout << "Balance: " << account.getBalance() << std::endl;
    }

  //  std::cout << "\n Customer ID: " << customer.getId() << std::endl;
    //std::cout << "\n Customer Name: " << customer.getName() << std::endl;
    //std::cout << "\n Customer Phone: " << customer.getPhone() << std::endl;
    //std::cout << "\n Customer Email: " << customer.getEmail() << std::endl;

    //customer.setPhone("+37498546543");

    //std::cout << "New Phone: " << customer.getPhone() << std::endl;

    Transaction transaction(
        1,
        1001,
        TransactionType::Deposit,
        20000
    );

    std::cout <<"\nTransaction ID: " << transaction.getId() << std::endl;
    std::cout << "Account ID: " << transaction.getAccountId() << std::endl;
    std::cout << "Amount: " << transaction.getAmount() << std::endl;

return 0;

}