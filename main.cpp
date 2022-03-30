
#include <string>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>
//#include "Incarcator.h"
//#include "Magazin.h"

//#pragma pack(1)

//using namespace std::string_literals;

//struct asd1 {
//    int x;
//    char z;
//};

//class Vanzator {
//    std::string nume;
//    int vechime;
//public:
//    Vanzator(const std::string &nume, int vechime);
//    friend std::ostream &operator<<(std::ostream &os, const Vanzator &vanzator);
//};
//
//Vanzator::Vanzator(const std::string &nume, int vechime) : nume(nume), vechime(vechime) {}
//
//std::ostream &operator<<(std::ostream &os, const Vanzator &vanzator) {
//    os << "nume: " << vanzator.nume << " vechime: " << vanzator.vechime;
//    return os;
//}

//class Priza {};

//void f([[maybe_unused]]Magazin m) {
//    std::cout << "mag\n";
//}
//void f([[maybe_unused]]Accesoriu s) {
//    std::cout << "acc\n";
//}
//
//void g(Accesoriu) {
//    std::cout << "g\n";
//}

class baza1 {
    char x;
};
class derivata1 : public baza1 {
    short z;
    short u;
};

class baza3_0 {
public:
    enum tip {der3_0, der3_01};
    baza3_0() {
        std::cout << "constr baza3_0\n";
    }
    virtual ~baza3_0() {
        std::cout << "destr baza3_0\n";
    }
};
class derivata3_0 : public baza3_0 {
public:
    derivata3_0() {
        std::cout << "constr der3_0\n";
    }
    ~derivata3_0() override {
        std::cout << "destr der3_0\n";
    }
    void g() {
        std::cout << "g der3_0\n";
    }
};
class derivata3_01 : public baza3_0 {
    int x;
public:
    derivata3_01() : x{5} {
        std::cout << "constr der3_01\n";
    }
    ~derivata3_01() override {
        std::cout << "destr der3_01\n";
    }
    void f() {
        std::cout << x << " f der3_01\n";
    }
};

class baza2 {
protected:
    int x = 5;
    baza2(const baza2&) = default;
    baza2& operator=(const baza2&) = default;
    virtual void afisare(std::ostream& os) const = 0;
public:
    friend std::ostream &operator<<(std::ostream &os, const baza2 &baza2);

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
    virtual std::shared_ptr<baza2> clone() const = 0;
};

void baza2::afisare(std::ostream &os) const {
    auto& baza2 = *this;
    os << "x: " << baza2.x;
}

void baza2::g() {
    std::cout << "g b2\n";
}

std::ostream &operator<<(std::ostream &os, const baza2 &baza2) {
    baza2.afisare(os);
    return os;
}

class derivata21 : public baza2 {
    int z{5};
public:
    [[nodiscard]] std::shared_ptr<baza2> clone() const override {
        return std::make_shared <derivata21>(*this);
    }

