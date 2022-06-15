//
// Created by Koroteev Vladimir on 21.11.2018.
//

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <algorithm>
#include <string>
#include <stdexcept>
#include "BstNode.h"

template<typename T>
class BinaryTreeInterface {
public:
    /** Tests whether this binary tree is empty.
    @return True if the binary tree is empty, or false if not. */
    virtual bool isEmpty() const = 0;
    /** Gets the height of this binary tree.
     * @return The height of the binary tree. */
    virtual int height() const = 0;
    /** Gets the number of nodes in this binary tree.
     * @return The number of nodes in the binary tree. */
    virtual int count() const = 0;
    /** Gets the data that is in the root of this binary tree.
    @pre The binary tree is not empty.
    @post The root’s data has been returned, and the binary tree is unchanged.
    @return The data in the root of the binary tree. */
    virtual T getRootData() const = 0;
    /** Replaces the data item in the root of this binary tree with the given data, if the tree is not empty. However, if
    the tree is empty, inserts a new root node containing the
    given data into the tree. @pre None.
    @post The data in the root of the binary tree is as given.
    @param newData The data for the root.
     */
    virtual void setRootData(const T& newData) = 0;
    /** Adds a new node containing the given data to this binary tree. @param newData The data for the new node.
    @post The binary tree contains a new node.
    @return True if the addition is successful, or false not.
     */
    virtual void add(const T& newData) = 0;
    /** Removes the node containing the given data item from this binary tree.
     * @param data The data value to remove from the binary tree.
     * @return True if the removal is successful, or false not. */
    virtual void remove(const T& data) = 0;
    /** Removes all nodes from this binary tree. */
    virtual void clear() = 0;
    /** Tests whether a given entry occurs in this binary tree.
    @post The binary search tree is unchanged.
    @param anEntry The entry to find.
    @return True if the entry occurs in the tree, or false if not. */
    virtual bool contains(const T& anEntry) const = 0;
    /** Traverses this binary tree in preorder (inorder, postorder) and calls the function visit once for each node.
    @param visit A client-defined function that performs an operation on or with the data in each visited node. */
    virtual void inorderTraverse(void visit(T)) const = 0;
    virtual void postorderTraverse(void visit(T)) const = 0;
    virtual void preorderTraverse(void visit(T)) const = 0;
    virtual void breadthFirstTraversal(void visit(T)) const = 0;
}; // end BinaryTreeInterface

template<typename T>
class BinarySearchTree : public BinaryTreeInterface<T> {
private:
    BstNode<T> *rootPtr;
protected:
    int count(BstNode <T> *node) const {
        if(node == nullptr)
            return 0;
        if(node->getLeftChildPtr() == nullptr && node->getRightChildPtr() == nullptr)
            return 1;
        else
            return count(node->getLeftChildPtr())+
                   count(node->getRightChildPtr());
    };

    // Recursively deletes all nodes from the tree.
    void destroyTree(BstNode <T> *subTreePtr) {
        if (subTreePtr != nullptr) {
            destroyTree(subTreePtr->getLeftChildPtr());
            destroyTree(subTreePtr->getRightChildPtr());
            delete subTreePtr;
        } // end if
    };

    // Recursively searches for target value in the tree by using a // preorder traversal.
    BstNode <T> *findNode(const T &target, bool &success, BstNode <T> *treePtr) const {
        if(treePtr != nullptr) {
            T cValue = treePtr->get();
            if(cValue == target) {
                success = true;
                return treePtr;
            } else if(cValue > target) {
                return findNode(target, success, treePtr->getRightChildPtr());
            } else {
                return findNode(target, success, treePtr->getLeftChildPtr());
            }
        }

        return treePtr;
    };

    BstNode <T> *copyTree(BstNode <T> *treePtr) const {
        BstNode<T>* newTreePtr = nullptr;

        if (treePtr != nullptr) {
            //T data = treePtr->getItem();
            newTreePtr = new BstNode<T>(treePtr->get(), nullptr, nullptr);
            newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
            newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
        }
        return newTreePtr;
    };

    /* Print nodes at a given level */
    void printLevel(int level, void visit(T), BstNode<T> * node) const
    {
        if (node == nullptr)
            return;
        if (level == 1) {
            T item = node->get();
            visit(item);
        }
        else if (level > 1)
        {
            printLevel(level-1, visit, node->getLeftChildPtr());
            printLevel(level-1, visit, node->getRightChildPtr());
        }
    }

    void breadthFirst(void visit(T), BstNode<T> * node) const
    {
        int h = getHeight(node);
        int i;
        for (i=1; i<=h; i++)
            printLevel(i, visit, node);
    }

    void preorder(void visit(T), BstNode <T> *treePtr) const {
        if (treePtr != nullptr) {
            T theItem = treePtr->get();
            visit(theItem);

            /* then recur on left sutree */
            preorder(visit, treePtr->getLeftChildPtr());

            /* now recur on right subtree */
            preorder(visit, treePtr->getRightChildPtr());
        }
    };

    void inorder(void visit(T), BstNode <T> *treePtr) const {
        if (treePtr != nullptr) {
            inorder(visit, treePtr->getLeftChildPtr());
            T theItem = treePtr->get();
            visit(theItem);
            inorder(visit, treePtr->getRightChildPtr());
        } // end if
    };

