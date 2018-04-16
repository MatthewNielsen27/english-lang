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


class ReturnStatement{
  public:
  bool is_valid(std::string line);

  std::string parse(std::string line);

  bool write(std::string native_commands, std::ofstream& outfile);
};

#endif