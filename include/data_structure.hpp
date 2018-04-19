#ifndef DATA_STRUCTURE_HPP
#define DATA_STRUCTURE_HPP

#include <vector>
#include <fstream>
#include <string>

class StructureStatement{
  public:
  bool is_valid(std::string line);

  std::string parse(std::string line);

  bool write(std::string name, std::ofstream& outfile);
};

class ClassStructureStatement{
  public:
  bool is_valid(std::string line);

  std::string parse(std::string line);

  bool write(std::string name, std::ofstream& outfile);
};

class PrivacyStatement{
  public:
  bool is_valid(std::string line);

  std::string parse(std::string line);

  bool write(std::string name, std::ofstream& outfile);
};

class EndStructureStatement{
  public:
  bool is_valid(std::string line);

  bool write(std::ofstream& outfile);
};

class ConstructorStatement{
  public:
  bool is_valid(std::string line);

  std::vector<std::string> parse(std::string line, std::ifstream& infile);

  bool write(std::vector<std::string> tokens, std::ofstream& outfile);
};

#endif