#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer{
    int customerId;
    int  name;
    int contactDetails;

public:
    Customer();
    void loadCustomer();
    void updateDetails();
};
#endif