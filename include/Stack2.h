//
// Created by alexandergaranin on 03.12.2019.
//

#ifndef TEMPLATE1_STACK2_H
#define TEMPLATE1_STACK2_H

#include <iostream>
#include <exception>
#include "Node.h"

using namespace std;


template<typename T>
class Stack2 {
private:
    Node<T> *node = nullptr;  //вершина стэка

public:

    Stack2() = default;

    Stack2(const Stack2 &stack) = delete; //конструктор копирования
    Stack2(Stack2 &&stack) = default;      // конструктор перемещения (constructible)
    auto operator=(Stack2 &&stack) noexcept -> Stack2 & = default; // (assignable)

    template<typename ... Args>
    void push_emplace(Args &&... value) {
        auto item = node;
        node = new Node<T>{{forward<Args>(value)...}, item}; //позволяет выполнить идельную передачу аргументов, принимаемых в качестве rvalue-ссылок
    }

    void push(T &&value) {
        auto item = node;
        node = new Node<T>{forward<T>(value), item};
    }

    const T &head() const {
        if (!node)
            throw logic_error("no stack");
        else
            return node->value;
    }

    T pop() {
        if (!node)
            throw logic_error("no stack");
        else {
            auto remote = node->value;
            node = node->prev;
            return remote;
        }
    }
};


#endif //TEMPLATE1_STACK2_H
