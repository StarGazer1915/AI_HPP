#include <iostream>
#include "include/auto.hpp"
#include "include/klant.hpp"
#include "include/autohuur.hpp"
#include "include/talker.hpp"

using std::cout, std::endl;

int main()
{
    Klant k("Mijnheer de Vries", 0);
    k.set_korting(10.0);
    Auto a1("Peugeot 207", 50);
    AutoHuur ah1(a1, k, 4);
    cout << "Eerste autohuur:" << ah1 << endl;
    cout << endl;
    
    Auto a2("Ferrari", 3500);
    AutoHuur ah2(a1, k, 10);
    ah2.set_gehuurde_auto(a2);
    ah2.set_aantal_dagen(1);
    cout << "Tweede autohuur: " << ah2 << endl;
    cout << endl;
    
    cout << "Gehuurd: " << ah1.get_gehuurde_auto() << endl;
    cout << "Gehuurd: " << ah2.get_gehuurde_auto() << endl;
    
    return 0;
}
