#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account{
    private:
    int id;
    std::string holderName;
    double balance;
    bool active;

    public:
    Account(int id, const std::string& holderName , double balance);

    int getId() const;
    std::string getHolderName() const;
    double getBalance() const;
    bool isActive() const;

    void deposit(double amount);
    bool withdraw(double amount);

    void deactivate();
    void activate();
};

#endif