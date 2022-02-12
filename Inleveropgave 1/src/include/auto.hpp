#include <iostream>

using std::string, std::ostream;

class Auto
{
private:
    string type;
    double prijs_per_dag;

public:
    Auto();
    Auto(string type, double prijs_per_dag);
    friend ostream & operator<<(ostream & os, const Auto & ob);
    string get_type() const;
    void set_prijs_per_dag(double percentage);
    double get_prijs_per_dag() const;
    string to_string();
};