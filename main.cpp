#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "headers/Accesoriu.h"
#include "headers/Microfon.h"

//#pragma pack(1)

using namespace std::string_literals;

//class asd {
//    int x;
//    std::string z;
//public:
//    asd(int x, const std::string &z);
//};
//
//asd::asd(int x, const std::string &z) : x(x), z(z) {}

class baza1 {
    int x;
    double z;
    double z1;
};

class derivata1 : public baza1 {};

class baza2 {
public:
    baza2() {
        std::cout << "constr b2\n";
    }

    virtual ~baza2() {
        std::cout << "destr b2\n";
    }
};
class derivata2 : public baza2 {
public:
    derivata2() {
        std::cout << "constr d2\n";
    }
    ~derivata2() {
        std::cout << "destr d2\n";
    }
    void g() {
        std::cout << "g d2\n";
    }
};
class derivata22 : public baza2 {
    int z{5};
public:
    derivata22() {
        std::cout << "constr d22\n";
    }
    ~derivata22() {
        std::cout << "destr d22\n";
    }
    void f() {
        std::cout << z << "f d22\n";
    }
};

class baza3 {
    int z = 7;
protected:
    baza3(const baza3&) = default;
    baza3& operator=(const baza3&) = default;
    virtual void afisare(std::ostream &ostream) const = 0;
public:
    friend std::ostream &operator<<(std::ostream &os, const baza3 &baza3);

    baza3() {
        std::cout << "constr b3 \n";
    }
    virtual ~baza3() {
        std::cout << "destr b3\n";
    }
    virtual void f() {
        std::cout << "f b3\n";
    }
    virtual void g();
    virtual std::shared_ptr<baza3> clone() const = 0;
};

void baza3::g() {
    std::cout << "g b3\n";
}

std::ostream &operator<<(std::ostream &os, const baza3 &baza3) {
    baza3.afisare(os);
    return os;
}

void baza3::afisare(std::ostream &ostream) const {
    const auto& baza3 = *this;
    ostream << "z: " << baza3.z;
}

class derivata31 : public baza3 {
public:
    [[nodiscard]] std::shared_ptr<baza3> clone() const override {
        return std::make_shared <derivata31>(*this);
    }

    void afisare(std::ostream &ostream) const override {
        baza3::afisare(ostream);
    }

    void g() override {
        baza3::g();
        std::cout << "g d31\n";
    }

    derivata31() {
        std::cout << "constr d31\n";
    }
    ~derivata31() {
        std::cout << "destr d31\n";
    }
    void f() override {
        //super.f();
        std::cout << "f d31\n";
        baza3::f();
    }
};
class derivata32 : public baza3 {
public:
    [[nodiscard]] std::shared_ptr<baza3> clone() const override {
        return std::make_shared <derivata32>(*this);
    }

    void afisare(std::ostream &ostream) const override {
        baza3::afisare(ostream);
    }

    void g() override {
        baza3::g();
        std::cout << "g d32\n";
    }

    derivata32() {
        std::cout << "constr d32\n";
    }
    ~derivata32() {
        std::cout << "destr d32\n";
    }
    void f() override {
        //super.f();
        std::cout << "f d32\n";
        baza3::f();
    }
};

// std::unique_ptr
// std::move

class colectie {
    std::vector<std::shared_ptr<baza3>> chestii;
public:
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
    void fa_chestii() {
        for(auto& chestie : chestii)
            chestie->g();
    }
};

class eroare_aplicatie : public std::runtime_error {
public:
    explicit eroare_aplicatie(const std::string &arg) : runtime_error(arg) {
        std::cout << "constr err\n";
    }
};

class eroare_tabla : public eroare_aplicatie {
public:
    explicit eroare_tabla(const std::string &arg) : eroare_aplicatie(arg) {}
};

class eroare_marker : public eroare_aplicatie {
public:
    explicit eroare_marker(const std::string &arg) : eroare_aplicatie("marker: " + arg) {}
};

void f2() {
    std::cout << "inainte f2\n";
    throw eroare_marker{"eroare f2"};
    std::cout << "dupa f2\n";
}

void f1() {
    std::cout << "inainte f1\n";
    try {
        f2();
        throw eroare_tabla{"err f1"};
        std::cout << "dupa f1\n";
    } catch (eroare_aplicatie& err) {
        std::cout << err.what() << " catch f1\n";
        throw eroare_aplicatie{"aaa"};
        std::cout << "dupa throw;\n";
    }
    std::cout << "dupa catch f1\n";
}

int main() {
    //f1();
    try {
        std::cout << "inainte in main\n";
        f1();
        std::cout << "dupa in main\n";
    } catch (std::exception& err) {
//        std::cout << err.what() << " catch main\n";
    }
//    catch(...) {
//
//    }
    baza2 *b01 = new derivata2;
//    auto& der0 = static_cast<derivata22&>(*b01);
//    der0.f();
    try {
        auto& der = dynamic_cast<derivata2&>(*b01);
//        der.f();
        der.g();
    } catch (std::bad_cast& err) {
        std::cout << err.what() << "\n";
    }
    if(auto der2 = dynamic_cast<derivata22*>(b01)) {
        der2->f();
        std::cout << "a reusit\n";
    }
    else
        std::cout<<"nu a reusit cast-ul\n";
    delete b01;
//    baza2 b21;
//    [[maybe_unused]] baza2 *b2 = new baza2;
//    delete b2;
    [[maybe_unused]] baza2 *b22 = new baza2[2];
    delete[] b22;
//    baza3 *b3 = new baza3;
//    delete b3;
    derivata2 *d2 = new derivata2;
    delete d2;
    derivata31 *d3 = new derivata31;
    d3->f();
    delete d3;

    baza2 *b23 = new derivata2;
    delete b23;
    baza3 *b32 = new derivata32;
    b32->f();
    b32->g();
    baza3& refb3 = *b32;
    refb3.g();
//    baza3 copie{*b32};
//    copie.g();
    std::cout << "inainte de clone\n";
    auto copie2 = b32->clone();
    copie2->g();
//    delete copie2;
    delete b32;

    return 0;
    std::cout << "size int " << sizeof(int) << "\n";
    std::cout << "size double " << sizeof(double) << "\n";
    std::cout << "size baza1 " << sizeof(baza1) << "\n";
    std::cout << "size derivata1 " << sizeof(derivata1) << "\n";
    std::cout << "size baza2 " << sizeof(baza2) << "\n";
    std::cout << "size derivata2 " << sizeof(derivata2) << "\n";
    std::cout << "size baza3 " << sizeof(baza3) << "\n";
    std::cout << "size derivata31 " << sizeof(derivata31) << "\n";
    std::cout << "size pointer int " << sizeof(int*) << "\n";
    Accesoriu p{"asd"s, 123};
    std::cout << p << "\n";
    Microfon m{"asd"s, 234, Microfon::USB_C};
    return 0;
}
