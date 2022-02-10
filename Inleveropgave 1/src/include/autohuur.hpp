#include <iostream>
#include "auto.hpp"
#include "klant.hpp"

using std::string;

class AutoHuur
{
private:
    Auto car;
    Klant huurder;
    int aantal_dagen;

public:
    AutoHuur();
    AutoHuur(Auto car, Klant huurder, int aantal_dagen);
    void set_aantal_dagen(int days);
    void set_gehuurde_auto(Auto new_car);
    Auto get_gehuurde_auto();
    void set_huurder(Klant new_huurder);
    Klant get_huurder();

    string to_string();
};