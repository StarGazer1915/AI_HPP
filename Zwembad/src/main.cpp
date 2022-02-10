#include "include/zwembad.hpp"

using std::cout, std::endl;

int main()
{
    Zwembad z1(2.0, 5.5, 1.5, Badmeester("Barry"));
    cout << z1.get_breedte() << endl;
    cout << z1.get_lengte() << endl;
    cout << z1.get_diepte() << endl;
    cout << z1.inhoud() << endl;
    z1.add_badmeester(Badmeester("Pamela"));
    z1.add_badmeester(Badmeester("Cindy"));
    z1.remove_badmeester(1);
    for (Badmeester b : z1.get_badmeesters())
    {
        cout << "Een badmeester is: " << b.get_naam() << endl;
    }
    cout << endl;
    Zwembad z2;
    z2.set_breedte(2.5);
    z2.set_lengte(100.0);
    z2.set_diepte(2.0);
    cout << z2.to_string() << endl;
    cout << z2.inhoud() << endl;
    return 0;
}