    void afisare(std::ostream &os) const override {
        baza2::afisare(os);
        os << z << "\n";
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
    [[nodiscard]] std::shared_ptr<baza2> clone() const override {
        return std::make_shared <derivata22>(*this);
    }

protected:
    void afisare(std::ostream &os) const override {
        baza2::afisare(os);
    }

public:
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

class baza3_1 {
public:
    baza3_1() {
        std::cout << "constr baza3_1\n";
    }
    ~baza3_1() {
        std::cout << "destr baza3_1\n";
    }
};

class derivata3 : public baza3_1 {
public:
    derivata3() {
        std::cout << "constr der3\n";
    }
    ~derivata3() {
        std::cout << "destr der3\n";
    }
};

class colectie {
    std::vector<std::shared_ptr<baza2>> chestii;
public:
    colectie(std::vector <std::shared_ptr <baza2>> chestii) : chestii(std::move(chestii)) {}

    void adauga(baza2& ob) {
        chestii.emplace_back(ob.clone());
    }
    colectie(const colectie& other) {
        for(const auto& chestie : other.chestii)
            chestii.push_back(chestie->clone());
    }
    friend void swap(colectie& c1, colectie& c2) {
        using std::swap;
        swap(c1.chestii, c2.chestii);
    }

    colectie& operator=(const colectie& other) {
        auto copie{other};
        swap(copie, *this);
        return *this;
    }

    void fa_de_toate() {
        for(auto& chestie : chestii)
            chestie->f();
    }
};

class my_exceptie : public std::runtime_error {
public:
    explicit my_exceptie(const std::string &arg) : runtime_error(arg) {}
};

class eroare_server : public my_exceptie {
public:
    explicit eroare_server(const std::string &arg) : my_exceptie(arg) {}
};

class eroare_client : public my_exceptie {
public:
    explicit eroare_client(const std::string &arg) : my_exceptie(arg) {}
};

void f2() {
    std::cout << "f2 inainte\n";
    throw eroare_client("eroare f2");
    std::cout << "f2 dupa\n";
}

void f1() {
    std::cout << "f1 inainte\n";
    try {
        f2();
        throw eroare_server{"hopa"};
    } catch (my_exceptie& err) {
        std::cout << "catch logic err\n" << err.what();
    }
    std::cout << "f1 dupa\n";
}

int main() {
    //f1();
    try {
        std::cout << "inainte throw main" << "\n";
        f1();
        std::cout << "dupa throw main" << "\n";
    } catch (std::runtime_error& err) {
        std::cout << err.what() << "\n";
    }
    colectie c1({std::make_shared <derivata21>(), std::make_shared <derivata22>()});
    c1.fa_de_toate();
    derivata21 d1;
    c1.adauga(d1);
    c1.fa_de_toate();

    std::cout << sizeof(baza3_0) << "\n";
    std::cout << sizeof(baza3_1) << "\n";
    baza3_1* b1 = new derivata3;
    delete b1;
    baza3_0* b2 = new derivata3_0;
//    auto& der = static_cast<derivata3_01&>(*b2);
//    der.f();
    try {
        auto& der = dynamic_cast<derivata3_0&>(*b2);
        new derivata3_0(der);
        der.g();
    } catch (std::bad_cast& err) {
        std::cout << err.what() << "\n";
    }
    auto* der2 = dynamic_cast<derivata3_01*>(b2);
    if(der2 != nullptr) {
        der2->f();
    }
    else {
        std::cout << "nu a reusit conversia cu pointer\n";
    }
    delete b2;
//    baza3_1 b1, b2;
//    std::cout << &b1 << " " << &b2 << "\n";
//    std::cout << sizeof(asd1) << "\n";
//    baza2* b2 = new baza2[2];
//    delete[] b2;
//    baza3_1* b3 = new baza3_1;
//    delete b3;
//    derivata21* d2 = new derivata21;
//    delete d2;
//    derivata3* d3 = new derivata3;
//    delete d3;
//
    std::shared_ptr<baza2> b21 = std::make_shared <derivata21>();
    b21->f();
    baza2& refb2 = *b21;
    refb2.f();
    //baza2 copie(*b21);
    std::cout << "inainte de clone\n";
    auto copie = b21->clone();
    copie->f();
//    delete b21;
    baza3_1* b31 = new derivata3;
    delete b31;

    return 0;
    std::cout << "size baza1: " << sizeof(baza1) << "\n";
    std::cout << "size derivata1: " << sizeof(derivata1) << "\n";
    std::cout << "size baza2: " << sizeof(baza2) << "\n";
    std::cout << "size derivata21: " << sizeof(derivata21) << "\n";
//    Vanzator v{"asd", 3};
//    std::cout<<v << "\n";
//    f(Accesoriu{"asd"s});
//    f(Magazin{"asd"s});
//    g({"asd", 23});
//    Priza p;
//    Incarcator usb{"asd"s, 123};
//    Magazin m{"asd"s} ;
//    m.modifica(m);
    return 0;
}
