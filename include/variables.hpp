#ifndef VARIABLES_HPP
#define VARIABLES_HPP

#include <fstream>
#include <vector>
#include <string>

class CreateStatement{
  public:
  bool is_valid(std::string line);

  std::vector<std::string> parse(std::string line);

  bool write(std::vector<std::string> tokens, std::ofstream& outfile);
};

class SetStatement{
  public:
  bool is_valid(std::string line);

  std::vector<std::string> parse(std::string line);

  bool write(std::vector<std::string> tokens, std::ofstream& outfile);
};

#endif