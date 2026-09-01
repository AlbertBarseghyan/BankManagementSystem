#include "../include/Account.h"
#include "../include/Customer.h"
#include "../include/Transaction.h"
#include "../include/Bank.h"

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

    Bank bank;

    Customer customer2(
        505,
        "John",
        "+37458965474",
        "john@mail.ru"
    );

    bank.addCustomer(customer);
    bank.addCustomer(customer2);

    Customer* foundCustomer = bank.findCustomer(505);
    if(foundCustomer != nullptr){
        std::cout << "\nCustomer found: " << foundCustomer -> getName() << std::endl;
    }
    else{
        std::cout << "\n Customer not found" << std::endl;
    }

    
    Customer customer3(
        600,
        "Albert",
        "+37493241079",
        "barseghyan503@mail.ru"
    );
    Account account3(
        2001,
        "Albert",
        50000
    );

    customer3.addAccount(account3);
    bank.addCustomer(customer3);

    bool depositSuccess = bank.deposit(
        600,
        2001,
        20000

    );

    std::cout << "\nDeposit success: " << depositSuccess << std::endl;

    Customer* foundCustomer3 = bank.findCustomer(600);
    if(foundCustomer3 != nullptr){
        Account* foundAccount = foundCustomer3 -> findAccount(2001);

        if(foundAccount != nullptr){
            std::cout << "Balance after deposit: " << foundAccount -> getBalance() << std::endl;
        }
    }

bool withdrawSuccess = bank.withdraw(
    600,
    2001,
    15000
);

std::cout << "\nWithdraw success: " << withdrawSuccess << std::endl;

Customer* withdrawCustomer = bank.findCustomer(600);

if(withdrawCustomer != nullptr){
    Account* withdrawAccount = withdrawCustomer -> findAccount(2001);

    if(withdrawAccount != nullptr){
        std::cout << "Balance after withdraw: " << withdrawAccount -> getBalance() << std::endl;
    }
}

bool failedWithdraw = bank.withdraw(
    600,
    2001,
    100000
);

std::cout << "Large withdraw success: "
          << failedWithdraw
          << std::endl;

std::cout <<"\n--- Transaction History ---" << std::endl;

bool transferSuccess = bank.transfer(
    600,
    2001,
    504,
    1001,
    1000
);

std::cout << "\nTransfer success: " << transferSuccess << std::endl;

Customer* sender = bank.findCustomer(600);
Customer* receiver = bank.findCustomer(504);

if(sender != nullptr && receiver != nullptr){
    Account* senderAccount = sender -> findAccount(2001);
    Account* receiverAccount = receiver->findAccount(1001);

    if(senderAccount != nullptr && receiverAccount != nullptr){
      std::cout << "Sender balance: " << senderAccount -> getBalance() << std::endl;
      std::cout << "Reseiver balance: " << receiverAccount -> getBalance() << std::endl;    
    }
}

for(const Transaction& transaction : bank.getTransaction()){
    
    std::cout << "Transaction ID: " << transaction.getId() << std::endl;

    std::cout << "Account ID: " << transaction.getAccountId() << std::endl;

    std::cout << "Amount: " << transaction.getAmount() << std::endl;

    std::cout << "Type: ";

    if(transaction.getType() == TransactionType::Deposit){
        std::cout << "Deposit";
    }
    else if(transaction.getType() == TransactionType::Withdraw){
        std::cout << "Withdraw";
    }
    else if(transaction.getType() == TransactionType::Transfer){
        std::cout << "Transfer";
    }
    std::cout << std::endl;
    std::cout << "--------------------" << std::endl;
}

bool saveSuccess = bank.saveAccountsToFile("data/accounts.txt");

if(saveSuccess){
    std::cout << "\nAccounts saved successfully" << std::endl;
}
else{
    std::cout << "\nFailed to save accounts" << std::endl;
}

std::cout << "\n--- loading accounts from file ---" << std::endl;

Bank loadedBank;

bool loadSuccess = loadedBank.loadAccountsFromFile(
    "data/accounts.txt"
);

if(loadSuccess){
    std::cout << "Accounts loaded successfully" << std::endl;
}
else{
    std::cout << "Failed to load accounts" << std::endl;
}

Customer* loadedCustomer = loadedBank.findCustomer(504);

if(loadedCustomer != nullptr){
    std::cout << "Loaded customer: " << loadedCustomer -> getName() << std::endl;

    for(const Account& account : loadedCustomer -> getAccounts()){
        std::cout << "Loaded Account ID: " << account.getId() << std::endl;

        std::cout << "Loaded Balance: " << account.getBalance() << std::endl;
    }
}
else{
    std::cout << "loaded customer not found" << std::endl;
}

return 0;

}