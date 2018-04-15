#include "../include/control_flow.hpp"
#include <regex>
#include <iostream>

std::string to_operator(std::string incoming){
  if(incoming == "equals"){
    return "==";
  }else{
    return incoming;
  }
}

// IF STATEMENT

bool IfStatement::is_valid(std::string incoming){
  return true;
}

bool IfStatement::write(std::vector<std::string> incoming, std::ofstream& outfile){
  outfile << "if( ";

  size_t max = incoming.size();

  for(int x = 0; x < max; x++){
    outfile << incoming[x] << " ";
  }

  outfile << "){\n";

  return true;
}

std::vector<std::string> IfStatement::parse(std::string line){
  std::vector<std::string> tokens;

  //remove 'if' and ', then' statement
  size_t index;
  line = line.substr(3);
  index = line.find(",");
  line = line.substr(0, index);
  
  //trim any whitespace
  line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1");

  int encapsulated = 0;

  bool quoted = false;

  std::string buffer = "";

  for(int i = 0; line[i] != 0; i++){
    if(line[i] == ' ' && !encapsulated && !quoted){
        if(buffer.length() && buffer != " "){
          tokens.push_back(buffer);
        }
      buffer = "";
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
  if(buffer.length() && buffer != " "){
    tokens.push_back(buffer);
  }

  return tokens;
}

// OR STATEMENT

bool OrStatement::is_valid(std::string incoming){
  return true;
}

bool OrStatement::write(std::vector<std::string> incoming, std::ofstream& outfile){
  outfile << "else if( ";

  size_t max = incoming.size();

  for(int x = 0; x < max; x++){
    outfile << incoming[x] << " ";
  }

  outfile << "){\n";

  return true;
}

std::vector<std::string> OrStatement::parse(std::string line){
  std::vector<std::string> tokens;

  //remove 'or' and ', then' statement
  size_t index = line.find("if");
  line = line.substr(index + 3);
  index = line.find(",");
  line = line.substr(0, index);
  
  //trim any whitespace
  line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1");

  int encapsulated = 0;

  bool quoted = false;

  std::string buffer = "";

  for(int i = 0; line[i] != 0; i++){
    if(line[i] == ' ' && !encapsulated && !quoted){
      if(buffer.length() && buffer != " "){
        tokens.push_back(buffer);
      }
      buffer = "";
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
  if(buffer.length() && buffer != " "){
    tokens.push_back(buffer);
  }

  return tokens;
}

// ELSE STATEMENT
bool ElseStatement::is_valid(std::string incoming){
  return true;
}

bool ElseStatement::write(std::ofstream& outfile){
  outfile << "else{\n";
  return true;
}

// END STATEMENT

bool EndStatement::is_valid(std::string incoming){
  return true;
}

bool EndStatement::write(std::ofstream& outfile){
  outfile << "}\n";

  return true;
}

bool WhileStatement::is_valid(std::string incoming){
  return true;
}

bool WhileStatement::write(std::string incoming, std::ofstream& outfile){
  outfile 
  << "while("
  << incoming
  << "){\n";

  return true;
}

std::string WhileStatement::parse(std::string line){
  std::vector<std::string> tokens;

  size_t index;
  line = line.substr(6);
  index = line.find(",");
  line = line.substr(0, index);
  
  return line;
}

bool ForStatement::is_valid(std::string incoming){
  return true;
}

bool ForStatement::write(std::vector<std::string> incoming, std::ofstream& outfile){
  outfile 
    << "for( int "
    << incoming[0]
    << " = 0; "
    << incoming[0]
    << " < "
    << incoming[1]
    << "; "
    << incoming[0]
    << "++){\n";
  return true;
}

std::vector<std::string> ForStatement::parse(std::string line){
  std::vector<std::string> tokens;

  line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1");

  size_t index;
  line = line.substr(4);
  index = line.find(" in");

  tokens.push_back(line.substr(0, index));

  line = line.substr(index + 4);

  index = line.find(" ");

  tokens.push_back(line.substr(0, index));
  
  return tokens;
}

bool DoesStatement::is_valid(std::string incoming){
  return true;
}

bool DoesStatement::write(std::ofstream& outfile){
  outfile << "{\n";

  return true;
}