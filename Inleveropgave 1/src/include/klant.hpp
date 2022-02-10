#include <iostream>

using std::string;

class Klant
{
private:
    string naam;
    double korting_percentage;

public:
    Klant();
    Klant(std::string type, double prijs_per_dag);
    void set_korting(double percentage);
    double get_korting();
    string to_string();
};