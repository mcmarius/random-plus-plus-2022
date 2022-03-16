/*
test
*/
//
// Created by marius on 2022-03-16.
//

#ifndef OOP_MAGAZIN_H
#define OOP_MAGAZIN_H

#include <string>
#include <vector>
#include <ostream>
#include "Accesoriu.h"

class Magazin {
    std::string nume;
    std::vector<Accesoriu> accesorii;
public:
    Magazin(const std::string &nume);
    friend std::ostream &operator<<(std::ostream &os, const Magazin &magazin);
    void adauga(const Accesoriu& acc);
};

#endif //OOP_MAGAZIN_H
