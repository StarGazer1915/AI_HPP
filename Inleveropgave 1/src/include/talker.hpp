#include <iostream>

using std::string, std::ostream;

class Talker {
  private:
    string name;
  public:
    Talker(string name);
    friend ostream& operator<<(ostream& os, Talker& g);
};