#include <iostream>
#include "Biblioteca.hpp"

void afiseazaMeniu() {
    std::cout << "\n=== MANAGER BIBLIOTECA ===\n";
    std::cout << "1. Adauga Roman\n";
    std::cout << "2. Adauga Manual\n";
    std::cout << "3. Adauga Client\n";
    std::cout << "4. Afiseaza tot (Carti & Clienti)\n";
    std::cout << "5. Inspectie Tehnica (Dynamic Cast)\n";
    std::cout << "6. Sorteaza Carti si Afiseaza Ordinea\n";
    std::cout << "7. Demonstreaza Operatori Roman (+ si ==)\n";
    std::cout << "0. Iesire\n";
    std::cout << "Optiune: ";
}

int main() {
    Biblioteca biblio;

    biblio.adaugaCarte(new Roman("Dune", "F. Herbert", "SF", 9.8));
    biblio.adaugaCarte(new Roman("Anna Karenina", "Leo Tolstoy", "Roman", 8.5));
    biblio.adaugaCarte(new Roman("Calatorie spre centrul Pamantului", "Jules Verns", "Aventura", 7.2));
    biblio.adaugaCarte(new Roman("Ion", "Liviu Rebreanu", "Roman", 5.1));
    biblio.adaugaCarte(new Roman("Batman: Nightwalker", "Marie Lu", "Fictiune", 8.2));

    biblio.adaugaCarte(new Manual("Matematica clasa a X-a", "C. Popescu", "Matematica"));
    biblio.adaugaCarte(new Manual("Matematica clasa a V-a", "M. Alexandrescu", "Matematica"));
    biblio.adaugaCarte(new Manual("Informatica clasa a XI-a", "C. Popescu", "Informatica"));

    biblio.adaugaClient(new Client("Andreea"));
    biblio.adaugaClient(new Client("Maria"));
    biblio.adaugaClient(new Client("Alex"));
    biblio.adaugaClient(new Client("Stefan"));


    int optiune;
    do {
        afiseazaMeniu();
        std::cin >> optiune;

        try {
            switch (optiune) {
            case 1: {
                std::string t, a, g; 
                double r;
                std::cout << "Titlu: "; std::cin >> t;
                std::cout << "Autor: "; std::cin >> a;
                std::cout << "Gen: "; std::cin >> g;
                std::cout << "Rating: "; std::cin >> r;
                biblio.adaugaCarte(new Roman(t, a, g, r));
                break;
            }
            case 2: {
                std::string t, a, m;
                std::cout << "Titlu: "; std::cin >> t;
                std::cout << "Autor: "; std::cin >> a;
                std::cout << "Materie: "; std::cin >> m;
                biblio.adaugaCarte(new Manual(t, a, m));
                break;
            }
            case 3: {
                std::string n;
                std::cout << "Nume client: "; std::cin >> n;
                biblio.adaugaClient(new Client(n));
                break;
            }
            case 4:
                biblio.afiseazaToateCartile();
                biblio.afiseazaTotiClientii();
                Carte::afiseazaStatistici(); 
                break;
            case 5:
                biblio.inspecteazaCartiDetaliat();
                break;
            case 6:
                biblio.sorteazaCartiDupaTitlu();
                break;
            case 7: {
                std::cout << "-- Demo Operatori --\n";
                Roman r1("TestA", "AutorA", "GenA", 5.0);
                Roman r2 = r1 + 3.0; 
                std::cout << "R1 initial: " << r1 << " Rating: " << r1.getRating() << "\n";
                std::cout << "R2 (R1 + 3pct): " << r2 << " Rating: " << r2.getRating() << "\n";
                
                if (r1 == r2) 
                    std::cout << "Sunt identice (titlu/autor).\n";
                else 
                    std::cout << "Sunt diferite.\n";
                
                std::cout << "-- Demo Constructor de copiere--\n";
                Roman r3 = r1; 
                std::cout << "R3 (copie R1): " << r3 << "\n";
                break;
            }
            case 0:
                std::cout << "Au revoir!\n";
                break;
            default:
                std::cout << "Optiune invalida.\n";
            }
        }
        catch (const BibliotecaException& e) {
            std::cerr << "[EROARE LOGICA] " << e.what() << "\n";
        }
        catch (const std::exception& e) {
            std::cerr << "[EROARE SISTEM] " << e.what() << "\n";
        }

    } while (optiune != 0);

    return 0;
}
