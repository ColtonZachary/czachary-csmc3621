#include <conio.h>  
#include <iostream>  
#include "avltree.h"  

using namespace std;

int main(int argc, char** argv) {

	AvlTree<int> tree;

	cout << "Tree 1 Start ---------------------------------------" << endl;
	tree.Insert(21);
	tree.Insert(12);
	tree.Insert(35);
	tree.Insert(2);
	tree.Insert(15);
	tree.Insert(36);
	tree.Insert(14);
	tree.Insert(7);
	tree.Insert(28);
	tree.Insert(9);
	tree.DisplayTree(tree.getRoot(), 0);
	//cout << "Balance of Tree 1" << endl;
	//tree.DisplayTreeBalance(tree.getRoot(), 0);
	//this was a custom function purely for testing purposes
	cout << "Tree 1 End ---------------------------------------" << endl;


	cout << "Tree 2 Start ---------------------------------------" << endl;
	AvlTree<int> tree2;
	tree2.Insert(15);
	tree2.Insert(2);
	tree2.Insert(18);
	tree2.Insert(19);
	tree2.Insert(42);
	tree2.Insert(20);
	tree2.Insert(37);
	tree2.Insert(30);
	tree2.Insert(8);
	tree2.Insert(32);
	tree2.Insert(55);
	tree2.Insert(35);
	tree2.Insert(31);
	tree2.DisplayTree(tree2.getRoot(), 0);
	//cout << "Balance of Tree 2" << endl;
	//tree2.DisplayTreeBalance(tree2.getRoot(), 0);
	cout << "Tree 2 End ---------------------------------------" << endl;

	cout << "Tree 3 Start ---------------------------------------" << endl;
	AvlTree<int> tree3;
	tree3.Insert(24);
	tree3.Insert(9);
	tree3.Insert(15);
	tree3.Insert(39);
	tree3.Insert(4);
	tree3.Insert(20);
	tree3.Insert(18);
	tree3.Insert(50);
	tree3.DisplayTree(tree3.getRoot(), 0);
	//cout << "Balance of Tree 3" << endl;
	//tree3.DisplayTreeBalance(tree3.getRoot(), 0);
	cout << "Tree 3 End ---------------------------------------" << endl;

	return 0;
}
