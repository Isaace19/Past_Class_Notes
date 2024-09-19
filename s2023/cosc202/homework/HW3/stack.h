#ifndef STACK_H
#define STACK_H

#include "slinked_list.h"
#include <iostream>

class stack
// this goofy ahh top will be the stack version of head
{
public:
    stack() { Top = NULL; }
    ~stack();

    bool empty() const {}
    int size() const {}
    void push(const data_t &data) {}
    void pop() {}
    const data_t &top() {}

private:
    list v;
    Node *Top;
};
// just implement here for now.

stack::~stack()
{
    // somehow implement
    while (!empty())
    {
        pop();
    }
}

bool stack::empty() const
{
    return Top == 0;
}

int stack::size() const
{
}

void stack::pop()
{
    if (Top == 0)
    {
        std::cerr << "Stack Overflow....\n";
    }
    else
    {
    }
}

void stack::push(const data_t &data)
{
}

const data_t &stack::top()
{
}

#endif