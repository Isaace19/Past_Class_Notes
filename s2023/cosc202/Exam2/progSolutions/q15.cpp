#include <iostream>

struct node
{
    node(int k = 0)
    {
        key = k;
        left = right = NULL;
    }
    int key;
    node *left, *right;
};

// recursive solution to this:

node *recursive_search(node *root, int key)
{
    // recursion requires a base case.
    if (root->key == key)
    {
        return root;
    }
    // this assumes that we have found th ekey from the node struct.

    // explore the left subtrees first, than the right subtree.
    if (key < root->key)
    {
        // we are on the right side searching.
        return recursive_search(root->left, key); // this will now retry the base case
    }
    else // same logic for the right hand side after we search the left subtree.
    {
        return recursive_search(root->right, key);
    }
}

// iterative solution

node *iterative_search(node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->key)
        {
            return root;
        } // base case if the root is the key

        // however we can avoid using recursion by instead wrapping a while statement that
        // adjusts our pointer positions until our if statement is satisfied.
        if (key < root->key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    return NULL; // key not found yet.
}