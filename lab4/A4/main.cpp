// Assignment4BST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "BinaryTreeNode.h"
#include "BinaryTree.h"
#include "BSTree.h"
#include <iostream>

using namespace std;

int main()
{

    cout << "Tree 1:" << endl;
    BSTree<int> myBstTree;

    int vals1[] = { 50, 30, 70, 20, 40, 60, 80, 10, 5, 7, 79 };
    int n1 = sizeof(vals1) / sizeof(vals1[0]);

    for (int i = 0; i < n1; i++) {
        myBstTree.insert(myBstTree.getRoot(), vals1[i]);
    }

    cout << "Tree 1 Initial In Order Traversersal:" << endl;
    myBstTree.InOrderTraverse(myBstTree.getRoot());
    cout << endl;

    cout << "Tree 1 Initial Level Order Traversal:" << endl;
    myBstTree.LevelOrderTraverse(myBstTree.getRoot());
    cout << endl;

    cout << "Removing 5, 10, and 30 from Tree 1" << endl;
    myBstTree.remove(myBstTree.getRoot(), 5);
    myBstTree.remove(myBstTree.getRoot(), 10);
    myBstTree.remove(myBstTree.getRoot(), 30);

    cout << "Tree 1 After Removal In Order Traversersal:" << endl;
    myBstTree.InOrderTraverse(myBstTree.getRoot());
    cout << endl;

    cout << "Tree 1 After Removal Level Order Traversal:" << endl;
    myBstTree.LevelOrderTraverse(myBstTree.getRoot());
    cout << endl;

    const int* p7 = myBstTree.search(myBstTree.getRoot(), 7);
    if (p7 != nullptr) {
        cout << "Address of node containing 7: " << (const void*)p7
             << " data from node containing 7: " << *p7 << endl;
    }
    else {
        cout << "7 not found in Tree 1" << endl;
    }

    cout << endl;

    cout << "Tree 2:" << endl;
    BSTree<char> myCharTree;

    char vals2[] = { 'D', 'B', 'A', 'C', 'F', 'E', 'Z' };
    int n2 = sizeof(vals2) / sizeof(vals2[0]);

    for (int i = 0; i < n2; i++) {
        myCharTree.insert(myCharTree.getRoot(), vals2[i]);
    }

    cout << "Tree 2 Initial In Order Traversersal:" << endl;
    myCharTree.InOrderTraverse(myCharTree.getRoot());
    cout << endl;

    cout << "Tree 2 Initial Level Order Traversal:" << endl;
    myCharTree.LevelOrderTraverse(myCharTree.getRoot());
    cout << endl;

    cout << "Removing F, C, and D from Tree 2" << endl;
    myCharTree.remove(myCharTree.getRoot(), 'F');
    myCharTree.remove(myCharTree.getRoot(), 'C');
    myCharTree.remove(myCharTree.getRoot(), 'D');

    cout << "Tree 2 After Removal In Order Traversersal:" << endl;
    myCharTree.InOrderTraverse(myCharTree.getRoot());
    cout << endl;

    cout << "Tree 2 After Removal Level Order Traversal:" << endl;
    myCharTree.LevelOrderTraverse(myCharTree.getRoot());
    cout << endl;

    const char* pZ = myCharTree.search(myCharTree.getRoot(), 'Z');
    if (pZ != nullptr) {
        cout << "Data from node containing Z: " << *pZ << endl;
    }
    else {
        cout << "Z not found in Tree 2" << endl;
    }

    cout << endl << endl;

    cout << "Int BSTREE" << endl;

    BSTree<int> demo;
    for (int i = 0; i <= 19; i++) {
        demo.insert(demo.getRoot(), i);
    }

    cout << "In order!" << endl;
    demo.InOrderTraverse(demo.getRoot());
    cout << endl;

    cout << "Level order!" << endl;
    demo.LevelOrderTraverse(demo.getRoot());
    cout << endl;

    cout << "Removing all items from the tree" << endl;
    for (int i = 0; i <= 19; i++) {
        demo.remove(demo.getRoot(), i);
    }

    cout << "In order after removal!" << endl;
    demo.InOrderTraverse(demo.getRoot());
    cout << endl;

    cout << "Level order after removal!" << endl;
    demo.LevelOrderTraverse(demo.getRoot());
    cout << endl;

    return 0;
}