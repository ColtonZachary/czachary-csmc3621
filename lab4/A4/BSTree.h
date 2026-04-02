#pragma once

#include"BinaryTreeNode.h" 
#include"BinaryTree.h"

using namespace std;

template <class T>
class BSTree : public BinaryTree<T> {

protected:
    BinaryTreeNode<T>* root;    // root of tree

public:
    BSTree() : root(NULL) {};
    BSTree(const BSTree&);
    BSTree(T data) { root = new BinaryTreeNode<T>(data); };
    virtual ~BSTree() { if (root) delete root; };

    BinaryTreeNode<T>* getRoot() {
        return root;
    }

    T findSmallest(BinaryTreeNode<T>* nodep);
    virtual bool insert(BinaryTreeNode<T>* nodep, const T& x);
    virtual const T* const search(BinaryTreeNode<T>* nodep, const T& x);
    virtual bool remove(BinaryTreeNode<T>* nodep, const T& x);

};

template <class T>
T BSTree<T>::findSmallest(BinaryTreeNode<T>* nodep) {
    if (nodep->GetLeftChild() != nullptr) {
        return findSmallest(nodep->GetLeftChild());
    }
    // This is the data contained within the smallest node
    return nodep->GetData();
}

template <class T>
const T* const BSTree<T>::search(BinaryTreeNode<T>* nodep, const T& x) {
    if (nodep == 0) {
        return NULL;
    }

    if (x == nodep->GetData()) {
        return &(nodep->GetData());
    }

    if (x < nodep->GetData()) {
        return search(nodep->GetLeftChild(), x);
    }
    else {
        return search(nodep->GetRightChild(), x);
    }
}

template <class T>
bool BSTree<T>::insert(BinaryTreeNode<T>* nodep, const T& x) {
    //To Do: Write your code here

    // If the tree is empty, create the root.
    if (root == nullptr) {
        root = new BinaryTreeNode<T>(x);
        return true;
    }

    // If caller passed null, just start from the root.
    if (nodep == nullptr) nodep = root;

    // No duplicates allowed, so if we find the value, return false.
    if (x == nodep->GetData()) {
        return false;
    }

    // Go left
    if (x < nodep->GetData()) {
        if (nodep->GetLeftChild() == nullptr) {
            nodep->SetLeftChild(new BinaryTreeNode<T>(x));
            return true;
        }
        return insert(nodep->GetLeftChild(), x);
    }
    // Go right
    else {
        if (nodep->GetRightChild() == nullptr) {
            nodep->SetRightChild(new BinaryTreeNode<T>(x));
            return true;
        }
        return insert(nodep->GetRightChild(), x);
    }
}

template <class T>
bool BSTree<T>::remove(BinaryTreeNode<T>* nodep, const T& x) {
    //To Do: Write your code here

    // auto lambda to recursively find and remove the node with value x, starting from cur.
    auto removeNode = [&](auto&& self, BinaryTreeNode<T>*& cur, const T& key) -> bool {
        if (cur == nullptr) return false;

        if (key < cur->GetData()) {
            BinaryTreeNode<T>* left = cur->GetLeftChild();
            bool ok = self(self, left, key);
            cur->SetLeftChild(left);
            return ok;
        }
        else if (key > cur->GetData()) {
            BinaryTreeNode<T>* right = cur->GetRightChild();
            bool ok = self(self, right, key);
            cur->SetRightChild(right);
            return ok;
        }
        else {
            // FOUND the node to remove

            // Case 1: no children
            if (cur->GetLeftChild() == nullptr && cur->GetRightChild() == nullptr) {
                delete cur;
                cur = nullptr;
                return true;
            }

            // Case 2: only right child
            if (cur->GetLeftChild() == nullptr) {
                BinaryTreeNode<T>* temp = cur;
                cur = cur->GetRightChild();
                delete temp;
                return true;
            }

            // Case 3: only left child
            if (cur->GetRightChild() == nullptr) {
                BinaryTreeNode<T>* temp = cur;
                cur = cur->GetLeftChild();
                delete temp;
                return true;
            }

            // Case 4: two children
            // Replace with inorder successor (smallest in right subtree),
            // then remove that successor from the right subtree.
            T successorValue = findSmallest(cur->GetRightChild());
            cur->SetData(successorValue);

            BinaryTreeNode<T>* right = cur->GetRightChild();
            bool ok = self(self, right, successorValue);
            cur->SetRightChild(right);
            return ok;
        }
    };

    // Ignore nodep if it's null; removal must work from root anyway. 
    (void)nodep;

    return removeNode(removeNode, root, x);
}
