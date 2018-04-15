#ifndef IO_HPP
#define IO_HPP

#include <fstream>
#include <vector>
#include <string>

class WriteStatement{
  public:
  bool is_valid(std::string line);

  std::vector<std::string> parse(std::string line);

  bool write(std::vector<std::string> tokens, std::ofstream& outfile);
};

class PutStatement{
  public:
  bool is_valid(std::string line);

  std::vector<std::string> parse(std::string line);

  bool write(std::vector<std::string> tokens, std::ofstream& outfile);
};

class OpenStatement{
  public:
  bool is_valid(std::string line);

  std::vector<std::string> parse(std::string line);

  bool write(std::vector<std::string> tokens, std::ofstream& outfile);
};

class AppendStatement{
  public:
  bool is_valid(std::string line);

  std::vector<std::string> parse(std::string line);

  bool write(std::vector<std::string> tokens, std::ofstream& outfile);
};

class CloseStatement{
  public:
  bool is_valid(std::string line);

  std::string parse(std::string line);

  bool write(std::string filename, std::ofstream& outfile);
};

#endif