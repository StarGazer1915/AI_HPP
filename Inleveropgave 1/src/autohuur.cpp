#include <string>
#include "include/autohuur.hpp"

using std::string;

AutoHuur::AutoHuur(Auto car, Klant huurder, int aantal_dagen) : car(car), huurder(huurder), aantal_dagen(aantal_dagen)
{
}

void AutoHuur::set_aantal_dagen(int days)
{
    this->aantal_dagen = days;
}

void AutoHuur::set_gehuurde_auto(Auto new_car)
{
    this->car = new_car;
}

Auto AutoHuur::get_gehuurde_auto()
{
    return car;
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
    return "";
}
