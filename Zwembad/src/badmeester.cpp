#include "include/badmeester.hpp"

Badmeester::Badmeester()
{
    naam = "Geen";
}

Badmeester::Badmeester(std::string naam)
{
    this->naam = naam;
}

std::string Badmeester::get_naam()
{
    return naam;
}