/** 
* @file -->Node.cpp
* @description -->Txt deki her bir sayıyı tutan düğüm sınıfı
* @assignment 2
* @date 10/12/2023
* @author Osman Tahir Özdemir  osman.ozdemir3@ogr.sakarya.edu.tr  ya da ozdemirosmantahir@gmail.com
*/

#include "Node.hpp"

Node::Node(const int& value) 
{
    this->data =value;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 0;
}

Node::~Node()
{
   
}
