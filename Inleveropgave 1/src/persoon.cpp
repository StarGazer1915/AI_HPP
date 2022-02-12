#include <iostream>
#include <math.h>
#include "include/persoon.hpp"

using std::cout, std::string, std::ostream, std::vector;

Persoon::Persoon(string naam, double budget) : naam(naam), budget(budget) {
    games = {};
}

ostream & operator<<(ostream & os, const Persoon & ob) {
    os << "\n'" << ob.naam << "' heeft een budget van €" << ob.budget << " en bezit de volgende this->games:\n";
    
    for(auto & game : ob.games) {
        os.precision(4);
        os << "'" << game.get_naam() << "', uitgegeven in " << game.get_releasejaar(); // break line for readability
        os << " nieuwprijs: €" << game.get_prijs() << " nu voor: €" << game.get_oudprijs() << "\n";
    }
    return os;
}

void Persoon::koop(Game videogame) {
    if (videogame.get_prijs() < budget) {
        for(auto & game : this->games) {
            if (game.get_naam() == videogame.get_naam()) {
                cout << "'" << this->naam << "' koopt NIET '" << videogame.get_naam() << "' (al in bezit)\n";
                return;
            }
        }
        this->games.push_back(videogame);
        this->budget = budget - videogame.get_prijs();
        cout << "'" << this->naam << "' koopt '" << videogame.get_naam() << "'\n";

    } else if (videogame.get_prijs() > budget) {
        cout << "'" << this->naam << "' koopt NIET '" << videogame.get_naam() << "' (geen saldo)\n";
    }
}

void Persoon::verkoop(Game videogame, Persoon koper) {
    if (videogame.get_oudprijs() < koper.get_budget()) {
        for(auto & game : koper.games) {
            if (game.get_naam() == videogame.get_naam()) {
                cout << "'" << this->naam << "' verkoopt '" << videogame.get_naam() << " NIET aan " << koper.get_naam() << "' (al in bezit)\n";
                return;
            }
        }

        koper.games.push_back(videogame);
        cout << "'" << this->naam << "' verkoopt '" << videogame.get_naam() << "' aan " << koper.get_naam() << "\n";
        this->budget += videogame.get_oudprijs();
        
        for(int i = 0; i < this->games.size(); i++) {
            if (this->games[i].get_naam() == videogame.get_naam()) {
                this->games.erase(this->games.begin()+i);
            }
        }
    } else if (videogame.get_oudprijs() > koper.get_budget()) {
        cout << "'" << this->naam << "' verkoopt '" << videogame.get_naam() << "' NIET aan " << koper.get_naam() << "\n";
    }
}

string Persoon::get_naam() const {
    return this->naam;
}

double Persoon::get_budget() const {
    return this->budget;
}