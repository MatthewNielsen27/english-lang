#ifndef CONTROLFLOW_HPP
#define CONTROLFLOW_HPP

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class IfStatement{
  public:
  bool is_valid(std::string incoming);

  std::vector<std::string> parse(std::string incoming);

  bool write(std::vector<std::string> incoming, std::ofstream& outfile);
};

class OrStatement{
  public:
  bool is_valid(std::string incoming);

  std::vector<std::string> parse(std::string incoming);

  bool write(std::vector<std::string> incoming, std::ofstream& outfile);
};

class ElseStatement{
  public:
  bool is_valid(std::string incoming);

  bool write(std::ofstream& outfile);
};

class EndStatement{
  public:
  bool is_valid(std::string incoming);

  bool write(std::ofstream& outfile);
};

class ForStatement{
  public:
  bool is_valid(std::string incoming);

  std::vector<std::string> parse(std::string incoming);

  bool write(std::vector<std::string> incoming, std::ofstream& outfile);
};

class WhileStatement{
  public:
  bool is_valid(std::string incoming);

  std::string parse(std::string incoming);

  bool write(std::string incoming, std::ofstream& outfile);
};

std::string to_operator(std::string incoming);

#endif