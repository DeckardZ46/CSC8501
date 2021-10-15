/*
Tree structures are a widely used data construct in programming (including games programming). 
One such tree structure is a Binary Search Tree which stores data in a manner that allows fast searching. 
Familiarise yourself with this technique and write your own Binary Search Tree using the code below to help you:
**code**

A Tree can be considered as a collection of nodes, linked to one another via pointers. 
You have been given the definition of a node in the Binary Search Tree. This is in the form of a struct; 
a record for holding together related variables.
You “build” the tree recursively using the insert_integer function. 
You will need to find the correct place to insert a node to hold the new value, then create a node on the heap.
The print_tree function should print out the values in the tree in ascending order, 
and the terminate_tree function should reclaim all the memory used in the tree.

Deckard Zhao 15/10/2021
*/
#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int value;
    struct node *left;
    struct node *right;
};
struct node *root = nullptr;

// implement the functions described by these headers
void insert_integer(struct node **tree, int value)
{
    if ((*tree) == nullptr)
    {
        *tree = new node;
        (*tree)->value = value;
        (*tree)->left = nullptr;
        (*tree)->right = nullptr;
    }

    else if (value <= (*tree)->value)
        insert_integer(&(*tree)->left, value);

    else if (value > (*tree)->value)
        insert_integer(&(*tree)->right, value);
    else
        cout << "Value is illegal! value is " << value << endl;
}
void print_tree(struct node *tree) //todo
{
    if (tree->left != nullptr)
        print_tree(tree->left);

    cout << tree->value << " ";

    if (tree->right != nullptr)
        print_tree(tree->right);
}

void terminate_tree(struct node *tree) // todo
{
    if (tree->left != nullptr)
        terminate_tree(tree->left);
    if (tree->right != nullptr)
        terminate_tree(tree->right);
    else
    {
        delete tree;
        tree = nullptr;
    }
    return;
}

int main()
{
    cout << "Please enter numbers to build the Binary Search Tree." << endl;
    cout << "Enter a number greater or equal than 0 to the Binary Search Tree; OR a NEGATIVE one to stop: " << endl;

    vector<int> myVec(0);
    while (true)
    {
        int a;
        cin >> a;
        if (a < 0)
            break;
        else
            myVec.push_back(a);
    }

    for (auto val : myVec)
    {
        insert_integer(&root, val);
    }

    print_tree(root);
    cout << endl;
    terminate_tree(root);
    return 0;
}