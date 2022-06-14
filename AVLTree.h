//TODO pragma once vs ifndef define endif
#pragma once
#include "BinarySearchTree.h"
#include "BstNode.h"

int max(int a, int b)
{
    return (a > b) ? a : b;
};

template<typename T>
int height(BstNode<T> * node) {
    if (node == nullptr) {
        return 0;
    }
    return node->getHeight();
}

template<typename T>
class AVLTree : public BinarySearchTree<T> {
public:
    using BinarySearchTree<T>::BinarySearchTree;
    using BinarySearchTree<T>::add;
    

    //TODO Why do we get here instead of BinarySearchTree<T>::add(const T & data, BstNode<T> * node) ?
    BstNode<T> * add(const T & data, BstNode<T> * node) {

        if (node == nullptr) return new BstNode<T>(data);

        /* Otherwise, recur down the tree */
        T nodeData = node->get();

        if (data < nodeData) {
            node->setLeftChildPtr(add(data, node->getLeftChildPtr()));
        }
        else if (nodeData < data) {
            node->setRightChildPtr(add(data, node->getRightChildPtr()));
        } else {
            return node;
        }

        node->setHeight(
            1 + max(height(node->getLeftChildPtr()),  height(node->getRightChildPtr()))
        );

        int balance = height(node->getLeftChildPtr()) - height(node->getRightChildPtr());


        // Left Left Case
        if (balance > 1 && node->getLeftChildPtr() != nullptr && data < node->getLeftChildPtr()->get())
            return rightRotate(node);
    
        // Right Right Case
        if (balance < -1 && node->getRightChildPtr() != nullptr && data > node->getRightChildPtr()->get())
            return leftRotate(node);
    
        // Left Right Case
        if (balance > 1 && node->getLeftChildPtr() != nullptr && data > node->getLeftChildPtr()->get()) {
            node->setLeftChildPtr(leftRotate(node->getLeftChildPtr()));
            return rightRotate(node);
        }
    
        // Right Left Case
        if (balance < -1 && node->getRightChildPtr() != nullptr && data < node->getRightChildPtr()->get()) {
            node->setRightChildPtr(rightRotate(node->getRightChildPtr()));
            return leftRotate(node);
        }
        /* return the (unchanged) node pointer */
        return node;
    }

    // A utility function to right
    // rotate subtree rooted with y
    // See the diagram given above.
    BstNode<T> * rightRotate(BstNode<T> * y)
    {
        BstNode<T> * x = y->getLeftChildPtr();
        BstNode<T> * T2 = x->getRightChildPtr();
    
        // Perform rotation
        x->setRightChildPtr(y);
        y->setLeftChildPtr(T2);
    
        // Update heights
        y->setHeight(max(height(y->getLeftChildPtr()), height(y->getRightChildPtr())) + 1);
        x->setHeight(max(height(x->getLeftChildPtr()), height(x->getRightChildPtr())) + 1);
    
        // Return new root
        return x;
    }
    
    // A utility function to left
    // rotate subtree rooted with x
    // See the diagram given above.
    BstNode<T> * leftRotate(BstNode<T> * x)
    {
        BstNode<T> * y = x->getRightChildPtr();
        BstNode<T> * T2 = y->getLeftChildPtr();
    
        // Perform rotation
        y->setLeftChildPtr(x);
        x->setRightChildPtr(T2);
    
        // Update heights
        x->setHeight(max(height(x->getLeftChildPtr()), height(x->getRightChildPtr())) + 1);
        y->setHeight(max(height(y->getLeftChildPtr()), height(y->getRightChildPtr())) + 1);
    
        // Return new root
        return y;
    }
};