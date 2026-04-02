#include "avlnode.h"  

template <class T>
class AvlTree {

	AvlNode<T>* root;

	bool Insert(AvlNode<T>*& rt, T x, bool& taller);

	void RotateLeft(AvlNode<T>*& node);
	void RotateRight(AvlNode<T>*& node);

	void RightBalanceAfterInsert(AvlNode<T>*& sRoot, bool& taller);
	void LeftBalanceAfterInsert(AvlNode<T>*& sRoot, bool& taller);
	void CalculateTreeBalance(AvlNode<T>*& sub_root);
	int CalculateTreeHeight(AvlNode<T>*& sub_root);

public:

	AvlTree() :root(NULL) {}
	AvlNode<T>* getRoot() const
	{
		return root;
	}

	bool Insert(T x)
	{
		bool taller = false;
		return Insert(root, x, taller);
	}

	bool Remove(T x)
	{
		bool shorter = false;
		return Remove(root, x, shorter);
	}

	void DisplayTree(AvlNode<T>* t, int layer) const;
	void DisplayTreeBalance(AvlNode<T>* t, int layer) const; 
};

template <typename T>
void AvlTree<T>::RotateLeft(AvlNode<T>*& node)
{
	if ((node == NULL) || (node->rightChild == NULL)) return;

	AvlNode<T>* tmpNode = new AvlNode<T>(node->data);
	if (tmpNode == NULL) return;

	tmpNode->leftChild = node->leftChild;
	node->leftChild = tmpNode;
	tmpNode->rightChild = node->rightChild->leftChild;

	AvlNode<T>* toDelete = node->rightChild;
	node->data = toDelete->data;
	node->rightChild = toDelete->rightChild;

	delete toDelete;
}

template <typename T>
void AvlTree<T>::RotateRight(AvlNode<T>*& node)
{
	if ((node == NULL) || (node->leftChild == NULL)) return;

	AvlNode<T>* tmpNode = new AvlNode<T>(node->data);
	if (tmpNode == NULL) return;

	tmpNode->rightChild = node->rightChild;
	node->rightChild = tmpNode;
	tmpNode->leftChild = node->leftChild->rightChild;

	AvlNode<T>* toDelete = node->leftChild;
	node->data = toDelete->data;
	node->leftChild = toDelete->leftChild;

	delete toDelete;
}

template <typename T>
void AvlTree<T>::RightBalanceAfterInsert(AvlNode<T>*& sRoot, bool& taller) //if balance == -2     right higher
{
	//ToDo: Write your code here
	//...
	AvlNode<T>* rightsub = sRoot->rightChild; // the right subtree of the root node that is unbalanced, we will need to check the balance of this subtree to determine which case we are in

	switch (rightsub->balance) {
	case -1: //right-right case (-1, so left subtree is also right higher, so only one left rotation needed)
		//ToDo: Write your code here
		//...
		RotateLeft(sRoot); // we need to rotate left on the root node to balance the tree
		CalculateTreeBalance(sRoot); // we need to recalculate the tree balance after the rotation, as the structure of the tree has changed
		taller = false; // after the tree is balanced, it will not be taller than before, so we set taller to false
		break; 

	case 0:
		//ToDo: Write your code here
		//...
		RotateLeft(sRoot); 
		CalculateTreeBalance(sRoot);
		taller = false;
		break;

	case 1: //right-left case (1, so left subtree is left higher, so two rotations are needed)
		//ToDo: Write your code here
		//...
		RotateRight(sRoot->rightChild); // we need to rotate right on the right child of the root node to balance the right subtree
		RotateLeft(sRoot); // then we need to rotate left on the root node to balance the whole tree
		CalculateTreeBalance(sRoot); // we need to recalculate the tree balance after the rotations, as the structure of the tree has changed
		taller = false; // after the tree is balanced, it will not be taller than before, so we set taller to false
		break;
	}
}

template <typename T>
void AvlTree<T>::LeftBalanceAfterInsert(AvlNode<T>*& sRoot, bool& taller) // if balance == 2 left higher
{
	//ToDo: Write your code here
	//...
	AvlNode<T>* leftsub = sRoot->leftChild; // the left subtree of the root node that is unbalanced, we will need to check the balance of this subtree to determine which case we are in

	switch (leftsub->balance) {
	case -1: //left-right case(-1 means the left subtree is right higher, so two rotations are needed)
		//ToDo: Write your code here
        //...
		RotateLeft(sRoot->leftChild); // we need to rotate left on the left child of the root node to balance the left subtree
		RotateRight(sRoot); // then we need to rotate right on the root node to balance the whole tree
		CalculateTreeBalance(sRoot); // we need to recalculate the tree balance after the rotations, as the structure of the tree has changed
		taller = false;
		break;

	case 0:
		//ToDo: Write your code here
		//...
		RotateRight(sRoot); // we need to rotate right on the root node to balance the tree
		CalculateTreeBalance(sRoot); // we need to recalculate the tree balance after the rotation, as the structure of the tree has changed
		taller = false; // after the tree is balanced, it will not be taller than before, so we set taller to false
		break;

	case 1: //left-left case(left sub tree is also left higher, so only one rotate right is needed)
		//ToDo: Write your code here
		//...
		RotateRight(sRoot); // we need to rotate right on the root node to balance the tree
		CalculateTreeBalance(sRoot); // we need to recalculate the tree balance after the rotation, as the structure of the tree has changed
		taller = false; // after the tree is balanced, it will not be taller than before, so we set taller to false
		break;
	}
}

