// Node.hpp

#ifndef NODE_HPP
#define NODE_HPP

class Node
{
private:
    /* data */
public:
    Node(const int& value);
    int data;
    Node* left;
    Node* right;
    int height;

    ~Node();
};

#endif // NODE_HPP

