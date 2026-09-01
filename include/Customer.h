#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "Account.h"

class Customer{

    private:
    int id;
    std::string name;
    std::string phone;
    std::string email;
    std::vector<Account> accounts;

    public:
    Customer(int id,const std::string& name,const std::string& phone,const std::string& email);
    void addAccount(const Account& account);
    const std::vector<Account>& getAccounts() const;

    int getId() const;
    std::string getName()  const;
    std::string getPhone() const;
    std::string getEmail() const;

    void setPhone(const std::string& phone);
    void setEmail(const std::string& email);
};

#endif