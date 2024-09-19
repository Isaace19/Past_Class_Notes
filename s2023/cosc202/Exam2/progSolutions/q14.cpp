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

void clear(node *root, int key)
{
    // checking the tree if it’s empty. This satisfies one of the requirements.

    // alternatively you can do
    if (root == NULL)
    {
        std::cout << "Attempting to delete an empty tree.\n";
        return;
    }

    node *curr = root; // make a curr tracker to traverse the search tree via iterative steps

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            node *temp = curr->right; // moves to the right leaf node.
            delete curr;              // delete the node we are on currently, than set the node to a temp value.
            curr = temp;
        }
        else
        { // we got to the right nodes of the left subtrees and delete those first
            node *prev = curr->left;
            while (prev->right != NULL && prev->right != curr)
            {
                prev = prev->right;
            }

            if (curr->right == NULL)
            {
                prev->right = curr; // again delete node
                curr = curr->left;  // now the current node pointer is the left node
            }
            else
            { // logic handling if we accidentally delete a node with a left subtree.
                prev->right = NULL;
                node *temp = curr->right;
                delete curr;
                curr = temp;
            }
        }
    }
}
