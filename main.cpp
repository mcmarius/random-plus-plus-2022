
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
protected:
    int x;
    baza2(const baza2&) = default;
    baza2& operator=(const baza2&) = default;
public:
    baza2() {
        std::cout << "constr baza2\n";
    }
    virtual ~baza2() {
        std::cout << "destr baza2\n";
    }
    virtual void f() {
        std::cout << "f b2\n";
    }
    virtual void g();
    virtual baza2* clone() = 0;
};

void baza2::g() {
    std::cout << "g b2\n";
}

class derivata21 : public baza2 {
public:
    baza2 *clone() override {
        return new derivata21(*this);
    }

    void g() override {
        baza2::g();
        std::cout << "g d21\n";
    }

    void f() override {
        std::cout << "f d21\n" << x;
        baza2::f();
    }
    derivata21() {
        std::cout << "constr der21\n";
    }
    ~derivata21() {
        std::cout << "destr der21\n";
    }
};

class derivata22 : public baza2 {
public:
    baza2 *clone() override {
        return new derivata22(*this);
    }

    void g() override {
        baza2::g();
        std::cout << "g d22\n";
    }

    void f() override {
        std::cout << "f d22\n" << x;
        baza2::f();
    }
    derivata22() {
        std::cout << "constr der22\n";
    }
    ~derivata22() {
        std::cout << "destr der22\n";
    }
};

class baza3 {
public:
    baza3() {
        std::cout << "constr baza3\n";
    }
    ~baza3() {
        std::cout << "destr baza3\n";
    }
};
class derivata3 : public baza3 {
public:
    derivata3() {
        std::cout << "constr der3\n";
    }
    ~derivata3() {
        std::cout << "destr der3\n";
    }
};



int main() {
//    baza2* b2 = new baza2[2];
//    delete[] b2;
//    baza3* b3 = new baza3;
//    delete b3;
//    derivata21* d2 = new derivata21;
//    delete d2;
//    derivata3* d3 = new derivata3;
//    delete d3;
//
    baza2* b21 = new derivata22;
    b21->f();
    baza2& refb2 = *b21;
    refb2.f();
    //baza2 copie(*b21);
    std::cout << "inainte de clone\n";
    baza2* copie = b21->clone();
    copie->f();
    delete b21;
    baza3* b31 = new derivata3;
    delete b31;

    return 0;
    std::cout << "size baza1: " << sizeof(baza1) << "\n";
    std::cout << "size derivata1: " << sizeof(derivata1) << "\n";
    std::cout << "size baza2: " << sizeof(baza2) << "\n";
    std::cout << "size derivata21: " << sizeof(derivata21) << "\n";
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