template <typename T>
bool AvlTree<T>::Insert(AvlNode<T>*& rt, T x, bool& taller)
{
	bool success;

	//ToDo: Write your code here
	//...
	if (rt == NULL) { // if the root node is null, we can simply insert the new node here
		rt = new AvlNode<T>(x); // we create a new node with the data x and set it as the root node
		taller = true; // after inserting a new node, the tree will be taller than before, so we set taller to true
		success = true; // the insertion is successful, so we set success to true
	}
	else if (x < rt->data) { // if the data to be inserted is less than the data of the root node, we need to insert it into the left subtree
		success = Insert(rt->leftChild, x, taller); // we recursively call the Insert function on the left child of the root node, passing in the data to be inserted and the taller flag

		if (success && taller) { // if the insertion is successful and the tree is taller than before, we need to check the balance of the tree and perform rotations if necessary
			CalculateTreeBalance(rt); // we need to calculate the tree balance after the insertion, as the structure of the tree has changed

			if (rt->balance > 1) { // if the balance of the root node is greater than 1, it means the left subtree is higher than the right subtree, so we need to perform rotations to balance the tree
				LeftBalanceAfterInsert(rt, taller); // we call the LeftBalanceAfterInsert function to perform the necessary rotations to balance the tree
			}
			else if (rt->balance == 0) { // if the balance of the root node is 0, it means the left and right subtrees are of equal height, so the tree is not taller than before
				taller = false; // we set taller to false, as the tree is not taller than before	
			}
			else { // if the balance of the root node is less than 0, it means the right subtree is higher than the left subtree, so the tree is taller than before
				taller = true;
			}
		}
	}
	else if (x > rt->data) { // if the data to be inserted is greater than the data of the root node, we need to insert it into the right subtree
		success = Insert(rt->rightChild, x, taller);

		if (success && taller) {
			CalculateTreeBalance(rt);

			if (rt->balance < -1) {
				RightBalanceAfterInsert(rt, taller);
			}
			else if (rt->balance == 0) {
				taller = false;
			}
			else {
				taller = true;
			}
		}
	}
	else { // if the data to be inserted is equal to the data of the root node, we do not allow duplicate values in the tree, so the insertion is unsuccessful
		taller = false;
		success = false;
	}

	if (rt != NULL) { // if the root node is not null, we need to calculate the tree balance after the insertion, as the structure of the tree has changed
		CalculateTreeBalance(rt);
	}

	return success;
}

template <typename T>
void AvlTree<T>::DisplayTree(AvlNode<T>* t, int layer) const
{
	if (t == NULL)
		return;
	if (t->rightChild)
		DisplayTree(t->rightChild, layer + 1);
	for (int i = 0; i < layer; i++)
		cout << "    ";
	cout << t->data << endl;
	if (t->leftChild)
		DisplayTree(t->leftChild, layer + 1);
}

template <typename T>
void AvlTree<T>::DisplayTreeBalance(AvlNode<T>* t, int layer) const
{
	if (t == NULL)
		return;
	if (t->rightChild)
		DisplayTreeBalance(t->rightChild, layer + 1);
	for (int i = 0; i < layer; i++)
		cout << "    ";
	cout << t->balance << endl;
	if (t->leftChild)
		DisplayTreeBalance(t->leftChild, layer + 1);
}

template<typename T>
void AvlTree<T>::CalculateTreeBalance(AvlNode<T>*& sub_root) { //function to calculate tree balance
	if (sub_root == nullptr) {
		return; //nothing to do
	}
	sub_root->balance = CalculateTreeHeight(sub_root->leftChild) - CalculateTreeHeight(sub_root->rightChild); //the balance of a particular node is the height(left) - height(right)
	CalculateTreeBalance(sub_root->leftChild); // there is likely a more effecient way to handle this, but for simplicity I calculate the tree balance for the whole tree
	CalculateTreeBalance(sub_root->rightChild);
}


template <typename T>
int AvlTree<T>::CalculateTreeHeight(AvlNode<T>*& sub_root) {
	if (sub_root == nullptr) {
		return -1; //we don't want this sub_root to count if it isn't there, so nulify the +1
	}
	return 1 + max(CalculateTreeHeight(sub_root->leftChild), CalculateTreeHeight(sub_root->rightChild)); //we want whatever height is highest
}