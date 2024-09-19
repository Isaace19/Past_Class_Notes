#include <iostream>

template <typename T>
class list
{
    struct node
    {
        node()
        {
            key = T();
            next = NULL;
        }
        T key;
        node *next;
    };

public:
    list() { L = new node; }
    ~list();
    void magic17(const T &);
    void printList() const;

private:
    node *L;
    void clear(node *);
};

template <typename T>
list<T>::~list()
{
    clear(L->next);
    delete L;
}

template <typename T>
void list<T>::clear(node *p)
{
    if (p)
        clear(p->next);
    else
        return;
    delete p;
}

template <typename T>
void list<T>::magic17(const T &key)
{
    node *curr = L->next;
    node *prev = L;
    // check key if it exists already in list:

    while (curr && curr->key != key)
    {
        prev = curr;
        curr = curr->next;
    }
    // if it does, than unlink and delete that previous node
    if (curr)
    {
        prev->next = curr->next;
        delete curr;
    }
    else
    {
        // than key is unique and not in the list already, so insert normally:
        node *new_node = new node;
        new_node->key = key;
        prev->next = new_node;
    }
}

template <typename T>
void list<T>::printList() const
{
    node *curr = L->next;
    while (curr)
    {
        std::cout << curr->key << " ";
        curr = curr->next;
    }
}

int main()
{
    list<int> L;
    int key;
    while (std::cin >> key)
        L.magic17(key);

    L.printList();

    return 0;
}
