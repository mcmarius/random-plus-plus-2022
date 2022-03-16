/*
test
*/
//
// Created by marius on 2022-03-16.
//

#ifndef OOP_MAGAZIN_H
#define OOP_MAGAZIN_H

#include <vector>
#include "Accesoriu.h"

class Magazin {
    std::vector<Accesoriu> accesorii;
    std::string nume;
public:
    explicit Magazin(const std::string &nume);
    void adauga(const Accesoriu& produs);
//    void modifica(Magazin m) {
//        m.adauga(..);
//        this->adauga(...);
//    }
};

#endif //OOP_MAGAZIN_H
