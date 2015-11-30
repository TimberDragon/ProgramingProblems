/* 
 * File:   LinkedList.cpp
 * Author: TimberDragon
 * 
 * Created on November 29, 2015, 6:18 PM
 */

#include "LinkedList.h"

LinkedList::LinkedList() {
    pHead = NULL;
}

LinkedList::LinkedList(int val) {
    pHead = new Node(val);
}

LinkedList::~LinkedList() {
    //TODO Delete linked list
}

LinkedList::DeleteNode(int val) {
    Node* previous = NULL;
    Node* current = pHead;
    while(current != NULL) {    
        if(current->getValue() == val) { // deletes the node
            if(previous == NULL) {//if head
                pHead = NULL;
                delete current;
            }else if(current->getNext() == NULL) {// tail
                previous->setNext(NULL);
            }else {
                previous->setNext(current->getNext());
            }
            return;
        }
        previous = current;
        current = current->getNext();
    }
    //not found
    return;
}

LinkedList::DeleteDuplicates() {
    
}