    void postorder(void visit(T), BstNode <T> *treePtr) const {
        if (treePtr != nullptr) {

            // first recur on left subtree
            postorder(visit, treePtr->getLeftChildPtr());

            // then recur on right subtree
            postorder(visit, treePtr->getRightChildPtr());

            T theItem = treePtr->get();
            visit(theItem);
        }

    };

public:
    BinarySearchTree() : rootPtr(nullptr) {};

    BinarySearchTree(const T &rootItem) {
        rootPtr = new BstNode<T>(rootItem, nullptr, nullptr);
    };

    BinarySearchTree(const T &rootItem,
                   const BinarySearchTree<T> *leftTreePtr,
                   const BinarySearchTree<T> *rightTreePtr) {
        rootPtr = new BstNode<T>(rootItem, copyTree(leftTreePtr->rootPtr), copyTree(rightTreePtr->rootPtr));
    };

    BinarySearchTree(const BinarySearchTree<T> &treePtr) {
        rootPtr = copyTree(treePtr.rootPtr);
    };

    virtual ~BinarySearchTree() {};

    bool isEmpty() const {
        return rootPtr == nullptr;
    };

    BstNode <T> * minValueNode(BstNode <T> * node)
    {
        BstNode <T> * current = node;

        /* loop down to find the leftmost leaf */
        while (current->getLeftChildPtr() != nullptr)
            current = current->getLeftChildPtr();

        return current;
    }

    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    int getHeight(BstNode<T> * node) const {
        if (node == nullptr)
            return 0;
        else
        {
            /* compute the depth of each subtree */
            int lDepth = getHeight(node->getLeftChildPtr());
            int rDepth = getHeight(node->getRightChildPtr());

            /* use the larger one */
            if (lDepth > rDepth)
                return(lDepth+1);
            else 
                return(rDepth+1);
        }
    };

    T getRootData() const {
        if(rootPtr == nullptr) {
            throw std::range_error("Root node is empty");
        }
        return rootPtr->get();
    };

    void setRootData(const T &newData) {
        rootPtr->setData(newData);
    };

    virtual BstNode<T> * add(const T & data, BstNode<T> * node) {

        if (node == nullptr) return new BstNode<T>(data);

        /* Otherwise, recur down the tree */
        T nodeData = node->get();

        if (data < nodeData) {
            node->setLeftChildPtr(add(data, node->getLeftChildPtr()));
        }
        else if (nodeData < data) {
            node->setRightChildPtr(add(data, node->getRightChildPtr()));
        }

        /* return the (unchanged) node pointer */
        return node;
    }

    // Adds a node
    void add(const T &newData) {
        rootPtr = add(newData, rootPtr);
    };

    /*
    void add(T * newData) {
        rootPtr = add(newData, rootPtr);
    };
     */

    BstNode <T> * remove(const T &data, BstNode<T> * current) {
        // base case

        if (current == nullptr) return current;

        BstNode<T> * left = current->getLeftChildPtr();
        BstNode<T> * right = current->getRightChildPtr();
        T cValue = current->get();

        if(cValue == data) {
            // node with only one child or no child
            if (left == nullptr)
            {
                BstNode<T> * temp = right;
                delete current;
                return temp;
            }
            else if (right == nullptr)
            {
                BstNode<T> * temp = left;
                delete current;
                return temp;
            }

            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            BstNode<T> * temp = minValueNode(right);
            T tmpData = temp->get();
            // Copy the inorder successor's content to this node
            current->setData(tmpData);

            // Delete the inorder successor
            current->setRightChildPtr(remove(tmpData, right));
        }
        // If the key to be deleted is smaller than the root's key,
        // then it lies in left subtree
        else if (data > cValue) {// data < cValue)
            current->setLeftChildPtr(remove(data, left));

        }
            // If the key to be deleted is greater than the root's key,
            // then it lies in right subtree
        else if (cValue > data) {//data > cValue)
            current->setRightChildPtr(remove(data, right));

        }
            // if key is same as root's key, then This is the node
            // to be deleted
        return current;
    };

    void clear(BstNode <T> * node) {
        if (node == nullptr) return;

        clear(node->getLeftChildPtr());
        clear(node->getRightChildPtr());
        free(node);
    };

    void clear() {
        clear(rootPtr);
    };
    //T getEntry(const T& anEntry) const throw(char *) {};

    int height() const {
        return getHeight(rootPtr);
    };

    int count() const {
        return count(rootPtr);
    };

    void remove(const T &data) {
        BstNode<T> * temp  = remove(data, rootPtr);
        rootPtr = temp;
    };

    bool contains(const T& anEntry) const {
        bool success = false;
        findNode(anEntry, success, rootPtr);
        return success;
    };

    void preorderTraverse(void visit(T)) const {
        preorder(visit, rootPtr);
    };
    void inorderTraverse(void visit(T)) const {
        inorder(visit, rootPtr);
    };

    void postorderTraverse(void visit(T)) const {
        postorder(visit, rootPtr);
    };
    void breadthFirstTraversal(void visit(T)) const {
        breadthFirst(visit, rootPtr);
    };


    //TODO make a function that will print bstree in a visual matter
    // like so:
    //        Min-Heap         Binary Search Tree               AVL BTree   
    //          1                    6                              6
    //      2       3             4     8                         
    //    4   5   6    7            5     16 
    //                                      24 

    void visualize() {
       //this->rootPtr
       //this->rootPtr->getLeftChild()
       //this->rootPtr->getRightChild()
    }
};

#endif //GROUPPROJECT_BINARYSEARCHTREE_H