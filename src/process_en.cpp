#include "../include/process_en.hpp"
#include "../include/input_parse_en.hpp"
#include <fstream>
#include <string>

bool if_proper_write_clause(std::vector<std::string> tokens){
  if(tokens.size() < 4){
    return false;
  }else return true;
}

void process_tokens(std::vector<std::string> tokens, std::string output_file_name){
  Verb action = string_to_verb(tokens[0]);
  std::ofstream output_file;

  output_file.open(output_file_name, std::fstream::app);

  switch(action){
    case(write):
      if(if_proper_write_clause(tokens)){
        if(tokens[3] == "console"){
          output_file << "std::cout<<"
                      << tokens[1] 
                      << "<<std::endl;";
        }else{
          output_file << "std::ofstream temp_out;\n"
                      << "temp_out.open(\""
                      << tokens[3]
                      << "\", std::fstream::app); "
                      << "temp_out<<"
                      << tokens[1]
                      << "<<std::endl;"
                      << "temp_out.close();";
        }
      }
  }
  output_file.close();
}