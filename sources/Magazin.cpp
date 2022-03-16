/*
test
*/
//
// Created by marius on 2022-03-16.
//

#include "../headers/Magazin.h"

Magazin::Magazin(const std::string &nume) : nume(nume) {}

std::ostream &operator<<(std::ostream &os, const Magazin &magazin) {
    os << "nume: " << magazin.nume << " accesorii: ";
    for(const auto& acc : magazin.accesorii) {
        os << acc;
    }
    return os;
}

void Magazin::adauga(const Accesoriu &acc) {
    accesorii.push_back(acc);
}
