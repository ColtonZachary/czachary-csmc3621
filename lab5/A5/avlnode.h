#ifndef AVLNODE_H  
#define AVLNODE_H  

#include <iostream>  

using namespace std;

template <class T> class AvlTree;

template <class T>
class AvlNode {

	T data;
	AvlNode* leftChild;
	AvlNode* rightChild;
	int balance;

public:

	AvlNode() :leftChild(NULL), rightChild(NULL), balance(0) {};

	AvlNode(const T& e, AvlNode<T>* lt = NULL, AvlNode<T>* rt = NULL)
		:data(e), leftChild(lt), rightChild(rt), balance(0) {};

	int getBalance() const
	{
		return balance;
	}
	AvlNode<T>* getLeftChild() const
	{
		return leftChild;
	}
	AvlNode<T>* getRightChild() const
	{
		return rightChild;
	}
	T getData() const
	{
		return data;
	}

	friend class AvlTree<T>;
};
#endif  
