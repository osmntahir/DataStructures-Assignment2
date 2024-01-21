#ifndef READER_HPP
#define READER_HPP
#include "List.hpp"
#include <fstream>
#include <sstream>
class FileReader
{
private:
  
public:
    FileReader(/* args */);
    List * Trees;
    void Start();
  
    void ReadFile();
    ~FileReader();
};




#endif