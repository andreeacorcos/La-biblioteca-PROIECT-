#pragma once
#include <iostream>
#include <string>

class Carte {
protected:
    std::string titlu;
    std::string autor;
    static int numarTotalCarti; 

public:
    Carte(std::string t, std::string a);
    virtual ~Carte();

    std::string getTitlu() const;
    std::string getAutor() const;
    
    static int getNumarTotal();
    static void afiseazaStatistici();

    virtual void afiseaza() const = 0;
    virtual std::string getTip() const = 0;
    virtual Carte* clone() const = 0; 
};

class Roman : public Carte {
    std::string gen;
    double* rating; 

public:
    Roman(std::string t, std::string a, std::string g, double r);
    Roman(std::string t, std::string a); 
    Roman(const Roman& o);
    Roman& operator=(const Roman& o);
    ~Roman() override;

    void afiseaza() const override;
    std::string getTip() const override;
    Carte* clone() const override;
    double getRating() const;
    Roman operator+(double puncte);

    friend std::ostream& operator<<(std::ostream& os, const Roman& r);
    friend std::istream& operator>>(std::istream& is, Roman& r);
    friend bool operator==(const Roman& r1, const Roman& r2);
};

class Manual : public Carte {
    std::string materie;
public:
    Manual(std::string t, std::string a, std::string m);
    ~Manual() override;

    void afiseaza() const override;
    std::string getTip() const override;
    std::string getMaterie() const;
    Carte* clone() const override;
};
