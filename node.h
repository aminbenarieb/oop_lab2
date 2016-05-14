#ifndef NODE_H
#define NODE_H

template <typename type_t>
struct Node
{
    Node  *prev;
    Node  *next;
    type_t data;
};


#endif // NODE_H
