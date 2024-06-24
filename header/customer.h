#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer{
    int customerId{0};
    int  name;
    int contactDetails;

public:
    Customer(std::string, int);
    void loadCustomer();
    void updateDetails();
    void updateCustomerFile();
};
#endif