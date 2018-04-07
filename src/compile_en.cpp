#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include "../include/input_parse_en.hpp"
#include "../include/process_en.hpp"

bool file_exists(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
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
  std::ofstream output_file;
  output_file.open(destination_file);
  output_file << "//English lang compiler version 1.0\n";
  output_file << "#include <iostream>\n#include <fstream>\n int main(){\n";
  output_file.close();
  std::string incoming_line;
  size_t line_count = 0;

  //Read each line and interpret it
  while( !input_file.eof() )
  {
      line_count++;
      getline( input_file, incoming_line );
      std::vector<std::string> tokens = tokenize(incoming_line);

      if(valid_command(tokens[0])){
        process_tokens(tokens, destination_file);
      }else{
        std::cerr<<"@English_Error: improper structure on line "<<line_count<<std::endl;
      }
  }

  output_file.open(destination_file, std::fstream::app);
  //Finish the output file
  output_file << "\n}\n";
  output_file.close();

  return 0;
}