#ifndef NODE_H
#define NODE_H

template <typename type_t>
struct Node
{
    Node *left;
    Node *right;
    type_t data;
};


#endif // NODE_H
