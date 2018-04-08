#ifndef INPUT_PARSE_EN_HPP
#define INPUT_PARSE_EN_HPP

#include <vector>
#include <string>
#include "types_en.hpp"

Verb string_to_verb(std::string command);

Identifier string_to_identifier(std::string command);

std::vector<std::string> tokenize(std::string input);
std::vector<std::string> manual_token(std::string input);

bool valid_command(std::string command);

#endif