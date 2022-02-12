#include <iostream>
#include <ctime>
#include "include/autohuur.hpp"
#include "include/persoon.hpp"

using std::cout, std::endl;

int main()
{
    cout << "\n------------------ AUTOHUUR ---------------------" << endl;
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

    cout << "\n------------------ GAMESHOP ---------------------" << endl;

    std::time_t result = std::time(NULL);
    cout << std::asctime(std::localtime(&result));
    time_t curr_time = time(NULL);
    tm *tm_local = localtime(&curr_time);
    int releaseJaar1 = tm_local->tm_year + 1899; // 1 jaar geleden
    int releaseJaar2 = tm_local->tm_year + 1898; // 2 jaar geleden
    
    Game g1("Just Cause 3", releaseJaar1, 49.98);
    Game g2("Need for Speed: Rivals", releaseJaar2, 45.99);
    Game g3("Need for Speed: Rivals", releaseJaar2, 45.99);
    
    Persoon p1("Eric", 200);
    Persoon p2("Hans", 55);
    Persoon p3("Arno", 185);
    

    // Druk personen p1, p2 en p3 nu af naar de console
    cout << "\np1:" << p1 << endl;
    cout << "\np2:" << p2 << endl;
    cout << "\np3:" << p3 << endl;
    
    // Druk de volgende transacties af (pas de code aan)
    p1.koop(g1);
    p1.koop(g2);
    p1.koop(g3);
    p2.koop(g2);
    p2.koop(g1);
    p3.koop(g3);

    // Druk personen p1, p2 en p3 nu af naar de console
    cout << "\np1:" << p1 << endl;
    cout << "\np2:" << p2 << endl;
    cout << "\np3:" << p3 << endl;
    
    // Druk de volgende transacties af (pas de code aan)
    p1.verkoop(g1, p3);
    p2.verkoop(g2, p3);
    p2.verkoop(g1, p1);
    
    // Druk personen p1, p2 en p3 nu af naar de console
    cout << "\np1:" << p1 << endl;
    cout << "\np2:" << p2 << endl;
    cout << "\np3:" << p3 << endl;
    
    return 0;
}
