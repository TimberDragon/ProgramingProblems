/* 
 * File:   Node.cpp
 * Author: TimberDragon
 * 
 * Created on November 29, 2015, 7:55 PM
 */

#include "Node.h"

Node::Node() {
    pNext = NULL;
}

Node::Node(int val) {
    value = val;
    pNext = NULL;
}

Node::Node(int val, Node* next) {
    value = val;
    pNext = next;
}

Node* Node::getNext() {
    return pNext;
}

void Node::setNext(Node* next) {
    pNext = next;
}

int Node::getValue() {
    return value;
}

void Node:: setValue(int val) {
    value = val;
}

Node::~Node() {
}

