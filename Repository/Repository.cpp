//
// Created by ANDREI on 25-May-24.
//

#include "Repository.h"
#include <fstream>
#include <algorithm>

Repository::Repository(std::string filename) : filename{filename}{
    this->read_from_file(filename);
    this->sort_by_name();
}

void Repository::read_from_file(std::string filename) {
    std::ifstream fin("../" + filename);
    std::string line;

    std::string name;
    std::string serial;
    double sum;
    std::string paidstr;
    bool isPaid;

    std::string delim = ",";
    while(std::getline(fin, line)){
        name = line.substr(0,line.find(delim));
        line.erase(0, line.find(delim) + delim.length());
        serial = line.substr(0, line.find(delim));
        line.erase(0, line.find(delim) + delim.length());
        sum = std::stod(line.substr(0, line.find(delim)));
        line.erase(0, line.find(delim) + delim.length());
        paidstr = line;
        if(paidstr == "false")
            isPaid = false;
        else
            isPaid = true;
        auto b = new Bill(name, serial, sum, isPaid);
        v.push_back(*b);
    }
}

void Repository::sort_by_name() {
    for (int i = 0; i < v.size()-1; i ++)
        for(int j = i+1; j < v.size(); j++)
            if(this->v[i].get_name() > this->v[j].get_name())
                std::swap(v[i],v[j]);
}

std::vector<Bill> Repository::get_list() {
    return this->v;
}

std::pair<std::vector<Bill>, std::vector<Bill>> Repository::filter_paid() {
    std::vector<Bill> unpaid;
    std::vector<Bill> paid;
    for(auto b : this->v){
        if (b.check_paid())
            paid.push_back(b);
        else
            unpaid.push_back(b);
    }
    std::pair<std::vector<Bill>, std::vector<Bill>> pair;
    pair.first = unpaid;
    pair.second = paid;
    return pair;
}

std::vector<Bill> Repository::filter_by_name(std::string name) {
    std::vector<Bill> newlist;
    for(auto b : this->v){
        if(b.get_name() == name)
            newlist.push_back(b);
    }
    return newlist;
}