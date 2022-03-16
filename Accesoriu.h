/*
test
*/
//
// Created by marius on 2022-03-16.
//

#ifndef OOP_ACCESORIU_H
#define OOP_ACCESORIU_H

#include <string>
#include <iostream>

class Accesoriu {
    std::string nume;
    int pret;
public:
    Accesoriu(const std::string &nume, int pret);
    explicit Accesoriu(const std::string &nume);

    virtual ~Accesoriu();
    friend std::ostream &operator<<(std::ostream &os, const Accesoriu &accesoriu);
};

#endif //OOP_ACCESORIU_H
