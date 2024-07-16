#include "../header/customer.h"
#include<string>
#include<vector>
#include<iostream>
Customer::Customer(std::string cName, int number){
    customerId = customerId+1;
    name = cName;
    contactDetails = number;
}

void Customer::addCustomer(std::vecto<Customer> &customers){
    bool init{false};
    for (int i = 0; i < customers.size(); i++){
        if (customers[i].name == name) init = true;
    }
    if (!init) customers.emplace_back(customerId, name, contactDetails);
}

std::vector<Customer> Customer::loadCustomer(std::string filename){
    std::vector<Customer> customers;
    std::ifstream file(filename);
    std::string line;
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string token;
        
        int customerID;
        std::string name;
        long int number;
        std::getline(ss, token, ',');
        customerId = std::stoi(token);
        std::getline(ss, name, ',');
        std::getline(ss, token, ',');
        number = std::stol(token);
        customers.emplace_back(customer(customerId, name, number));
    }
    
    return customers;
}


void Customer::updateDetails(){
    std::vector<Customer> customers;
    int number;
    std::string new_name;
    std::string anwser;
    for (auto& customer : customers){
        if(customer.name == name && customer.contactDetails == contactDetails){
            std::cout << "\nName: " << customer.name;
            std::cout << "\nPhone number: " << customer.contactDetails;
            std::cout << "\nwould you like to edit anything? (YES/NO)";
            std::cin >> anwser;
            anwser = std::lower(anwser);
            if (anwser = "yes"){
                std::cout << "\nType in your new name or existing name";
                std::cin >> new_name;
                new_name = std::lower(new_name);
                customer.name = new_name;
                std::cout << "\nType in your new phone number";
                std::cin >> number;
                customer.contactDetails = number;
                std::cout << "\ncontsct successfully changed";
            }
        }
    }
}


void Customer::updateCustomerFile(std::vector<Customer> &customers){
    std::ofstream outfile;
    outfile.open("customer.csv");
    outfile << "customerId,name,number\n";
    for (auto& customer : customers){
        outfile << customer.customerId << "," 
        << customer.name << ','
        << customer.number;
    }
}