//
// Created by yasha on 06.12.2019.
//

#ifndef TEMPLATE1_NODE_H
#define TEMPLATE1_NODE_H
template <typename T>
struct Node
{
    T value;
    Node<T> *prev;

    Node(T valu1e, Node<T> *pre1v) : value(valu1e), prev(pre1v) {}
};

#endif //TEMPLATE1_NODE_H
