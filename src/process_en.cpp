#include "../include/process_en.hpp"
#include "../include/input_parse_en.hpp"
#include <fstream>
#include <string>
#include <iostream>

bool proper_write_clause(std::vector<std::string> tokens){
  if(tokens.size() < 4){
    return false;
  }else return true;
}

bool proper_create_clause(std::vector<std::string> tokens){
  if(tokens.size() != 3){
    return false;
  }else return true;
}

bool proper_create_assign_clause(std::vector<std::string> tokens){
  if(tokens.size() < 6){
    return false;
  }else return true;
}

void process_tokens(std::vector<std::string> tokens, std::string output_file_name){
  Verb action = string_to_verb(tokens[0]);

  std::ofstream output_file;
  std::cout<<"Analyzing token "<<action<<std::endl;
  output_file.open(output_file_name, std::fstream::app);

  switch(action){
    case(write):
      if(proper_write_clause(tokens)){
        if(tokens[3] == "console"){
          output_file 
            << "std::cout<<"
            << tokens[1]
            << "<<std::endl;\n";
        }else{
          output_file
            << "temp_out.open(\""
            << tokens[3]
            << "\", std::fstream::app);\n"
            << "temp_out<<"
            << tokens[1]
            << "<<std::endl;\n"
            << "temp_out.close();\n";
        }
      }
      break;
    case(create):
      if(proper_create_clause(tokens)){
          if(tokens[1] == "integer"){
            output_file 
              << "int "
              << tokens[2] 
              << " = 0;\n";
          }else if(tokens[1] == "float"){
            output_file 
              << "float "
              << tokens[2]
              << " = 0;";
          }else if(tokens[1] == "string"){
            output_file 
              << "std::string "
              << tokens[2]
              << " = \"\";";
          }
      }else if(proper_create_assign_clause(tokens)){
          if(tokens[1] == "integer"){
            output_file 
              << "int "
              << tokens[2] 
              << " = "
              << tokens[5] 
              << ";\n";
          }else if(tokens[1] == "float"){
            output_file 
              << "float "
              << tokens[2] 
              << " = "
              << tokens[5]
              << ";\n";
          }else if(tokens[1] == "string"){
            output_file 
              << "std::string "
              << tokens[2]
              << " = "
              << tokens[5]
              << ";\n";
          }
      }
      break;
  }
  output_file.close();
}