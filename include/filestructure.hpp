#ifndef FILESTRUCTURE_HPP
#define FILESTRUCTURE_HPP

#include <string>
#include <fstream>

void write_closing(std::ofstream& output_file);

void write_headers(std::ofstream& output_file);

void write_main(std::ofstream& output_file);

#endif 