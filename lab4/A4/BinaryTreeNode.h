#ifndef BINARYTREENODE_H  
#define BINARYTREENODE_H  

#include "iostream"  

using namespace std;

template <class Type>
class BinaryTreeNode
{
	Type m_data;
	BinaryTreeNode<Type>* m_leftChild;
	BinaryTreeNode<Type>* m_rightChild;

public:
	BinaryTreeNode() { m_leftChild = m_rightChild = NULL; };
	BinaryTreeNode(const Type& data,
		BinaryTreeNode* leftChild = NULL,
		BinaryTreeNode* rightChild = NULL)
	{
		m_data = data;
		m_leftChild = leftChild;
		m_rightChild = rightChild;
	};

	Type& GetData() { return m_data; };
	void SetData(const Type& data) { m_data = data; };

	BinaryTreeNode<Type>* GetLeftChild() { return m_leftChild; };
	BinaryTreeNode<Type>* GetRightChild() { return m_rightChild; };


	void SetLeftChild(BinaryTreeNode<Type>* leftChild) { m_leftChild = leftChild; };
	void SetRightChild(BinaryTreeNode<Type>* rightChild) { m_rightChild = rightChild; };
};

#endif  
