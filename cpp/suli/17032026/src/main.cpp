#include <fstream>
#include <iostream>

// Binary Search Tree
// 1. exercise - Making a binary tree from random numbers

struct binaryTree
{
    int root;
    binaryTree *left;
    binaryTree *right;
};

binaryTree *tree = nullptr;
int numOfNodes;

void
insert (binaryTree *&tree, int a)
{
    if (tree == nullptr)
        {
            binaryTree *uj = new binaryTree;
            uj->root = a;
            uj->left = nullptr;
            uj->right = nullptr;
            tree = uj;
        }
    else
        {
            if (a < tree->root)
                insert (tree->left, a);
            else
                insert (tree->right, a);
        }
}

void
readFromFile ()
{
    std::ifstream inputFile ("tree.in");

    inputFile >> numOfNodes;

    for (int i = 0; i < numOfNodes; i++)
        {
            int a;
            inputFile >> a;
            insert (tree, a);
        }
}

void
writeOutToConsole (binaryTree *tree)
{
    if (tree != nullptr)
        {
            std::cout << tree->root << " ";
            writeOutToConsole (tree->left);
            writeOutToConsole (tree->right);
        }
}

int
main ()
{
    readFromFile ();
    writeOutToConsole (tree);
}
