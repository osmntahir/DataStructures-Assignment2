#ifndef LIST_HPP
#define LIST_HPP

#include "AvlTree.hpp"

class List
{
private:
   AvlTree * firstTree;
   int treeCount;
   int avlNo;
   int choice;
   void  backUpStacks();
public:
    List(/* args */);
    void addTree(AvlTree *newTree);
   AvlTree* findMinTopfromStacks();
   AvlTree* findMaxTopFromStacks();
   bool isDeleted;
   void printTrees();
   void start();
   int getAvlTreeCount();
   void executeStack(AvlTree * executeToTree);

    ~List();
};


#endif