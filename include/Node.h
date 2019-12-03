//
// Created by alexandergaranin on 03.12.2019.
//

#ifndef TEMPLATE1_NODE_H
#define TEMPLATE1_NODE_H
template <typename T>
struct Node
{
    T value;
    Node<T> *prev;

    Node(T value, Node<T> *prev) : value(value), prev(prev) {}
};

#endif //TEMPLATE1_NODE_H
