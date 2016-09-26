/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Leaf.h
 * Author: Timber Dragon
 *
 * Created on September 25, 2016, 3:53 PM
 */

#ifndef LEAF_H
#define LEAF_H

#include <cstddef>

class Leaf {
public:
    Leaf();
    Leaf(Leaf* parent,int val);
    ~Leaf();
    Leaf* AddRightChild(int val);
    Leaf* AddLeftChild(int val);
    bool ChangeParent(Leaf* parent);
    int GetValue();
private:
    Leaf* AddChild(Leaf* child,int newchild);
    Leaf* pParent;
    Leaf* pLeft;
    Leaf* pRight;
    int value;
};

#endif /* LEAF_H */

