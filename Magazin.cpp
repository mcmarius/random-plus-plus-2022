/*
test
*/
//
// Created by marius on 2022-03-16.
//

#include "Magazin.h"

Magazin::Magazin(const std::string &nume) : nume(nume) {}

void Magazin::adauga(const Accesoriu &produs) {
    accesorii.push_back(produs);
}
