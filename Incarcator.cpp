/*
test
*/
//
// Created by marius on 2022-03-16.
//

#include "Incarcator.h"

Incarcator::Incarcator(const std::string &nume, int pret) : Accesoriu(nume, pret) {
    std::cout << "constr incarcator " << *this << "\n";
}
