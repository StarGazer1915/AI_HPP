#include <string>
#include "include/klant.hpp"

using std::string, std::to_string;

Klant::Klant(string naam, double korting_percentage) : naam(naam), korting_percentage(korting_percentage)
{
}

void Klant::set_korting(double percentage)
{
    this->korting_percentage = percentage;
}

double Klant::get_korting()
{
    return korting_percentage;
}

string Klant::to_string()
{
    return "Naam van de klant: " + naam + ". Kortingspercentage: " + std::to_string(korting_percentage) + ".";
}