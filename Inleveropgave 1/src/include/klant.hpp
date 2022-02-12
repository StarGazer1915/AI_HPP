#include <iostream>

using std::string, std::ostream;

class Klant
{
private:
    string naam;
    double korting_percentage;

public:
    Klant();
    Klant(std::string type, double prijs_per_dag);
    friend ostream & operator<<(ostream & os, const Klant & ob);
    string get_naam() const;
    void set_korting(double percentage);
    double get_korting() const;
    string to_string();
};