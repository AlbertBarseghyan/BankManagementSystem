#include "../include/Bank.h"

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