#include "../include/Transaction.h"

Transaction::Transaction(int id, int accountId, TransactionType type, double amount){
    this -> id =id;
    this -> accountId = accountId;
    this -> type = type;
    this -> amount = amount;
}

int Transaction::getId() const {
    return id;
}
int Transaction::getAccountId() const {
    return accountId;
}
TransactionType Transaction::getType() const {
    return type;
}
double Transaction::getAmount() const {
    return amount;
}