/* 
 * File:   Node.h
 * Author: TimberDragon
 *
 * Created on November 29, 2015, 7:55 PM
 */
#include <cstddef>
#ifndef NODE_H
#define	NODE_H

class Node {
public:
    Node();
    Node(int val);
    Node(int val, Node* next);
    virtual ~Node();
    
    Node* getNext();
    void setNext(Node* next);
    int getValue();
    void setValue(int val);
private:
    int value;
    Node *pNext;

};

#endif	/* NODE_H */

