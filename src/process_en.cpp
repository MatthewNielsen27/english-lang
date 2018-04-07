#include "../include/process_en.hpp"
#include "../include/input_parse_en.hpp"
#include <fstream>
#include <string>
#include <iostream>

std::string get_comparator(std::string key){
  std::string val = "";
  if(key == "equals"){
    val = "==";
  }else if(key == "does-not-equal"){
    val = "!=";
  }else if(key == "is-greater-than"){
    val = ">=";
  }else if(key == "is-less-than"){
    val = "<=";
  }
  return val;
}

bool proper_write_clause(std::vector<std::string> tokens){
  if(tokens.size() != 4){
    return false;
  }else return true;
}

bool proper_create_clause(std::vector<std::string> tokens){
  if(tokens.size() != 3){
    return false;
  }else return true;
}

bool proper_create_assign_clause(std::vector<std::string> tokens){
  if(tokens.size() != 6){
    return false;
  }else return true;
}

bool proper_set_clause(std::vector<std::string> tokens){
  if(tokens.size() != 5){
    return false;
  }else return true;
}

bool proper_add_clause(std::vector<std::string> tokens){
  if(tokens.size() != 4){
    return false;
  }else return true;
}

bool proper_subtract_clause(std::vector<std::string> tokens){
  if(tokens.size() != 4){
    return false;
  }else return true;
}

bool proper_multiply_clause(std::vector<std::string> tokens){
  if(tokens.size() != 4){
    return false;
  }else return true;
}

bool proper_divide_clause(std::vector<std::string> tokens){
  if(tokens.size() != 4){
    return false;
  }else return true;
}

bool proper_if_clause(std::vector<std::string> tokens){
  if(tokens.size() != 5){
    return false;
  }else return true;
}

bool proper_elseif_clause(std::vector<std::string> tokens){
  if(tokens.size() != 5){
    return false;
  }else return true;
}

bool proper_else_clause(std::vector<std::string> tokens){
  if(tokens.size() != 1){
    return false;
  }else return true;
}

bool proper_end_clause(std::vector<std::string> tokens){
  if(tokens.size() != 1){
    return false;
  }else return true;
}

bool proper_for_loop_clause(std::vector<std::string> tokens){
  if(tokens.size() != 6){
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
      }else{
        std::cout<<"@English_Error: improper write clause"<<std::endl;
      }
      break;
    case(put):
      if(proper_write_clause(tokens)){
        if(tokens[3] == "console"){
          output_file 
            << "std::cout<<"
            << tokens[1]
            << ";\n";
        }else{
          output_file
            << "temp_out.open(\""
            << tokens[3]
            << "\", std::fstream::app);\n"
            << "temp_out<<"
            << tokens[1]
            << ";\n"
            << "temp_out.close();\n";
        }
      }else{
        std::cout<<"@English_Error: improper write clause"<<std::endl;
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
          }else if(tokens[1] == "integer-list"){
            output_file
              << "std::vector<int> "
              << tokens[2]
              << ";\n";
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
          }else if(tokens[1] == "integer-list"){
            output_file
              << "int "
              << tokens[2]
              << "[] = "
              << tokens[5]
              << ";\n";
          }
      }else{
        std::cout<<"@English_Error: improper create clause"<<std::endl;
      }
      break;
    case(set):
      if(proper_set_clause(tokens)){
        output_file
          << tokens[1]
          << " = "
          << tokens[4]
          << ";\n";
      }else{
        std::cout<<"@English_Error: improper set clause"<<std::endl;
      }
      break;
    case(add):
      if(proper_add_clause(tokens)){
        output_file
          << tokens[1]
          << " += "
          << tokens[3]
          << ";\n";
      }else{
        std::cout<<"@English_Error: improper add clause"<<std::endl;
      }
      break;
    case(subtract):
      if(proper_subtract_clause(tokens)){
        output_file
          << tokens[1]
          << " -= "
          << tokens[3]
          << ";\n";
      }else{
        std::cout<<"@English_Error: improper subtract clause"<<std::endl;
      }
      break;
    case(multiply):
      if(proper_multiply_clause(tokens)){
        output_file
          << tokens[1]
          << " *= "
          << tokens[3]
          << ";\n";
      }else{
        std::cout<<"@English_Error: improper multiply clause"<<std::endl;
      }
      break;
    case(divide):
      if(proper_divide_clause(tokens)){
        output_file
          << tokens[1]
          << " /= "
          << tokens[3]
          << ";\n";
      }else{
        std::cout<<"@English_Error: improper divide clause"<<std::endl;
      }
      break;
    case(if_cond):
      if(proper_if_clause(tokens)){
        output_file
          << "if("
          << tokens[1]
          << get_comparator(tokens[2])
          << tokens[3]
          << "){\n";
      }else{
        std::cout<<"@English_Error: improper if clause"<<std::endl;
      }
      break;
    case(elseif_cond):
      if(proper_elseif_clause(tokens)){
        output_file
          << "else if("
          << tokens[1]
          << get_comparator(tokens[2])
          << tokens[3]
          << "){\n";
      }else{
        std::cout<<"@English_Error: improper else-if clause"<<std::endl;
      }
      break;
    case(else_cond):
      if(proper_else_clause(tokens)){
        output_file
          << "else{\n";
      }else{
        std::cout<<"@English_Error: improper else clause"<<std::endl;
      }
      break;
    case(end_cond):
      if(proper_end_clause(tokens)){
        output_file
          << "}\n";
      }else{
        std::cout<<"@English_Error: improper end clause"<<std::endl;
      }
      break;
    case(end_line):
      if(proper_end_clause(tokens)){
        output_file
          << "std::cout<<std::endl;\n";
      }else{
        std::cout<<"@English_Error: improper end clause"<<std::endl;
      }
      break;
    case(for_loop):
      if(proper_for_loop_clause(tokens)){
        output_file
          << "for(int "
          << tokens[1]
          << "= 0; "
          << tokens[1]
          << "< "
          << tokens[3]
          << "; "
          << tokens[1]
          << "++){\n";
      }else{
        std::cout<<"@English_Error: improper for-loop clause"<<std::endl;
      }
      break;
    case(unknown_verb):
      std::cout<<"@English_Error: unknown clause found"<<std::endl;
  }
  output_file.close();
}