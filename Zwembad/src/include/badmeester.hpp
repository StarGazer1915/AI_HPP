#include <string>

class Badmeester
{
private:
    std::string naam;
public:
    Badmeester();
    Badmeester(std::string naam);
    std::string get_naam();
};