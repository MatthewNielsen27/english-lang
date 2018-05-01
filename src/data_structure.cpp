#include "../include/data_structure.hpp"
#include <regex>

std::string __to_type(std::string incoming){
  if(incoming == "string"){
    return "std::string";
  }else if(incoming == "integer-list"){
    return "int * ";
  }else if(incoming == "integer"){
    return "int";
  }else if(incoming == "decimal"){
    return "float";
  }else if(incoming == "nothing"){
    return "void";
  }else{
    return incoming;
  }
}

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

bool ClassStructureStatement::is_valid(std::string line){
  return true;
}

std::string ClassStructureStatement::parse(std::string line){
  line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1");

  return line.substr(16);
}

bool ClassStructureStatement::write(std::string name, std::ofstream& outfile){
  outfile
    << "class "
    << name
    << "{\n";
  return true;
}

bool PrivacyStatement::is_valid(std::string line){
  return (line.find("public") != std::string::npos || line.find("private") != std::string::npos);
}

std::string PrivacyStatement::parse(std::string line){
  line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1");

  return line.substr(16);
}

bool PrivacyStatement::write(std::string name, std::ofstream& outfile){
  outfile
    << name
    << ":\n";
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

bool ConstructorStatement::is_valid(std::string line){
  return true;
}

std::vector<std::string> ConstructorStatement::parse(std::string line, std::ifstream& infile){
  std::vector<std::string> tokens;
  size_t index;
  std::string name = "";
  std::string params = "";

  line = line.substr(12);
  name = line;

  int sig_count = 0;

  while(sig_count != 1){
    getline( infile, line );
    line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1");
    index = line.find(":");
    if(line.substr(0, index) == "takes"){
      sig_count++;
      line = line.substr(index + 2);
      line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1");

      if(line != "nothing"){
        std::string buffer;
        std::string var_type;

        while(line.length() != 0 && index != std::string::npos){
          line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1");
          index = line.find(",");
          buffer = line.substr(0, index);
          var_type = __to_type(buffer.substr(0, buffer.find(" ")));
          buffer = buffer.substr(buffer.find(" ") + 1);
          line = line.substr(index + 1);

          if(params == ""){
            params = var_type + " " + buffer;
          }else{
            params += " ," + var_type + " " + buffer;
          }
        }
      }
    }
  }

  tokens.push_back(name);
  tokens.push_back(params);

  return tokens;
}

bool ConstructorStatement::write(std::vector<std::string> tokens, std::ofstream& outfile){
  outfile
    << tokens[0]
    << "( "
    << tokens[1]
    << " )\n";
  return true;  
}