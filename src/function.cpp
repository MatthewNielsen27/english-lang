#include "../include/function.hpp"
#include <regex>

bool FunctionStatement::is_valid(std::string line){
  return true;
}

std::string to_type(std::string incoming){
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

std::vector<std::string> FunctionStatement::parse(std::string line, std::ifstream& infile){
  std::vector<std::string> tokens;
  size_t index;
  std::string name = "";
  std::string returns = "";
  std::string params = "";

  line = line.substr(9);
  name = line;

  int sig_count = 0;

  while(sig_count != 2){
    getline( infile, line );
    line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1");
    index = line.find(":");

    if(line.substr(0, index) == "returns"){
      sig_count++;
      returns = to_type(line.substr(index + 2));
    }else if(line.substr(0, index) == "takes"){
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
          var_type = to_type(buffer.substr(0, buffer.find(" ")));
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

  tokens.push_back(returns);
  tokens.push_back(name);
  tokens.push_back(params);

  return tokens;
}

bool FunctionStatement::write(std::vector<std::string> tokens, std::ofstream& outfile){
  outfile
    << tokens[0]
    << " "
    << tokens[1]
    << "( "
    << tokens[2]
    << " )\n";
  return true;  
}

bool ReturnStatement::is_valid(std::string line){
  return true;
}

std::string ReturnStatement::parse(std::string line){
  line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1");
  
  return line.substr(7);
}

bool ReturnStatement::write(std::string native_commands, std::ofstream& outfile){
  outfile
    << "return "
    << native_commands
    << ";\n";
  return true;
}

