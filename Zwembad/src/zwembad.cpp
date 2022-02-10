#include <string>
#include "include/zwembad.hpp"

Zwembad::Zwembad()
{
    badmeesters = {};
}

Zwembad::Zwembad(float breedte, float lengte, float diepte, Badmeester badmeester)
{
    this->breedte = breedte;
    this->lengte = lengte;
    this->diepte = diepte;
    badmeesters = { badmeester };
}

std::string Zwembad::get_breedte()
{
    return "BREEDTE: " + std::to_string(breedte);
}

std::string Zwembad::get_lengte()
{
    return "LENGTE: " + std::to_string(breedte);
}

std::string Zwembad::get_diepte()
{
    return "DIEPTE: " + std::to_string(breedte);
}

vector<Badmeester> Zwembad::get_badmeesters()
{
    return badmeesters;
}

void Zwembad::set_breedte(float b)
{
    breedte = b;
}

void Zwembad::set_lengte(float l)
{
    lengte = l;
}

void Zwembad::set_diepte(float d)
{
    diepte = d;
}

void Zwembad::add_badmeester(Badmeester nieuwe_badmeester)
{
    badmeesters.push_back(nieuwe_badmeester);
}

void Zwembad::remove_badmeester(int index)
{
    badmeesters.erase(badmeesters.begin() + index);
}

std::string Zwembad::inhoud()
{
    return "BEREKENDE INHOUD: " + std::to_string(breedte * lengte * diepte);
}

std::string Zwembad::to_string()
{
    return "GEGEVENS ZWEMBAD: Dit zwembad is " + std::to_string(breedte) + " meter breed, " + std::to_string(lengte) + " meter lang, en " + std::to_string(diepte) + " meter diep";
}
