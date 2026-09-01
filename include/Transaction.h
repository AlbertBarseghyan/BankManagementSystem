#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

enum class TransactionType{
    Deposit,
    Withdraw,
    Transfer
};

class Transaction{
    private:
    int id;
    int accountId;
    TransactionType type;
    double amount;

    public:
    Transaction(int id, int accountId, TransactionType type, double amount);

    int getId() const;
    int getAccountId() const;
    TransactionType getType() const;
    double getAmount() const;
};

#endif