/*
test
*/
//
// Created by marius on 2022-03-16.
//

#ifndef OOP_INCARCATOR_H
#define OOP_INCARCATOR_H

#include "Accesoriu.h"

class Incarcator : public Accesoriu {
public:
    Incarcator(const std::string &nume, int pret);
    ~Incarcator() {
        std::cout << "destr incarcator " << *this << "\n";
    }
};

#endif //OOP_INCARCATOR_H
