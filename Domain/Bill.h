//
// Created by ANDREI on 25-May-24.
//

#ifndef TEST3EX_BILL_H
#define TEST3EX_BILL_H
#include <string>


class Bill {
private:
    std::string company_name;
    std::string serial_num;
    double sum;
    bool isPaid;

public:
    Bill(std::string company_name, std::string serial_num, double sum, bool isPaid);
    bool check_paid();
    std::string get_name();
    std::string get_serial();
    double get_sum();
};


#endif //TEST3EX_BILL_H
