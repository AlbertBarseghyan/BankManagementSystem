#include "../include/Customer.h"

Customer::Customer(int id,const std::string& name, const std::string& phone, const std::string& email)
{
    this->id = id;
    this->name = name;
    this->phone = phone;
    this->email = email;
}

int Customer::getId() const {
    return id;
}
std::string Customer::getName() const {
    return name;
}
std::string Customer::getPhone() const {
    return phone;
}
std::string Customer::getEmail() const {
    return email;
}

void Customer::setPhone(const std::string& phone){
    this -> phone = phone;
}
void Customer::setEmail(const std::string& email){
    this -> email = email;
}
void Customer::addAccount(const Account& account){
    accounts.push_back(account);
}

const std::vector<Account>& Customer::getAccounts() const {
    return accounts;
}