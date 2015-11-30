/* 
 * File:   LinkedLists.h
 * Author: TimberDragon
 *
 * Created on November 29, 2015, 6:18 PM
 */
#include "Node.h"
#ifndef LINKEDLISTS_H
#define	LINKEDLISTS_H

class LinkedList {
public:
    LinkedList();
    LinkedList(int val);
    ~LinkedList();
    void DeleteNode(int val);
    void DeleteDuplicates(); //2.1
private:
    Node* pHead;

};

#endif	/* LINKEDLISTS_H */

