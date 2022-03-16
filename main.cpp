
#include <string>
#include <ostream>
#include "Incarcator.h"
#include "Magazin.h"

//#pragma pack(1)

using namespace std::string_literals;

class Vanzator {
    std::string nume;
    int vechime;
public:
    Vanzator(const std::string &nume, int vechime);
    friend std::ostream &operator<<(std::ostream &os, const Vanzator &vanzator);
};

Vanzator::Vanzator(const std::string &nume, int vechime) : nume(nume), vechime(vechime) {}

std::ostream &operator<<(std::ostream &os, const Vanzator &vanzator) {
    os << "nume: " << vanzator.nume << " vechime: " << vanzator.vechime;
    return os;
}

//class Priza {};

void f([[maybe_unused]]Magazin m) {
    std::cout << "mag\n";
}
void f([[maybe_unused]]Accesoriu s) {
    std::cout << "acc\n";
}

void g(Accesoriu) {
    std::cout << "g\n";
}

class baza1 {
    char x;
};
class derivata1 : public baza1 {
    short z;
    short u;
};

class baza2 {
public:
    virtual ~baza2() = default;
};
class derivata2 : public baza2 {};



int main() {
    std::cout << "size baza1: " << sizeof(baza1) << "\n";
    std::cout << "size derivata1: " << sizeof(derivata1) << "\n";
    std::cout << "size baza2: " << sizeof(baza2) << "\n";
    std::cout << "size derivata2: " << sizeof(derivata2) << "\n";
    Vanzator v{"asd", 3};
    std::cout<<v << "\n";
    f(Accesoriu{"asd"s});
    f(Magazin{"asd"s});
    g({"asd", 23});
//    Priza p;
    Incarcator usb{"asd"s, 123};
//    Magazin m{"asd"s} ;
//    m.modifica(m);
    return 0;
}
