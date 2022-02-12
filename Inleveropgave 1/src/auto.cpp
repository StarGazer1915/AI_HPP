#include "include/auto.hpp"

using std::string, std::ostream;

Auto::Auto(string type, double prijs_per_dag) : type(type), prijs_per_dag(prijs_per_dag)
{
}

ostream & operator<<(ostream & os, const Auto & ob)
{
    os << "Auto: '" << ob.type << "'";
    return os;
}

string Auto::get_type() const
{
    return type;
}

void Auto::set_prijs_per_dag(double percentage)
{
    this->prijs_per_dag = prijs_per_dag * (1 - percentage);
}

double Auto::get_prijs_per_dag() const
{
    return prijs_per_dag;
}

string Auto::to_string()
{
    return "Type auto: " + type + ". Prijs per dag: " + std::to_string(prijs_per_dag) + ".";
}
