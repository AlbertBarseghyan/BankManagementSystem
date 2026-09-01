#include "../include/Bank.h"
#include <fstream>
#include <sstream>

void Bank::addCustomer(const Customer& customer){
    customers.push_back(customer);
}

Customer* Bank::findCustomer(int customerId){
    for(Customer& customer : customers){
        if(customer.getId() == customerId){
            return &customer;
        }
    }
    return nullptr;
}

bool Bank::deposit(int customerId, int accountId, double amount){
    Customer* customer = findCustomer(customerId);

    if(customer == nullptr){
        return false;
    }

    Account* account = customer -> findAccount(accountId);

    if(account == nullptr){
        return false;
    }

    if(!account -> isActive() || amount <= 0){
        return false;
    }

    account -> deposit(amount);

    transaction.push_back(
        Transaction(
            nextTransaction,
            accountId,
            TransactionType::Deposit,
            amount
        )
    );

    nextTransaction++;

    return true;

}

bool Bank::withdraw(int customerId, int accountId, double amount){

    Customer* customer = findCustomer(customerId);

    if(customer == nullptr){
        return false;
    }

    Account* account = customer -> findAccount(accountId);

    if(account == nullptr)
    {
        return false;
    }

    if(!account -> withdraw(amount)){
        return false;
    }

    transaction.push_back(
        Transaction(
            nextTransaction,
            accountId,
            TransactionType::Withdraw,
            amount
        )
    );

    nextTransaction++;
    return true;
}

const std::vector<Transaction>& Bank::getTransaction() const {

    return transaction;

}

bool Bank::transfer(
    int fromCustomerId,
    int fromAccountId,
    int toCustomerId,
    int toAccountId,
    double amount
)
{
    Customer* fromCustomer = findCustomer(fromCustomerId);

    if(fromCustomer == nullptr){
        return false;
    }

    Customer* toCustomer = findCustomer(toCustomerId);

    if(toCustomer == nullptr){
        return false;
    }

    Account* fromAccount = fromCustomer->findAccount(fromAccountId);

    if(fromAccount == nullptr){
        return false;
    }

    Account* toAccount = toCustomer->findAccount(toAccountId);

    if(toAccount == nullptr){
        return false;
    }

    if(!fromAccount->isActive() || !toAccount->isActive()){
        return false;
    }

    if(amount <= 0){
        return false;
    }

    if(!fromAccount->withdraw(amount)){
        return false;
    }

    toAccount->deposit(amount);

    transaction.push_back(
        Transaction{
            nextTransaction,
            fromAccountId,
            TransactionType::Transfer,
            amount
        }
    );

    nextTransaction++;

    return true;
}

bool Bank::saveAccountsToFile(const std::string& filename) const {
    std::ofstream file(filename);

    if(!file.is_open()){
        return false;
    }

    for(const Customer& customer : customers){
        for(const Account& account : customer.getAccounts()){
            file << customer.getId() << ","
            << account.getId() << ","
            << account.getHolderName() << ","
            << account.getBalance() << ","
            << account.isActive()
            << "\n";
        }
    }
    file.close();

    return true;
}
 
bool Bank::loadAccountsFromFile(const std::string& filename){
    std::ifstream file(filename);

    if(!file.is_open()){
        return false;
    }

    std::string line;

    while(std::getline(file, line)){
        std::stringstream ss(line);

        std::string customerIdStr;
        std::string accountIdStr;
        std::string holderName;
        std:: string balanceStr;
        std::string activeStr;

        std::getline(ss, customerIdStr, ',');
        std::getline(ss, accountIdStr, ',');
        std::getline(ss, holderName, ',');
        std::getline(ss, balanceStr, ',');
        std::getline(ss, activeStr, ',');

        int customerId = std::stoi(customerIdStr);
        int accountId = std::stoi(accountIdStr);
        double balance = std::stod(balanceStr);
        bool active = std::stoi(activeStr);

        Customer* customer = findCustomer(customerId);

        if(customer == nullptr){
            Customer newCustomer(
                customerId,
                holderName,
                "",
                ""
            );

            addCustomer(newCustomer);

            customer = findCustomer(customerId);
        }

        if(customer != nullptr){
            Account account(
                accountId,
                holderName,
                balance
            );
            if(!active){
                account.deactivate();
            }

            customer -> addAccount(account);
        }
    }
    file.close();

    return true;
}