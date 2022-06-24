//
// Created by Koroteev Vladimir on 21.11.2018.
//

#ifndef BSTNODE_H
#define BSTNODE_H
#include "Node.h"

template<typename T>
class BstNode : Node<T> {
private:
    BstNode * right = nullptr;
    BstNode * left = nullptr;
    int height = 0;
public:
    using Node<T>::setData;
    using Node<T>::get;

    BstNode() {};
    BstNode(const T& data) {
        this->setData(data);
        this->height = 1;
    };
    
    BstNode(const T& data, BstNode<T>* leftPtr, BstNode<T>* rightPtr) {
        this->setData(data);
        this->right = rightPtr;
        this->left = leftPtr;
    };

    int getHeight() {
        return this->height;
    }

    void setHeight(int h) {
        this->height = h;
    }

    void setItem(const T& data) {
        (*this) = data;
    };

    bool isLeaf() const {
        return this->right == nullptr && this->left == nullptr;
    };

    bool hasRight() {
        return this->right != nullptr;
    }

    bool hasLeft() {
        return this->left != nullptr;
    }

    BstNode<T> * getLeftChildPtr() const {
        return this->left;
    };
    BstNode<T> * getRightChildPtr() const {
        return this->right;
    };
    void setLeftChildPtr(BstNode<T>* leftPtr) {
        this->left = leftPtr;
    };
    void setRightChildPtr(BstNode<T>* rightPtr) {
        this->right = rightPtr;
    };

    // end BinaryNode

};


#endif //BSTNODE_H
