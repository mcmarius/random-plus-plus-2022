/*
test
*/
//
// Created by marius on 2022-03-16.
//

#ifndef OOP_MICROFON_H
#define OOP_MICROFON_H

#include <ostream>
#include "Accesoriu.h"

class Microfon : public Accesoriu {
public:
    enum conector { USB, USB_C, Bluetooth };
    Microfon(const std::string &nume, int pret, conector con);
    ~Microfon();
    friend std::ostream &operator<<(std::ostream &os, const Microfon &microfon);
private:
    conector con;
};

#endif //OOP_MICROFON_H
