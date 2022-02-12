#include <iostream>
#include <vector>
#include "game.hpp"

using std::string, std::ostream, std::vector;

class Persoon
{
private:
    string naam;
    double budget;
    vector <Game> games;

public:
    Persoon();
    Persoon(string naam, double budet);
    friend ostream & operator<<(ostream & os, const Persoon & mc);
    void koop(Game videogame);
    void verkoop(Game videogame, Persoon koper);
    string get_naam() const;
    double get_budget() const;
};