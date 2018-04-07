#include <regex>
#include "../include/input_parse_en.hpp"

Verb string_to_verb(std::string command){
  Verb interpreted = unknown_verb;

  std::transform(command.begin(), command.end(), command.begin(), ::tolower);

  if(command == "write")        {  interpreted =  write; }
  else if(command == "add")     {  interpreted =  add;   }

  return interpreted;
}

Identifier string_to_identifier(std::string command){
  Identifier interpreted = unknown_identifier;

  std::transform(command.begin(), command.end(), command.begin(), ::tolower);

  if(command == "to")            {  interpreted =  to;     }
  if(command == "equals")        {  interpreted =  equals; }

  return interpreted;
}

std::vector<std::string> tokenize(std::string input){
  input = std::regex_replace(input, std::regex("^ +| +$|( ) +"), "$1");
  std::string buffer = input;
  std::string buffer2;
  std::vector<std::string> tokens;

  size_t index = 0;
  int count = 0;

  std::string quote = "\"";
  while(index != std::string::npos){
    std::string temp;
    if(buffer[0] != 34){
      index = buffer.find(" ");

      temp = buffer.substr(0, index);

      buffer = buffer.substr(index + 1);

      tokens.push_back(temp);
    }else if(buffer[0] == 34){
      buffer2 = buffer.substr(1);

      index = buffer2.find("\"");

      if(index != std::string::npos){
        temp = buffer.substr(0, index + 2);

        buffer = buffer.substr(index + 3);

        tokens.push_back(temp);
      }else{
        tokens.push_back("@English_Error: Missing \" in string input");
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