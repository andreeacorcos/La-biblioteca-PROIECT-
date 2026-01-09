#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <exception>
#include "Manager.hpp"
#include "Cartile.hpp"
#include "Persoane.hpp"

class BibliotecaException : public std::exception {
    std::string mesaj;
public:
    BibliotecaException(const std::string& msg) : mesaj(msg) {}
    virtual const char* what() const noexcept override {
        return mesaj.c_str();
    }
};

class Biblioteca {
    Manager<Carte*> stocCarti;
    Manager<Client*> registruClienti;

public:
    Biblioteca();
    ~Biblioteca();

    void adaugaCarte(Carte* c);
    void adaugaClient(Client* c);
    void afiseazaToateCartile() const;
    void afiseazaTotiClientii() const;
    void inspecteazaCartiDetaliat() const;
    void sorteazaCartiDupaTitlu();
    
    Client* gasesteClient(std::string nume);
    Carte* gasesteCarte(std::string titlu);

};
