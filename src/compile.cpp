//////////////////////////////////////
// English_lang compiler            //
// Written by: matthew nielsen      //
// Start:                           //
// Last edit:                       //
//////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include "../include/translate.hpp"
#include "../include/filestructure.hpp"
#include "../include/control_flow.hpp"

bool file_exists(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}

void close_filestreams(std::vector<std::string> streams, std::ofstream& output_file){
  for(size_t i = 0; i < streams.size(); i++){
      output_file
      << streams[i]
      <<".close();\n";
  }

  output_file.close();
}

bool is_valid_command(std::string incoming){
  return true;
}

int main(const int argc, const char *argv[]){
  
  //////////////////////////////
  //  Argument error checking //
  //////////////////////////////

  if(argc < 2){
    std::cerr<<"@Plain-English: Error: please enter a file to compile\n";
    return 1;
  }else if(!file_exists(argv[1])){
    std::cerr<<"@Plain-English: Error: file not found\n";
    return 1;
  }

  ////////////////////////////
  //  Variable declaration  //
  ////////////////////////////

  //Checkpoints in .english source file
  bool main_reached = false;
  bool routines_reached = false;
  bool constants_reached = false;

  //The string containing the incoming line
  std::string incoming_line;

  //Which line of the source file we are on
  size_t line_count = 0;

  //The name of the input file
  std::string source_file = argv[1];

  //The name of the destination file
  std::string destination_file = source_file.substr(0, source_file.find(".english")) + ".cpp";

  //The input file stream
  std::ifstream input_file;

  //Destination filestreams
  std::vector<std::string> INPUT_STREAMS;
  std::vector<std::string> OUTPUT_STREAMS;

  //Conversion mapping initiation
  //init_type_lookup();

  //////////////////////////
  //  File interpretation //
  //////////////////////////

  //Start the input file
  input_file.open(source_file);

  std::ofstream outfile;

  outfile.open(destination_file);

  //Write output file headers
  write_headers(outfile);
  //Read each line and interpret it
  while( !input_file.eof() )
  {
    line_count++;

    getline( input_file, incoming_line );
    incoming_line = std::regex_replace(incoming_line, std::regex("^ +| +$|( ) +"), "$1");
    
    std::string token = incoming_line.substr(0, incoming_line.find(' '));

    if(is_valid_command(token) && token[0] != '#'){
      if(token == "@script"){
        write_main(outfile);
        main_reached = true;
      }else if(token == "@routines"){
        routines_reached = true;
      }else{
        translate_command_from(token, incoming_line, outfile);
      }
    }else{
      std::cout << "@Plain_English: Error: Unknown command on line " << line_count << "\n";
    }
  }

  // If there was a main script found:
  // add the final curly brace to the destination file
  if(main_reached){
    write_closing(outfile);
  }else{
    std::cerr<<"@Plain-English: Error: no main script found: expecting @script tag before main program"<<"\n";
    return 1;
  }
  outfile.close();
  return 0;
}