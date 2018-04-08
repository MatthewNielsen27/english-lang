#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../include/input_parse_en.hpp"
#include "../include/process_en.hpp"
#include "../include/function_en.hpp"

bool file_exists(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}

bool valid_function(
  std::vector<std::string> name, 
  std::vector<std::string> takes,
  std::vector<std::string> returns, 
  std::vector<std::string> does)
{
  bool state = true;
  if(name[0] != "function" || (name[1] == " " || name[1] == "")){
    std::cerr<<"@English_Error: improper function name\n";
    return false;
  }
  if(takes[0] != "takes" || takes.size() < 2){
    std::cerr<<"@English_Error: improper function params\n";
    return false;
  }
  if(returns[0] != "returns" || returns.size() < 2){
    std::cerr<<"@English_Error: improper function return\n";
    return false;
  }
  if(does[0] != "does" || does.size() != 1){
    std::cerr<<"@English_Error: improper function does\n";
    return false;
  }
  return true;
}

void write_closing(std::string filename){
  std::ofstream output_file;
  output_file.open(filename, std::fstream::app);
  
  //Finish the output file
  output_file << "\n}\n";
  output_file.close();
}

void write_headers(std::string filename){
  std::ofstream output_file;
  output_file.open(filename);

  //Write hash includes and start main function
  output_file 
    << "//English lang compiler version 1.0\n"
    << "#include <iostream>\n"
    << "#include <vector>\n"
    << "#include <string>\n"
    << "#include <fstream>\n"
    << "#include <float.h>\n\n";
  output_file.close();
}

void write_main(std::string filename){
  std::ofstream output_file;
  output_file.open(filename, std::fstream::app);
  output_file
    << "int main(){\n"
    << "std::ofstream temp_out;\n";
  output_file.close();
}

int main(const int argc, const char *argv[]){
  //Error checking the inputs
  if(argc < 2){
    std::cerr<<"@English_Error: please enter a file to compile\n";
    return 1;
  }else if(!file_exists(argv[1])){
    std::cerr<<"@English_Error: file not found\n";
    return 1;
  }

  //Start the input file
  std::string source_file = argv[1];
  std::ifstream input_file;
  input_file.open(source_file);

  //Start the output file
  std::string destination_file = source_file.substr(0, source_file.find(".english")) + ".cpp";

  write_headers(destination_file);
  
  bool main_reached = false;
  bool functions_reached = false;

  std::string incoming_line;
  size_t line_count = 0;

  //Read each line and interpret it
  while( !input_file.eof() )
  {
      line_count++;
      getline( input_file, incoming_line );
      std::vector<std::string> tokens = manual_token(incoming_line);

      if(tokens[0] == "@functions"){
        functions_reached = true;
      }else if(tokens[0] == "@main"){
        main_reached = true;
        write_main(destination_file);
      }else if(valid_command(tokens[0])){
        if(tokens[0] == "function"){
          getline( input_file, incoming_line );
          std::vector<std::string> takes = manual_token(incoming_line);
          getline( input_file, incoming_line );
          std::vector<std::string> returns = manual_token(incoming_line);
          getline( input_file, incoming_line );
          std::vector<std::string> does = manual_token(incoming_line);
          if(valid_function(tokens, takes, returns, does)){
            define_function(destination_file, tokens, takes, returns);
          }else{
            std::cerr<<"@English_Error: improper function declaration: "<<tokens[0]<<std::endl;
            std::cerr<<"@English_Error: on line "<<line_count<<std::endl;
          }
        }else{
          process_tokens(tokens, destination_file);
        }
      }else if(tokens[0].length() > 0){
        std::cerr<<"@English_Error: improper statement: "<<tokens[0]<<std::endl;
        std::cerr<<"@English_Error: on line "<<line_count<<std::endl;
      }
  }

  if(main_reached){
    write_closing(destination_file);
  }else{
    std::cerr<<"@English_Error: no main script found: expecting @main tag before main program"<<std::endl;
    return 1;
  }

  return 0;
}