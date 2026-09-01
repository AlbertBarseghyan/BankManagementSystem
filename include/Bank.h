#ifndef BANK_H
#define BANK_H

#include <vector>

#include "Customer.h"
#include "Transaction.h"

class Bank{
private:
    std::vector<Customer> customers;
    std::vector<Transaction> transaction;
    int nextTransaction = 1;

public:
    void addCustomer(const Customer& customer);

    const std::vector<Transaction>& getTransaction() const;

    bool transfer(
        int fromCustomerId,
        int fromAccountId,
        int toCustomerId,
        int toAccountId,
        double amount
    );

    Customer* findCustomer(int customerId);

    bool deposit(int customerId, int accountId, double amount);
    bool withdraw(int customerId, int accountId, double amount);
};

#endif