#include "../include/variables.hpp"
#include <regex>

bool CreateStatement::is_valid(std::string line){
  return true;
}

std::vector<std::string> CreateStatement::parse(std::string line){
  std::vector<std::string> tokens;

  line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1");

  //remove 'if' and ', then' statement
  size_t index;

  line = line.substr(7);

  index = line.find(" ");

  std::string create_type = line.substr(0, index);

  tokens.push_back(create_type);

  line = line.substr(index + 1);

  if(create_type == "input-filestream" || create_type == "output-filestream"){
    index = line.find(" named ");

    tokens.push_back(line.substr(index + 7));

  }else{
    index = line.find(" equal to-> ");

    tokens.push_back(line.substr(0, index));

    line = line.substr(index + 12);

    tokens.push_back(line);
  }
  return tokens;
}

bool is_of_normal_type(std::string incoming){
  if(incoming == "integer-list" || incoming == "input-filestream" || incoming == "output-filestream"){
    return false;
  }else{
    return true;
  }
}

bool CreateStatement::write(std::vector<std::string> tokens, std::ofstream& outfile){
  if(is_of_normal_type(tokens[0])){
    outfile
      << "auto "
      << tokens[1]
      << " = ";
    for(int i = 2; i < tokens.size(); i++){
      outfile
      << tokens[i]
      << " ";
    }
    outfile << ";\n";
  }else if(tokens[0] == "integer-list"){
    outfile
      << "int * "
      << tokens[1]
      << " = ";
    for(int i = 2; i < tokens.size(); i++){
      outfile
      << tokens[i]
      << " ";
    }
    outfile << ";\n";
  }else if(tokens[0] == "input-filestream"){
    outfile
      << "std::ifstream "
      << tokens[1]
      << ";\n";
  }else if(tokens[0] == "output-filestream"){
    outfile
      << "std::ofstream "
      << tokens[1]
      << ";\n";
  }
  return true;
}

bool SetStatement::is_valid(std::string line){
  return true;
}

std::vector<std::string> SetStatement::parse(std::string line){
  std::vector<std::string> tokens;

  line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1");

  //remove 'if' and ', then' statement
  size_t index;

  line = line.substr(4);

  index = line.find(" ");

  tokens.push_back(line.substr(0, index));

  index = line.find(" equal to-> ");
  tokens.push_back(line.substr(index + 12));

  return tokens;
}

bool SetStatement::write(std::vector<std::string> tokens, std::ofstream& outfile){
  outfile
  << tokens[0]
  << " = "
  << tokens[1]
  << ";\n";
  return true;
}