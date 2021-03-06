#include "../include/translate.hpp"
#include "../include/control_flow.hpp"
#include "../include/io.hpp"
#include "../include/native.hpp"
#include "../include/variables.hpp"
#include "../include/function.hpp"
#include "../include/data_structure.hpp"

#include <vector>

enum CommandType{
  _undefiend,
  _inject,
  _if,
  _or,
  _else,
  _create,
  _perform,
  _write,
  _put,
  _open,
  _set,
  _function,
  _does,
  _end,
  _close,
  _append,
  _for,
  _while,
  _return,
  _structure,
  _class_structure,
  _end_structure,
  _privacy,
  _constructor
};

CommandType translate(std::string const& inString){
  CommandType val = _undefiend;
  if(inString == "if") { val = _if; }
  else if(inString == "else-if") { val = _or;}
  else if(inString == "else") { val = _else;}
  else if(inString == "create") { val = _create;}
  else if(inString == "perform") { val = _perform;}
  else if(inString == "write") { val = _write;}
  else if(inString == "put") { val = _put;}
  else if(inString == "open") { val = _open;}
  else if(inString == "close") { val = _close;}
  else if(inString == "append") { val = _append;}
  else if(inString == "set") { val = _set;}
  else if(inString == "function") { val = _function;}
  else if(inString == "does") { val = _does;}
  else if(inString == "end") { val = _end;}
  else if(inString == "for") { val = _for;}
  else if(inString == "while") { val = _while;}
  else if(inString == "cpp->") {val = _inject;}
  else if(inString == "return") {val = _return;}
  else if(inString == "structure") {val = _structure;}
  else if(inString == "class-structure") {val = _class_structure;}
  else if(inString == "end-structure") {val = _end_structure;}
  else if(inString == "privacy:") {val = _privacy;}
  else if(inString == "constructor") {val = _constructor;}
  return val;
}

int translate_command_from(std::string initial_token, std::string line, std::ofstream& outfile, std::ifstream& infile){
  CommandType identifier = translate(initial_token);
  int status = 0;
  switch(identifier){
    case(_if):
      IfStatement if_statement;
      if(if_statement.is_valid(line)){
        std::vector<std::string> tokens = if_statement.parse(line);
        if_statement.write(tokens, outfile);
      }else{
        status = 1;
      }
      break;
    case(_or):
      OrStatement or_statement;
      if(or_statement.is_valid(line)){
        std::vector<std::string> tokens = or_statement.parse(line);
        or_statement.write(tokens, outfile);
      }else{
        status = 1;
      }
      break;
    case(_else):
      ElseStatement else_statement;
      if(else_statement.is_valid(line)){
        else_statement.write(outfile);
      }else{
        status = 1;
      }
      break;
    case(_does):
      DoesStatement does_statement;
      if(does_statement.is_valid(line)){
        does_statement.write(outfile);
      }else{
        status = 1;
      }
      break;
    case(_end):
      EndStatement end_statement;
      if(end_statement.is_valid(line)){
        end_statement.write(outfile);
      }else{
        status = 1;
      }
      break;
    case(_write):
      WriteStatement write_statement;
      if(write_statement.is_valid(line)){
        std::vector<std::string> tokens = write_statement.parse(line);
        write_statement.write(tokens, outfile);
      }else{
        status = 1;
      }
      break;
    case(_put):
      PutStatement put_statement;
      if(put_statement.is_valid(line)){
        std::vector<std::string> tokens = put_statement.parse(line);
        put_statement.write(tokens, outfile);
      }else{
        status = 1;
      }
      break;
    case(_create):
      CreateStatement create_statement;
      if(create_statement.is_valid(line)){
        std::vector<std::string> tokens = create_statement.parse(line);
        create_statement.write(tokens, outfile);
      }else{
        status = 1;
      }
      break;
    case(_open):
      OpenStatement open_statement;
      if(open_statement.is_valid(line)){
        std::vector<std::string> tokens = open_statement.parse(line);
        open_statement.write(tokens, outfile);
      }else{
        status = 1;
      }
      break;
    case(_append):
      AppendStatement append_statement;
      if(create_statement.is_valid(line)){
        std::vector<std::string> tokens = append_statement.parse(line);
        append_statement.write(tokens, outfile);
      }else{
        status = 1;
      }
      break;
    case(_close):
      CloseStatement close_statement;
      if(close_statement.is_valid(line)){
        std::string filename = close_statement.parse(line);
        close_statement.write(filename, outfile);
      }else{
        status = 1;
      }
      break;
    case(_while):
      WhileStatement while_statement;
      if(while_statement.is_valid(line)){
        std::string cond = while_statement.parse(line);
        while_statement.write(cond, outfile);
      }else{
        status = 1;
      }
      break;
    case(_for):
      ForStatement for_statement;
      if(for_statement.is_valid(line)){
        std::vector<std::string> tokens = for_statement.parse(line);
        for_statement.write(tokens, outfile);
      }else{
        status = 1;
      }
      break;
    case(_set):
      SetStatement set_statement;
      if(set_statement.is_valid(line)){
        std::vector<std::string> tokens = set_statement.parse(line);
        set_statement.write(tokens, outfile);
      }else{
        status = 1;
      }
      break;
    case(_inject):
      InjectStatement inject_statement;
      if(inject_statement.is_valid(line)){
        std::string native_command = inject_statement.parse(line);
        inject_statement.write(native_command, outfile);
      }else{
        status = 1;
      }
      break;
    case(_perform):
      PerformStatement perform_statement;
      if(perform_statement.is_valid(line)){
        std::string native_command = perform_statement.parse(line);
        perform_statement.write(native_command, outfile);
      }else{
        status = 1;
      }
      break;
    case(_return):
      ReturnStatement return_statement;
      if(return_statement.is_valid(line)){
        std::string native_command = return_statement.parse(line);
        return_statement.write(native_command, outfile);
      }else{
        status = 1;
      }
      break;
    case(_function):
      FunctionStatement function_statement;
      if(function_statement.is_valid(line)){
        std::vector<std::string> tokens = function_statement.parse(line, infile);
        function_statement.write(tokens, outfile);
      }else{
        status = 1;
      }
      break;
    case(_structure):
      StructureStatement structure_statement;
      if(structure_statement.is_valid(line)){
        std::string name = structure_statement.parse(line);
        structure_statement.write(name, outfile);
      }else{
        status = 1;
      }
      break;
    case(_class_structure):
      ClassStructureStatement class_structure_statement;
      if(class_structure_statement.is_valid(line)){
        std::string name = class_structure_statement.parse(line);
        class_structure_statement.write(name, outfile);
      }else{
        status = 1;
      }
      break;
    case(_privacy):
      PrivacyStatement privacy_statement;
      if(class_structure_statement.is_valid(line)){
        std::string name = class_structure_statement.parse(line);
        class_structure_statement.write(name, outfile);
      }else{
        status = 1;
      }
      break;
    case(_end_structure):
      EndStructureStatement endstructure_statement;
      if(endstructure_statement.is_valid(line)){
        endstructure_statement.write(outfile);
      }else{
        status = 1;
      }
      break;
    case(_constructor):
      ConstructorStatement constructor_statement;
      if(constructor_statement.is_valid(line)){
        std::vector<std::string> tokens = constructor_statement.parse(line, infile);
        constructor_statement.write(tokens, outfile);
      }else{
        status = 1;
      }
      break;
  }
  return status;
}