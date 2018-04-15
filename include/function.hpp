#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <vector>
#include <fstream>
#include <string>

class FunctionStatement{
  public:
  bool is_valid(std::string line);

  std::vector<std::string> parse(std::string line, std::ifstream& infile);

  bool write(std::vector<std::string> tokens, std::ofstream& outfile);
};

#endif