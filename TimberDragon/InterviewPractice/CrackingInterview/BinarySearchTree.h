/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinarySearchTree.h
 * Author: Timber Dragon
 *
 * Created on September 25, 2016, 3:47 PM
 */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <cstddef>
#include "Leaf.h"

class BinarySearchTree {
public:
    BinarySearchTree();
    BinarySearchTree(int val);
    ~BinarySearchTree();
    Leaf* AddLeaf(int val);
    Leaf* SearchDFS(int val);
private:
    Leaf* pRoot;
    Leaf* SearchLeft(Leaf* leaf, int val);
    Leaf* SearchRight(Leaf* leaf, int val);
};


#endif /* BINARYSEARCHTREE_H */

