/*
 * Auther: Isaac Abella
 * Description: Implement the Header for a binary tree
 */

#ifndef BST_H
#define BST_H

#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <class TKey>
class bst
{
    struct node
    {
        int ID;
        node(int id = 0) : ID(id), parent(NULL), left(NULL), right(NULL) {} // Constructor with ID parameter

        void print();
        void s_print();

        TKey key;
        node *parent; // Added parent pointer

        node *left;
        node *right;
    };

public:
    class iterator
    {
    public:
        iterator();
        iterator &operator++();
        iterator &operator--();
        TKey &operator*();
        bool operator==(const iterator &compare) const;
        bool operator!=(const iterator &compare) const;

    private:
        friend class bst<TKey>;
        iterator(node *ptr); // Constructor with argument

        node *tracked_node;
    };

    iterator begin();
    iterator end();
    iterator rbegin();
    iterator rend();

public:
    bst()
    {
        Troot = NULL;
        nodeID = 0;
    } // Initialize nodeID to 0
    ~bst() { clear(Troot); }

    bool empty() { return Troot == NULL; }

    void insert(TKey &);

    iterator lower_bound(const TKey &);
    iterator upper_bound(const TKey &);

    void print_bylevel();

private:
    void clear(node *);
    node *insert(node *, TKey &);

    int nodeID; // Added nodeID
    node *Troot;
};

// MODE 1 IMPLEMENTATION
template <class TKey>
void bst<TKey>::node::print()
{
    cout << setw(3) << ID << ' '
         << setw(3) << key << " : ";

    if (parent)
        cout << "P=" << setw(3) << parent->ID;
    else
        cout << "ROOT ";

    if (left)
        cout << " L=" << setw(3) << left->ID;
    else
        cout << "      ";
    if (right)
        cout << " R=" << setw(3) << right->ID;
    else
        cout << "      ";

    cout << '\n';
}

template <class TKey>
void bst<TKey>::clear(node *T)
{
    if (T)
    {
        clear(T->left);
        clear(T->right);
        delete T;
        T = NULL;
    }
}

template <class TKey>
void bst<TKey>::insert(TKey &key)
{
    Troot = insert(Troot, key);
}

template <class TKey>
class bst<TKey>::node *bst<TKey>::insert(node *T, TKey &key)
{

    if (T == NULL)
    {
        T = new node(nodeID++);
        T->key = key;
    }
    else if (T->key == key)
    {
        ;
    }
    else if (key < T->key)
    {
        T->left = insert(T->left, key);
        T->left->parent = T;
    }
    else
    {
        T->right = insert(T->right, key);
        T->right->parent = T;
    }

    return T;
}

template <class TKey>
void bst<TKey>::print_bylevel()
{
    if (Troot == NULL)
        return;

    queue<node *> Q;
    node *T;

    Q.push(Troot);
    while (!Q.empty())
    {
        T = Q.front();
        Q.pop();

        T->print();
        if (T->left)
            Q.push(T->left);
        if (T->right)
            Q.push(T->right);
    }
}

// MODE 2 IMPLEMENTATION FOR THE BEGIN AND THE END
template <class TKey>
typename bst<TKey>::iterator bst<TKey>::begin()
{
    if (Troot == NULL)
    {
        // Tree is empty, return end iterator
        return end();
    }

    node *leftmost = Troot;
    while (leftmost->left != NULL)
    {
        leftmost = leftmost->left;
    }
    return iterator(leftmost);
}

template <class TKey>
typename bst<TKey>::iterator bst<TKey>::end()
{
    return iterator(NULL);
}

// MODE 2 IMPLEMENTATION FOR ITERATOR FUNCTIONS

// IMPLEMENT CONSTRUCTOR WITH AND WITHOUT ARGS OUTSIDE OF CLASS SINCE WE HAVE TWO UNIQUE CONSTRUCTORS THIS TIME.

template <class TKey>
bst<TKey>::iterator::iterator(node *ptr) : tracked_node(ptr) {}

// Default constructor
template <class TKey>
bst<TKey>::iterator::iterator() : tracked_node(NULL) {}

template <class TKey>
typename bst<TKey>::iterator &bst<TKey>::iterator::operator++()
{
    if (tracked_node->right != NULL)
    {
        tracked_node = tracked_node->right;
        while (tracked_node->left != NULL)
        {
            tracked_node = tracked_node->left;
        }
    }
    else
    { // no right hand leaf node and subtrees available
        while (tracked_node->parent != NULL && tracked_node->parent->right == tracked_node)
        {
            tracked_node = tracked_node->parent;
        }
        tracked_node = tracked_node->parent;
    }

    return *this;
}

template <class TKey>
typename bst<TKey>::iterator &bst<TKey>::iterator::operator--()
{

    if (tracked_node->left != NULL)
    {
        tracked_node = tracked_node->left;
        while (tracked_node->right != NULL)
        {
            tracked_node = tracked_node->right;
        }
    }
    else
    {
        while (tracked_node->parent != NULL && tracked_node->parent->left == tracked_node)
        {
            tracked_node = tracked_node->parent;
        }
        tracked_node = tracked_node->parent;
    }

    return *this;
}

template <class TKey>
TKey &bst<TKey>::iterator::operator*()
{
    // Dereference implementation
    return tracked_node->key;
}

template <class TKey>
bool bst<TKey>::iterator::operator==(const iterator &compare) const
{
    // compare the current node with previous "tracked_node" with the iterator arg.
    return tracked_node == compare.tracked_node;
}

template <class TKey>
bool bst<TKey>::iterator::operator!=(const iterator &compare) const
{
    // basically will do the opposite of the operator==
    return !(tracked_node == compare.tracked_node);
}

// MODE 3 IMPLEMENTATION FOR UPPER AND LOWER BOUNDS
template <class TKey>
typename bst<TKey>::iterator bst<TKey>::lower_bound(const TKey &key_value)
{
    typename bst<TKey>::node *current = Troot;
    node *result = NULL;

    while (current != NULL)
    {
        if (current->key >= key_value)
        {
            result = current;
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    return iterator(result);
}

template <class TKey>
typename bst<TKey>::iterator bst<TKey>::upper_bound(const TKey &key_value)
{
    typename bst<TKey>::node *current = Troot;
    node *result = NULL;

    while (current != NULL)
    {
        if (current->key > key_value)
        {
            result = current;
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    return iterator(result);
}

// MODE 4 IMPLEMENTATIONS FOR RIGHTMOST BEGIN AND END.

template <class TKey>
typename bst<TKey>::iterator bst<TKey>::rbegin()
{
    // Implementation for rbegin function
    node *rightmost = Troot;
    while (rightmost->right != NULL)
    {
        rightmost = rightmost->right;
    }
    return iterator(rightmost);
}

template <class TKey>
typename bst<TKey>::iterator bst<TKey>::rend()
{
    // Implementation for rend function
    return iterator(NULL);
}

#endif
