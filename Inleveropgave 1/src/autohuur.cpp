#include <string>
#include "include/autohuur.hpp"

using std::string, std::to_string, std::ostream;

AutoHuur::AutoHuur(Auto car, Klant huurder, int aantal_dagen) : car(car), huurder(huurder), aantal_dagen(aantal_dagen)
{
}

ostream & operator<<(ostream & os, const AutoHuur & ah)
{
    os << "\n autotype: " << ah.car.get_type() << " met prijs per dag: " << ah.car.get_prijs_per_dag();
    os << "\n op naam van: " << ah.huurder.get_naam() << " (Korting: " << ah.huurder.get_korting() << "%)";
    os << "\n aantal dagen: " << ah.aantal_dagen << " en dat kost " << (ah.car.get_prijs_per_dag() * ah.aantal_dagen) * (1 - (ah.huurder.get_korting() / 100));
    return os;
}

void AutoHuur::set_aantal_dagen(int days)
{
    this->aantal_dagen = days;
}

void AutoHuur::set_gehuurde_auto(Auto new_car)
{
    this->car = new_car;
}

string AutoHuur::get_gehuurde_auto()
{
    return car.get_type() + " met prijs per dag: " + std::to_string(car.get_prijs_per_dag());
}

void AutoHuur::set_huurder(Klant new_huurder)
{
    this->huurder = new_huurder;
}

Klant AutoHuur::get_huurder()
{
    return huurder;
}

string AutoHuur::to_string()
{
    return "Auto: " + car.get_type() + ". Huurder: " + huurder.get_naam() + ". Aantal dagen: "  + std::to_string(aantal_dagen) + ".";
}