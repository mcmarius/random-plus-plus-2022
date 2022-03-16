/*
test
*/
//
// Created by marius on 2022-03-16.
//

#include <iostream>
#include "../headers/Microfon.h"

Microfon::~Microfon() {
    std::cout << "destr microfon " << *this << "\n";
}

Microfon::Microfon(const std::string &nume, int pret, Microfon::conector con) : Accesoriu(nume, pret), con(con) {
    std::cout << "constr microfon " << *this << "\n";
}

std::ostream& operator<<(std::ostream& os, Microfon::conector con) {
    switch(con) {
        case Microfon::USB:
            os << "USB";
            break;
        case Microfon::USB_C:
            os << "USB C";
            break;
        case Microfon::Bluetooth:
            os << "Bluetooth";
            break;
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const Microfon &microfon) {
    os << static_cast<const Accesoriu &>(microfon) << " con: " << microfon.con;
//    os << microfon.pret
    return os;
}
