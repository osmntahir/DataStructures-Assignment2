/** 
* @file -->main.cpp
* @description -->Programın test edildiği main dosyası
* @assignment 2
* @date 15/12/2023
* @author Osman Tahir Özdemir  osman.ozdemir3@ogr.sakarya.edu.tr  ya da ozdemirosmantahir@gmail.com
*/


#include "AvlTree.hpp"
#include "Stack.hpp"
#include "FileReader.hpp"
int main(){
FileReader *reader = new FileReader();
reader->ReadFile();
reader->Trees->printTrees();
while(reader->Trees->getAvlTreeCount()!=1)
{
	reader->Start();
}
delete reader;
 std::cout << "\n\nPress any key to exit." << std::endl;
  cin.get();
   
	return 0;
}