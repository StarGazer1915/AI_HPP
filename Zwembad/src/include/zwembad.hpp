#include <iostream>
#include <vector>
#include "badmeester.hpp"

using std::string, std::vector;

class Zwembad
{
private:
    float breedte;
    float lengte;
    float diepte;
    vector<Badmeester> badmeesters;

public:
    Zwembad();
    Zwembad(float breedte, float lengte, float diepte, Badmeester badmeester);
    string get_breedte();
    string get_lengte();
    string get_diepte();
    vector<Badmeester> get_badmeesters();
    void set_breedte(float breedte);
    void set_lengte(float lengte);
    void set_diepte(float diepte);
    void add_badmeester(Badmeester nieuwe_badmeester);
    void remove_badmeester(int index);
    string inhoud();
    string to_string();
};