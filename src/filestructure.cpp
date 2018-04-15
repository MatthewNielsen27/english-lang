#include "../include/filestructure.hpp"

void write_closing(std::ofstream& output_file){
  output_file << "\n}\n";
}

void write_headers(std::ofstream& output_file){
  output_file 
    << "//English lang compiler version 1.0\n"
    << "#include <iostream>\n"
    << "#include <vector>\n"
    << "#include <string>\n"
    << "#include <fstream>\n"
    << "#include <float.h>\n\n";
}

void write_main(std::ofstream& output_file){
  output_file
    << "int main(){\n";
}