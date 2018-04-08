//English lang compiler version 1.0
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <float.h>

int main(){
std::ofstream temp_out;
std::cout<<"--counting up on one line--"<<std::endl;
for(int counter= 0; counter< 10; counter++){
std::cout<<counter;
std::cout<<" ";
}
std::cout<<std::endl;
std::string name = "matthew";
std::cout<<"--iterating over characters in a word--"<<std::endl;
for(int x= 0; x< name.length(); x++){
std::cout<<name[x];
}
std::cout<<std::endl;
int index = 100000;
std::cout<<"--counting down on seperate lines--"<<std::endl;
for(int x= 0; x< index; x++){
std::cout<<x<<std::endl;
}

}
