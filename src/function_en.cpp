#include "../include/function_en.hpp"
#include <fstream>

std::string get_return_value(std::string value){
  if(value == "nothing"){
    return "void";
  }else return value;
}

void define_function(
  std::string filename,
  std::vector<std::string> name,
  std::vector<std::string> takes,
  std::vector<std::string> returns)
{
  std::ofstream output_file;
  output_file.open(filename, std::fstream::app);

  output_file
    << get_return_value(returns[1])
    << " "
    << name[1]
    <<"(";
  
  if(takes[1] != "nothing"){
    for(int i = 1; i < takes.size(); i++){
      size_t pos = takes[i].find(":");
      std::string type = takes[i].substr(0, pos - 1);
      std::string type_name = takes[i].substr(pos + 1);

      output_file
        << type
        << " "
        << type_name;

      if(i != takes.size() - 1){
        output_file
          <<", ";
      }
    }
  }

  output_file 
    <<"){\n";
  output_file.close();
}