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
    if(index != std::string::npos){
      tokens.push_back(line.substr(index + 7));
    }

  }else{
    index = line.find(" equal to-> ");
    
    tokens.push_back(line.substr(0, index));
    if(index != std::string::npos){
      line = line.substr(index + 12);

      tokens.push_back(line);
    }

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

std::string _to_type(std::string incoming){
  if(incoming == "string"){
    return "std::string ";
  }else if(incoming == "integer"){
    return "int ";
  }else if(incoming == "decimal"){
    return "float ";
  }else if(incoming == "input-filestream"){
    return "std::ifstream ";
  }else if(incoming == "output-filestream"){
    return "std::ofstream ";
  }else if(incoming == "integer-array"){
    return "int * ";
  }else if(incoming == "variable"){
    return "auto ";
  }else return incoming + " ";
}

bool CreateStatement::write(std::vector<std::string> tokens, std::ofstream& outfile){
  if(tokens.size() == 2){
    outfile
      << _to_type(tokens[0])
      << tokens[1]
      << ";\n";
  }else{
    outfile
      << _to_type(tokens[0])
      << tokens[1]
      << " = ";
    for(int x = 2; x < tokens.size(); x++){
      outfile 
        << tokens[x]
        << " ";
    }
    outfile
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