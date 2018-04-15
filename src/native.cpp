#include "../include/native.hpp"
#include <regex>

bool InjectStatement::is_valid(std::string line){
  return true;
}

std::string InjectStatement::parse(std::string line){
  line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1");
  
  return line.substr(6);
}

bool InjectStatement::write(std::string native_commands, std::ofstream& outfile){
  outfile
    << native_commands
    << "\n";
  return true;
}