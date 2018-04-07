#include <regex>
#include "../include/input_parse_en.hpp"
#include <iostream>
Verb string_to_verb(std::string command){
  Verb interpreted = unknown_verb;

  std::transform(command.begin(), command.end(), command.begin(), ::tolower);

  if(command == "write")        {  interpreted =  write; }
  else if(command == "add")     {  interpreted =  add;   }
  else if(command == "if")     {  interpreted =  conditional;   }
  else if(command == "create")     {  interpreted =  create;   }
  else if(command == "set")     {  interpreted =  create;   }

  return interpreted;
}

Identifier string_to_identifier(std::string command){
  Identifier interpreted = unknown_identifier;

  std::transform(command.begin(), command.end(), command.begin(), ::tolower);

  if(command == "to")            {  interpreted =  to;     }
  if(command == "equals")        {  interpreted =  equals; }

  return interpreted;
}

std::vector<std::string> manual_token(std::string input){
  input = std::regex_replace(input, std::regex("^ +| +$|( ) +"), "$1");
  std::cout<<input<<std::endl;

  std::vector<std::string> tokens;

  bool encapsulated = false;
  std::string temp = "";
  for(int i = 0; input[i] != 0; i++){
    
    if(input[i] == 32 && !encapsulated){
      tokens.push_back(temp);
      temp = "";
    }else if(input[i] == 34){
      if(encapsulated){
        encapsulated = false;
      }else{
        encapsulated = true;
      } 
      temp += input[i];
    }else{
      temp+=input[i];
    }
  }
  tokens.push_back(temp);
  for(int i = 0; i < tokens.size(); i++){
     std::cout<<tokens[i]<<std::endl;
  }
  return tokens;
}

std::vector<std::string> tokenize(std::string input){
  input = std::regex_replace(input, std::regex("^ +| +$|( ) +"), "$1");
  std::string buffer = input;
  std::string buffer2;
  std::vector<std::string> tokens;

  size_t index = 0;
  int count = 0;

  std::string quote = "\"";
  while(index != std::string::npos && buffer.length() != 0){
    std::string temp;
    index = 0;
    if(buffer[0] != 34){
      index = buffer.find(" ");
      
      temp = buffer.substr(0, index);

      buffer = buffer.substr(index + 1);
      
      if(temp != " "){
        tokens.push_back(temp);
      }
    }else if(buffer[0] == 34){
      buffer2 = buffer.substr(1);
      
      index = buffer2.find("\"");

      if(index != std::string::npos){
        temp = buffer.substr(0, index + 2);

        buffer = buffer.substr(index + 3);
        
        if(temp != " "){
          tokens.push_back(temp);
        }
      }
    }
  }
  return tokens;
}

bool valid_command(std::string command){
  bool status = false;
  if(command == "write")        {  status = true; }
  else if(command == "add")     {  status = true;   }
  else if(command == "if")      {  status = true;   }
  else if(command == "set")     {  status = true;   }
  else if(command == "create")  {  status = true;   }
  return status;
}