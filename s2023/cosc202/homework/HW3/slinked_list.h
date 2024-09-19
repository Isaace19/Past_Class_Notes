#ifndef SLINKED_LIST.H
#define SLINKED_LIST_H

struct data_t
{
    int filler;
    data_t(int value = 0) : filler(value) {}
};

struct Node
{
    data_t data;
    Node *next;
    Node(const data_t &data = data_t()) : data(data), next(0) {}
};

class list
{
public:
    list();
    ~list();

    bool empty() const;
    void pop_front();
    int size() const;
    void push();
    void push_front(const int &din);
    const int &front();

private:
    Node *head;
};

#endif