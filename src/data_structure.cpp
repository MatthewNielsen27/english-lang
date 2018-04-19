#include "../include/data_structure.hpp"
#include <regex>

bool StructureStatement::is_valid(std::string line){
  return true;
}

std::string StructureStatement::parse(std::string line){
  line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1");

  return line.substr(10);
}

bool StructureStatement::write(std::string name, std::ofstream& outfile){
  outfile
    << "struct "
    << name
    << "{\n";
  return true;
}

bool EndStructureStatement::is_valid(std::string line){
  return true;
}

bool EndStructureStatement::write(std::ofstream& outfile){
  outfile
    << "};\n";
  return true;
}