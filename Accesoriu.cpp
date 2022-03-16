/*
test
*/
//
// Created by marius on 2022-03-16.
//

#include "Accesoriu.h"

Accesoriu::Accesoriu(const std::string &nume, int pret) : nume(nume), pret(pret) {
    std::cout << "constr acc " << *this << "\n";
}

Accesoriu::~Accesoriu() {
    std::cout << "destr acc " << *this << "\n";
}



Accesoriu::Accesoriu(const std::string &nume) : nume(nume) {
    if(nume.starts_with("promotie"))
        pret = 10;
}

std::ostream &operator<<(std::ostream &os, const Accesoriu &accesoriu) {
    os << "nume: " << accesoriu.nume << " pret: " << accesoriu.pret;
    return os;
}
