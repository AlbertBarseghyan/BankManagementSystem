#include "../include/Account.h"

Account::Account(int id, const std::string& holderName, double balance)
{
    this->id = id;
    this->holderName = holderName;
    this->balance = balance;
    this->active = true;
}

int Account::getId() const
{
    return id;
}

std::string Account::getHolderName() const
{
    return holderName;
}

double Account::getBalance() const
{
    return balance;
}

bool Account::isActive() const
{
    return active;
}

void Account::deposit(double amount)
{
    if (amount > 0)
    {
        balance += amount;
    }
}

bool Account::withdraw(double amount)
{
    if (amount <= 0)
    {
        return false;
    }

    if (amount > balance)
    {
        return false;
    }

    balance -= amount;
    return true;
}

void Account::deactivate()
{
    active = false;
}

void Account::activate()
{
    active = true;
}