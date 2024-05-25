//
// Created by ANDREI on 25-May-24.
//

#include "Bill.h"


Bill::Bill(std::string company_name, std::string serial_num, double sum, bool isPaid) {
    this->company_name = company_name;
    this->serial_num = serial_num;
    this->sum = sum;
    this->isPaid = isPaid;
}

bool Bill::check_paid() {
    return this->isPaid;
}

std::string Bill::get_name() {
    return this->company_name;
}

std::string Bill::get_serial() {
    return this->serial_num;
}

double Bill::get_sum() {
    return this->sum;
}