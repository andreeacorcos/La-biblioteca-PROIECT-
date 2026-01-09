#pragma once
#include <string>
#include <iostream>

class Persoana {
protected:
    std::string nume;
public:
    Persoana(std::string n) : nume(n) {}
    virtual ~Persoana() {}
    std::string getNume() const { return nume; }
};

class Client : public Persoana {
public:
    Client(std::string n) : Persoana(n) {}
    ~Client() override {}

    friend std::ostream& operator<<(std::ostream& os, const Client& c) {
        os << "[Client] " << c.nume;
        return os;
    }
};