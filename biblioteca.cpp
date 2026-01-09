#include "Biblioteca.hpp"

Biblioteca::Biblioteca() {}

Biblioteca::~Biblioteca() { 
    for (auto* c : stocCarti.getElemente()) {
        delete c;
    }
    for (auto* cl : registruClienti.getElemente()) {
        delete cl;
    }
}

void Biblioteca::adaugaCarte(Carte* c) {
    stocCarti.adauga(c);
}

void Biblioteca::adaugaClient(Client* c) {
    registruClienti.adauga(c);
}

void Biblioteca::afiseazaToateCartile() const {
    std::cout << "\n--- CARTI IN BIBLIOTECA ---\n";
    for (const auto* c : const_cast<Biblioteca*>(this)->stocCarti.getElemente()) {
        c->afiseaza(); 
    }
}

void Biblioteca::afiseazaTotiClientii() const {
    std::cout << "\n--- CLIENTI INREGISTRATI ---\n";
    for (const auto* c : const_cast<Biblioteca*>(this)->registruClienti.getElemente()) {
        std::cout << *c << "\n";
    }
}

void Biblioteca::inspecteazaCartiDetaliat() const {
    std::cout << "\n--- INSPECTIE DETALIATA (RTTI & Dynamic Cast) ---\n";
    for (const auto* c : const_cast<Biblioteca*>(this)->stocCarti.getElemente()) {
        const Roman* r = dynamic_cast<const Roman*>(c);
        if (r) {
            std::cout << " >> Am gasit un ROMAN: " << *r << " cu rating " << r->getRating() << "\n";
        } else {
            const Manual* m = dynamic_cast<const Manual*>(c);
            if (m) {
                std::cout << " >> Am gasit un  MANUAL: " << m->getTitlu() << " de " << m->getMaterie() << "\n";
            } else {
                std::cout << " >> Carte necunoscuta.\n";
            }
        }
    }
}

void Biblioteca::sorteazaCartiDupaTitlu() {
    auto& v = stocCarti.getElemente();
    
    std::sort(v.begin(), v.end(), [](Carte* a, Carte* b) {
        return a->getTitlu() < b->getTitlu();
    });

    std::cout << "\n=== ORDINE NOUA DUPA SORTARE (A-Z) ===\n";
    int cnt= 1;
    for (auto* c : v) {
        std::cout << cnt++ << ". " << c->getTitlu() 
                    << " (Autor: " << c->getAutor() << ")\n";
    }
    std::cout << "======================================\n";
}

Client* Biblioteca::gasesteClient(std::string nume) {
    auto& v = registruClienti.getElemente();
    auto it = std::find_if(v.begin(), v.end(), [nume](Client* c) {
        return c->getNume() == nume;
    });
    
    if (it != v.end()) return *it;
    throw BibliotecaException("Clientul nu a fost gasit :(");
}

Carte* Biblioteca::gasesteCarte(std::string titlu) {
    auto& v = stocCarti.getElemente();
    auto it = std::find_if(v.begin(), v.end(), [titlu](Carte* c) {
        return c->getTitlu() == titlu;
    });

    if (it != v.end()) return *it;
    throw BibliotecaException("Cartea cautata nu exista in stoc :(");
}
