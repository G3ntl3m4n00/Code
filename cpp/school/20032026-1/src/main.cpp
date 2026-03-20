/* 2026. marcius 20.
 * Binaris kereso fa - feladat
 */

/* Veletlenszeru szam -100 100 kozott n darab
 * Berakni binaris kereso faba az ertekeket
 * inorderrel vegigmenni rajta, kiiratva az ertekeket novekvo sorrendben.
 * */

#include <cstdlib>
#include <ctime>
#include <iostream>

struct binaryTree
{
    int root;
    binaryTree *left;
    binaryTree *right;
};

binaryTree *tree = nullptr;

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
generate ()
{
    srand (time (0));

    int n;
    std::cout << "How many elements should the binary tree have? ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
        {
            int a;
            a = rand () % 201 - 100;
            insert (tree, a);
            std::cout << a << " ";
        }
    std::cout << std::endl;
}

void
inOrderPrintToConsole (binaryTree *tree)
{
    if (tree != nullptr)
        {
            inOrderPrintToConsole (tree->left);
            std::cout << tree->root << " ";
            inOrderPrintToConsole (tree->right);
        }
}

int
main ()
{
    generate ();

    std::cout << "The binary tree with inorder: " << std::endl;

    inOrderPrintToConsole (tree);
    std::cout << std::endl;
}
