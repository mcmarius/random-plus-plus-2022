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

    ~baza2() {
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
};

class baza3 {
    int z = 7;
protected:
    baza3(const baza3&) = default;
    baza3& operator=(const baza3&) = default;
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
    virtual void afis(std::ostream &ostream) const;
};

void baza3::g() {
    std::cout << "g b3\n";
}

std::ostream &operator<<(std::ostream &os, const baza3 &baza3) {
    baza3.afis(os);
    return os;
}

void baza3::afis(std::ostream &os) const {
    const auto& baza3 = *this;
    os << "z: " << baza3.z;
}

class derivata31 : public baza3 {
public:
    [[nodiscard]] std::shared_ptr<baza3> clone() const override {
        return std::make_shared <derivata31>(*this);
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

int main() {
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
