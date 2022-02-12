#include "include/klant.hpp"

using std::string, std::to_string, std::ostream;

Klant::Klant(string naam, double korting_percentage) : naam(naam), korting_percentage(korting_percentage)
{
}

ostream & operator<<(ostream & os, const Klant & ob)
{
    os << "Klant: '" << ob.naam << "'";
    return os;
}

string Klant::get_naam() const
{
    return naam;
}

void Klant::set_korting(double percentage)
{
    this->korting_percentage = percentage;
}

double Klant::get_korting() const
{
    return korting_percentage;
}

string Klant::to_string()
{
    return "Naam van de klant: " + naam + ". Kortingspercentage: " + std::to_string(korting_percentage) + ".";
}