#include "../include/io.hpp"
#include <regex>
#include <iostream>

bool to_found(std::string in, size_t i){
  if(in[i] == 't' && in[i + 1] == 'o' && in[i + 2] == '-' && in[i + 3] == '>'){
    return true;
  }else {
    return false;
  }
}

bool WriteStatement::is_valid(std::string line){
  return true;
}

std::vector<std::string> WriteStatement::parse(std::string line){
  std::vector<std::string> tokens;

  line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1");

  //remove 'if' and ', then' statement
  size_t index;
  line = line.substr(6);

  int encapsulated = 0;

  bool quoted = false;
  bool found = false;
  std::string buffer = "";

  for(int i = 0; line[i] != 0 && !found; i++){
    if(to_found(line, i) && !encapsulated && !quoted){
      found = true;
    }else if(line[i] == '"'){
      buffer += line[i];
      quoted = !quoted;
    }else if(line[i] == '('){
      buffer += line[i];
      encapsulated++;
    }else if(line[i] == ')'){
      buffer += line[i];
      encapsulated--;
    }else{
      buffer += line[i];
    }
  }

  line = line.substr(buffer.length());
  
  index = line.find("to-> ");
  tokens.push_back(line.substr(index + 5));
  tokens.push_back(buffer);

  return tokens;
}

bool WriteStatement::write(std::vector<std::string> tokens, std::ofstream& outfile){
  if(tokens[0] == "console"){
    outfile << "std::cout << ";
  }else{
    outfile << tokens[0] << " << ";
  }
  outfile
    << tokens[1] 
    << "<<\"\\n\";\n";
  return true;
}

// Put statement

bool PutStatement::is_valid(std::string line){
  return true;
}

std::vector<std::string> PutStatement::parse(std::string line){
  std::vector<std::string> tokens;

  line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1");

  //remove 'if' and ', then' statement
  size_t index;
  line = line.substr(4);

  int encapsulated = 0;

  bool quoted = false;
  bool found = false;
  std::string buffer = "";

  for(int i = 0; line[i] != 0 && !found; i++){
    if(to_found(line, i) && !encapsulated && !quoted){
      found = true;
    }else if(line[i] == '"'){
      buffer += line[i];
      quoted = !quoted;
    }else if(line[i] == '('){
      buffer += line[i];
      encapsulated++;
    }else if(line[i] == ')'){
      buffer += line[i];
      encapsulated--;
    }else{
      buffer += line[i];
    }
  }

  line = line.substr(buffer.length());
  
  index = line.find("to-> ");
  tokens.push_back(line.substr(index + 5));
  tokens.push_back(buffer);

  return tokens;
}

bool PutStatement::write(std::vector<std::string> tokens, std::ofstream& outfile){
  if(tokens[0] == "console"){
    outfile << "std::cout << ";
  }else{
    outfile << tokens[0] << " << ";
  }
  for(int i = 1; i < tokens.size(); i++){
    outfile << tokens[i] << " ";
  }
  outfile << ";\n";
  return true;
}

bool OpenStatement::is_valid(std::string line){
  return true;
}

std::vector<std::string> OpenStatement::parse(std::string line){
  std::vector<std::string> tokens;
  size_t index;
  
  line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1");

  line = line.substr(5);

  index = line.find(" using ");
  
  tokens.push_back(line.substr(0, index));

  line = line.substr(index + 7);

  index = line.find(" ");

  tokens.push_back(line.substr(0, index));

  return tokens;
}

bool OpenStatement::write(std::vector<std::string> tokens, std::ofstream& outfile){
  outfile
    << tokens[1]
    << ".open(\""
    << tokens[0]
    << "\");\n";
  return true;
}

bool AppendStatement::is_valid(std::string line){
  return true;
}

std::vector<std::string> AppendStatement::parse(std::string line){
  std::vector<std::string> tokens;
  size_t index;
  
  line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1");

  line = line.substr(7);

  index = line.find(" using ");
  
  tokens.push_back(line.substr(0, index));


  line = line.substr(index + 7);

  index = line.find(" ");

  tokens.push_back(line.substr(0, index));

  return tokens;
}

bool AppendStatement::write(std::vector<std::string> tokens, std::ofstream& outfile){
  outfile
    << tokens[1]
    << ".open(\""
    << tokens[0]
    << "\", std::fstream::app);\n";
  return true;
}

bool CloseStatement::is_valid(std::string line){
  return true;
}

std::string CloseStatement::parse(std::string line){
  line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1");

  line = line.substr(6);

  size_t index = line.find(" ");

  return line.substr(0, index);
}

bool CloseStatement::write(std::string filename, std::ofstream& outfile){
  outfile
    << filename
    << ".close();\n";
  return true;
}