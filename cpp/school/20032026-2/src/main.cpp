#include <fstream>
#include <iostream>

struct binaryTree
{
    int root;
    binaryTree *left;
    binaryTree *right;
};

binaryTree *tree;
int numOfNodes;

void
insert (binaryTree *&tree, int a)
{
    if (tree == nullptr)
        {
            binaryTree *temp = new binaryTree;
            temp->root = a;
            temp->left = nullptr;
            temp->right = nullptr;
            tree = temp;
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
    std::ifstream inputFile ("preorder.in");
    inputFile >> numOfNodes;

    for (int i = 0; i < numOfNodes; i++)
        {
            int a;
            inputFile >> a;
            insert (tree, a);
        }
}

void
preOrderToConsole (binaryTree *tree)
{
    if (tree != nullptr)
        {
            std::cout << tree->root << " ";
            preOrderToConsole (tree->left);
            preOrderToConsole (tree->right);
        }
}

void
inOrderToConsole (binaryTree *tree)
{
    if (tree != nullptr)
        {
            inOrderToConsole (tree->left);
            std::cout << tree->root << " ";
            inOrderToConsole (tree->right);
        }
}

void
level (binaryTree *tree, int currentLevel, int writeLevel)
{
    if (tree != nullptr)
        {
            if (currentLevel == writeLevel)
                std::cout << tree->root << " ";
            else if (currentLevel < writeLevel)
                {
                    level (tree->left, currentLevel + 1, writeLevel);
                    level (tree->right, currentLevel + 1, writeLevel);
                }
        }
}

bool
searchForElement (binaryTree *tree, int element)
{
    if (tree != nullptr)
        {
            if (tree->root == element)
                return true;
            else
                {
                    if (element < tree->root)
                        searchForElement (tree->left, element);
                    else
                        searchForElement (tree->right, element);
                }
        }
    else
        return false;

    return false;
}

int
main ()
{
    readFromFile ();

    std::cout << "PreOrder: " << std::endl;
    preOrderToConsole (tree);
    std::cout << std::endl;

    std::cout << "InOrder: " << std::endl;
    inOrderToConsole (tree);
    std::cout << std::endl;

    std::cout << "The level you want to watch: ";
    int watchLevel;
    std::cin >> watchLevel;

    std::cout << "Elements from the given level: " << std::endl;
    level (tree, 1, watchLevel);

    std::cout << "Element you want to search for: ";
    int searchElement;
    std::cin >> searchElement;

    std::cout << (searchForElement (tree, searchElement) ? "It's in the tree."
                                                         : "It's not in the tree.")
              << std::endl;
}
