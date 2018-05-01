#ifndef TRANSLATE_HPP
#define TRANSLATE_HPP

#include <fstream>
#include <string>

int translate_command_from(std::string token, std::string line, std::ofstream& outfile, std::ifstream& infile);

#endif