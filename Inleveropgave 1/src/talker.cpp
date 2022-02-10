#include <string>
#include "include/talker.hpp"

using std::string;

Talker::Talker(string name)
{
    this->name = name;
}

std::ostream& operator<<(std::ostream& os, Talker& g) {
  os << "Hello, " << g.name << "!" << std::endl;
  return os;
}
