#include "../header/customer.h"
#include<string>
#include<vector>
Customer::Customer(std::string cName, int number){
    customerId = customerId+1;
    name = cName;
    contactDetails = number;
}


std::vector<Customer> Customer::loadCustomer(){
    std::vector<Customer> customers;
}