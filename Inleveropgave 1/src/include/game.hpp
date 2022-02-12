#include <iostream>

using std::string, std::ostream;

class Game
{
private:
    string naam;
    int releasejaar;
    double nieuwprijs;
    double oudprijs;

public:
    Game();
    Game(string naam, int releasejaar, double nieuwprijs);
    friend ostream & operator<<(ostream & os, const Game & ob);
    string get_naam() const;
    int get_releasejaar() const;
    double get_prijs() const;
    double get_oudprijs() const;
};