#include <string>
#include "include/auto.hpp"

using std::string;

Auto::Auto(string type, double prijs_per_dag) : type(type), prijs_per_dag(prijs_per_dag)
{
}

void Auto::set_prijs_per_dag(double percentage)
{
    this->prijs_per_dag = prijs_per_dag * (1 - percentage);
}

double Auto::get_prijs_per_dag()
{
    return prijs_per_dag;
}

string Auto::to_string()
{
    return "Deze auto is van het type: " + type + ". De prijs per dag van deze auto is: " + std::to_string(prijs_per_dag) + ".";
}
