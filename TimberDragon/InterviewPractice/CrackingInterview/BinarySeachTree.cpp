/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree(){
    pRoot = NULL;
}
BinarySearchTree::BinarySearchTree(int val){
    pRoot = new Leaf(NULL,val);
}
BinarySearchTree::~BinarySearchTree(){
    if(pRoot != NULL){
        delete pRoot;
    }
}
Leaf* BinarySearchTree::AddLeaf(int val){
    if(pRoot == NULL){
        pRoot = new Leaf(NULL, val);
        return pRoot;
    }else if(pRoot->GetValue() < val){
       return pRoot->AddLeftChild(val);
    }else{
        return pRoot->AddRightChild(val);
    }
}
//This is incomplete need to flesh out DFS
Leaf* BinarySearchTree::SearchDFS(int val){
    if(pRoot == NULL){
        return NULL;
    }else if(pRoot->GetValue() == val){
        return pRoot;
    }else {
        
    }
}