#include <iostream>
#include <string>
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
    ~baza2() = default;
};
class derivata2 : public baza2 {};

class baza3 {
public:
    virtual ~baza3() = default;
};
class derivata3 : public baza3 {};

int main() {
    std::cout << "size int " << sizeof(int) << "\n";
    std::cout << "size double " << sizeof(double) << "\n";
    std::cout << "size baza1 " << sizeof(baza1) << "\n";
    std::cout << "size derivata1 " << sizeof(derivata1) << "\n";
    std::cout << "size baza2 " << sizeof(baza2) << "\n";
    std::cout << "size derivata2 " << sizeof(derivata2) << "\n";
    std::cout << "size baza3 " << sizeof(baza3) << "\n";
    std::cout << "size derivata3 " << sizeof(derivata3) << "\n";
    std::cout << "size pointer int " << sizeof(int*) << "\n";
    Accesoriu p{"asd"s, 123};
    std::cout << p << "\n";
    Microfon m{"asd"s, 234, Microfon::USB_C};
    return 0;
}
