#ifndef AVLTREE_HPP
#define AVLTREE_HPP
#include "Node.hpp"
#include "Stack.hpp"
#include <math.h>
#include <iostream>
using namespace std;
class AvlTree{
	private:	
		Node *root;
		Node* SearchAndAdd(Node*subNode,const int& item);
		Node* SwapWithLeftChild(Node *subNode);
		Node* SwapWithRightChild(Node*subNode);
		bool DeleteNode(Node*&subNode);
		void postorder(Node *subNode);
		int Height(Node *subNode);
		bool Search(Node *subNode,const int& item);
		AvlTree(const AvlTree& other);
	public:
		AvlTree();
		Stack * stack;
		Stack* tempStack;
		int sumNode;
		char Ascii;
		int AvlNo;
		AvlTree *nextTree;
		void sumNodeToAscii();
		bool isEmpty()const;
		void Add(const int& item);
		void postorder();
		int Height();
		bool Search(const int& item);
		void Clear();
		~AvlTree();
};

#endif











