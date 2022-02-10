#include <iostream>

using std::string;

class Auto
{
private:
    string type;
    double prijs_per_dag;

public:
    Auto();
    Auto(string type, double prijs_per_dag);
    void set_prijs_per_dag(double percentage);
    double get_prijs_per_dag();
    string to_string();
};