/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Leaf.cpp
 * Author: Timber Dragon
 * 
 * Created on September 25, 2016, 3:53 PM
 */

#include "Leaf.h"

Leaf::Leaf() {
    pParent = NULL;
    pLeft = NULL;
    pRight = NULL;
    value = NULL;
}

Leaf::Leaf(Leaf* parent,int val) {
    pParent = parent;
    value = val;
    pLeft = NULL;
    pRight = NULL;
}

Leaf::~Leaf() {
   /* garbage collect */
}

Leaf* Leaf::AddRightChild(int val){
    return AddChild(pRight, val);
}
Leaf* Leaf::AddLeftChild(int val){
    return AddChild(pLeft, val);
}
Leaf* Leaf::AddChild(Leaf* child, int val){
        if(child == NULL){
        child = new Leaf(this, val);
        return child;
    }else if(child->GetValue() < val){
        child->AddRightChild(val);
        return child;
    }else{
        child->AddLeftChild(val);
        return child;
    }
    return false;
}
bool Leaf::ChangeParent(Leaf* parent){
    pParent = parent;
    return true;
}
int Leaf::GetValue(){
    return value;
}
