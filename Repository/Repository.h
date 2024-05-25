//
// Created by ANDREI on 25-May-24.
//

#ifndef TEST3EX_REPOSITORY_H
#define TEST3EX_REPOSITORY_H
#include "Domain/Bill.h"
#include <utility>
#include <vector>
#include <string>

class Repository {
private:
    std::vector<Bill> v;
    std::string filename;
public:
    Repository(std::string filename);
    void read_from_file(std::string filename);
    void sort_by_name();
    std::vector<Bill> get_list();
    std::pair<std::vector<Bill>, std::vector<Bill>> filter_paid();
    std::vector<Bill> filter_by_name(std::string name);
};


#endif //TEST3EX_REPOSITORY_H
