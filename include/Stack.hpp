#ifndef STACK_HPP
#define STACK_HPP
#include<iostream>
using namespace std;

class Stack
{
public:
    Stack();
    ~Stack();
    void push(int data);
    void pop();
    bool isEmpty();
    bool isFull();
    int top();
    friend ostream& operator<<(ostream& os, Stack& stack);
private:
    void expand(int size);
    int capacity;
    int topIndex;
    int* data;
    
};

#endif // Stack_hpp
