/*
test
*/
//
// Created by marius on 2022-03-16.
//

#include <iostream>
#include "headers/Accesoriu.h"

Accesoriu::Accesoriu(const std::string &nume, int pret) : nume(nume), pret(pret) {
    std::cout << "constr acc " << *this << "\n";
}

Accesoriu::Accesoriu(const std::string &nume) : nume(nume) {}

std::ostream &operator<<(std::ostream &os, const Accesoriu &accesoriu) {
    os << "nume: " << accesoriu.nume << " pret: " << accesoriu.pret;
    return os;
}

Accesoriu::~Accesoriu() {
    std::cout << "destr acc " << *this << "\n";
}
