#include "Cartile.hpp"

int Carte::numarTotalCarti = 0;

Carte::Carte(std::string t, std::string a) : titlu(t), autor(a) {
    numarTotalCarti++;
}

Carte::~Carte() {
    numarTotalCarti--;
}

std::string Carte::getTitlu() const { return titlu; }
std::string Carte::getAutor() const { return autor; }

int Carte::getNumarTotal() { return numarTotalCarti; }

void Carte::afiseazaStatistici() {
    std::cout << "[Static Info] Total carti in memorie acum: " << numarTotalCarti << "\n";
}

Roman::Roman(std::string t, std::string a, std::string g, double r) 
    : Carte(t, a), gen(g) {
    rating = new double(r);
}

Roman::Roman(std::string t, std::string a) 
    : Carte(t, a), gen("General") {
    rating = new double(0.0);
}

Roman::Roman(const Roman& o) : Carte(o.titlu, o.autor) {
    this->gen = o.gen;
    this->rating = new double(*(o.rating));
    std::cout << "-> (Constructor de copiere Roman apelat)\n";
}

Roman& Roman::operator=(const Roman& o) {
    if (this == &o) return *this;
    
    this->titlu = o.titlu;
    this->autor = o.autor;
    this->gen = o.gen;

    delete rating;
    this->rating = new double(*(o.rating));
    
    std::cout << "-> (Op= Roman apelat)\n";
    return *this;
}

Roman::~Roman() {
    delete rating;
}

void Roman::afiseaza() const {
    std::cout << "Roman: " << titlu << " (" << autor << ") - " << gen << " [Rating: " << *rating << "]\n";
}

std::string Roman::getTip() const { return "Roman"; }

Carte* Roman::clone() const {
    return new Roman(*this); 
}

double Roman::getRating() const { return *rating; }

Roman Roman::operator+(double puncte) {
    double nouRating = *rating + puncte;
    if(nouRating > 10.0) nouRating = 10.0;
    return Roman(this->titlu, this->autor, this->gen, nouRating);
}

std::ostream& operator<<(std::ostream& os, const Roman& r) {
    os << "Roman '" << r.titlu << "', Gen: " << r.gen;
    return os;
}

std::istream& operator>>(std::istream& is, Roman& r) {
    std::cout << "Titlu: "; is >> r.titlu;
    std::cout << "Autor: "; is >> r.autor;
    std::cout << "Gen: "; is >> r.gen;
    std::cout << "Rating: "; 
    double aux;
    is >> aux;
    *r.rating = aux;
    return is;
}

bool operator==(const Roman& r1, const Roman& r2) {
    return (r1.titlu == r2.titlu && r1.autor == r2.autor);
}


Manual::Manual(std::string t, std::string a, std::string m) 
    : Carte(t, a), materie(m) {}

Manual::~Manual() {}

void Manual::afiseaza() const {
    std::cout << "Manual: " << titlu << " (" << autor << ") - Materie: " << materie << "\n";
}

std::string Manual::getTip() const { return "Manual"; }
std::string Manual::getMaterie() const { return materie; }

Carte* Manual::clone() const {
    return new Manual(this->titlu, this->autor, this->materie);
}
