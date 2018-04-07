#include <regex>
#include "../include/input_parse_en.hpp"
#include <iostream>

Identifier string_to_identifier(std::string command){
  Identifier interpreted = unknown_identifier;

  std::transform(command.begin(), command.end(), command.begin(), ::tolower);

  if(command == "to")            {  interpreted =  to;     }
  if(command == "equals")        {  interpreted =  equals; }

  return interpreted;
}

//Function to convert string command to Verb enum
std::vector<std::string> manual_token(std::string input){
  std::vector<std::string> tokens;
  std::string temp = "";
  bool encapsulated = false;
  bool list = false;
  input = std::regex_replace(input, std::regex("^ +| +$|( ) +"), "$1");

  for(int i = 0; input[i] != 0; i++){
    if(input[i] == 32 && !encapsulated && !list){
      if(temp != " "){
        tokens.push_back(temp);
      }
      temp = "";
    }else if(input[i] == 34){
      encapsulated = !encapsulated;

      temp += input[i];
    }else if(input[i] == 123){
      list = true;
      temp += input[i];
    }else if(input[i] == 125){
      list = false;
      temp += input[i];
    }
    else{
      temp+=input[i];
    }
  }
  tokens.push_back(temp);

  return tokens;
}

//Function to convert string command to Verb enum
Verb string_to_verb(std::string command){
  Verb interpreted = unknown_verb;

  std::transform(command.begin(), command.end(), command.begin(), ::tolower);

  if(command == "write")              {  interpreted =  write;        }
  else if(command == "put")           {  interpreted =  put;          }
  else if(command == "end-line")      {  interpreted =  end_line;     }
  else if(command == "add")           {  interpreted =  add;          }
  else if(command == "create")        {  interpreted =  create;       }
  else if(command == "set")           {  interpreted =  set;          }
  else if(command == "subtract")      {  interpreted =  subtract;     }
  else if(command == "multiply")      {  interpreted =  multiply;     }
  else if(command == "divide")        {  interpreted =  divide;       }
  else if(command == "if")            {  interpreted =  if_cond;      }
  else if(command == "else-if")       {  interpreted =  elseif_cond;  }
  else if(command == "else")          {  interpreted =  else_cond;    }
  else if(command == "end")           {  interpreted =  end_cond;     }
  else if(command == "for")           {  interpreted =  for_loop;     }

  return interpreted;
}

//Function to determine if a command is suported
bool valid_command(std::string command){
  bool status = false;

  if(command == "write")              {  status = true;   }
  else if(command == "put")           {  status = true;   }
  else if(command == "end-line")      {  status = true;   }
  else if(command == "set")           {  status = true;   }
  else if(command == "create")        {  status = true;   }
  else if(command == "add")           {  status = true;   }
  else if(command == "subtract")      {  status = true;   }
  else if(command == "multiply")      {  status = true;   }
  else if(command == "divide")        {  status = true;   }
  else if(command == "if")            {  status = true;   }
  else if(command == "else-if")       {  status = true;   }
  else if(command == "else")          {  status = true;   }
  else if(command == "end")           {  status = true;   }
  else if(command == "for")           {  status = true;   }

  return status;
}