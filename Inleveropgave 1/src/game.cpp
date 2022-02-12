#include "include/game.hpp"

using std::string, std::ostream;

Game::Game(string naam, int releasejaar, double nieuwprijs) : naam(naam), releasejaar(releasejaar), nieuwprijs(nieuwprijs)
{
    double tmp = nieuwprijs;
    for(int i = 0; i < (2022 - releasejaar); i++) {
        tmp *= 0.7;
    }
    this->oudprijs = tmp;
}

ostream & operator<<(ostream & os, const Game & ob)
{
    os << "Game: '" << ob.naam << "'";
    return os;
}

string Game::get_naam() const
{
    return naam;
}

int Game::get_releasejaar() const
{
    return releasejaar;
}

double Game::get_prijs() const
{
    return nieuwprijs;
}

double Game::get_oudprijs() const
{
    return oudprijs;
}
