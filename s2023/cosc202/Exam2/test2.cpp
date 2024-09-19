#include <iostream>

struct node
{
    node(int k = 0)
    {
        key = k;
        height = 0;
        left = right = NULL;
    }
    int key;
    int height;
    node *left, *right;
};

node *insert(node *T, int key)
{
    if (T == NULL)
    {
        return new node(key);
    }

    // check left and right:

    if (key < T->key)
    {
        T->left = insert(T->left, key);
    }
    else if (key > T->key)
    {
        T->right = insert(T->right, key);
    }
    else
    {
        // this is when a duplicate key is found:
        std::cout << "Duplicate found.\n";
    }

    return T;
}