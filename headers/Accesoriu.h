/*
test
*/
//
// Created by marius on 2022-03-16.
//

#ifndef OOP_ACCESORIU_H
#define OOP_ACCESORIU_H

#include <string>
#include <ostream>

class Accesoriu {
    std::string nume;
    int pret;
public:
    Accesoriu(const std::string &nume, int pret);

    Accesoriu(const std::string &nume);
    friend std::ostream &operator<<(std::ostream &os, const Accesoriu &produs);
    ~Accesoriu();
};


#endif //OOP_ACCESORIU_H
