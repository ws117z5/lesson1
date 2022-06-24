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

// Get Balance factor of node N
template<typename T>
int getBalance(BstNode<T>  * node)
{
    if (node == nullptr)
        return 0;
    return height(node->getLeftChildPtr()) - height(node->getRightChildPtr());
}

template<typename T>
class AVLTree : public BinarySearchTree<T> {
public:
    using BinarySearchTree<T>::BinarySearchTree;
    using BinarySearchTree<T>::add;
    using BinarySearchTree<T>::visualize;
    

    //TODO Why do we get here instead of BinarySearchTree<T>::add(const T & data, BstNode<T> * node)?
    //TODO watch youtube for step by step process explaining how avl tree works
    //Here we do the rotation logic 
    BstNode<T> * add(const T & data, BstNode<T> * node) {

        if (node == nullptr) return new BstNode<T>(data);

        T nodeData = node->get();
        BstNode<T> * _tmp = nullptr;
        if (data < nodeData) {
            node->setLeftChildPtr(
                _tmp = add(data, node->getLeftChildPtr())
            );
        } else if (nodeData < data) {
            node->setRightChildPtr(
                _tmp = add(data, node->getRightChildPtr())
            );
        } else {
            return node;
        }

        node->setHeight(max(height(node->getLeftChildPtr()),  height(node->getRightChildPtr())) + 1);

        int balance = getBalance(node);


        // Left Left Case
        if (balance > 1 && node->getLeftChildPtr() != nullptr && data < node->getLeftChildPtr()->get())
            return rightRotate(node);
    
        // Right Right Case
        if (balance < -1 && node->getRightChildPtr() != nullptr && data > node->getRightChildPtr()->get())
            return leftRotate(node);
    
        // Left Right Case
        if (balance > 1 && node->getLeftChildPtr() != nullptr && data > node->getLeftChildPtr()->get()) {
            node->setLeftChildPtr( this->leftRotate(node->getLeftChildPtr()) );
            return this->rightRotate(node);
        }
    
        // Right Left Case
        if (balance < -1 && node->getRightChildPtr() != nullptr && data < node->getRightChildPtr()->get()) {
            node->setRightChildPtr( this->rightRotate(node->getRightChildPtr()) );
            return leftRotate(node);
        }

        return node;
    }

    //TODO Right rotate  
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
    
    //TODO Left Rotate
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