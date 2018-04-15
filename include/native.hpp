#ifndef NATIVE_HPP
#define NATIVE_HPP

#include <string>
#include <fstream>

class InjectStatement{
  public:
  bool is_valid(std::string line);

  std::string parse(std::string line);

  bool write(std::string native_commands, std::ofstream& outfile);
};

#endif
