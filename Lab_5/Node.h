#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
#include <climits>

class Node
{
private:
    int data;
    Node *next;
    Node *prev;

public:
    Node();
    Node(int data);
    Node(int data, Node *next, Node *prev);
    void SetNext(Node *next);
    void SetPrev(Node *prev);
    void SetData(int data);
    Node *GetNext();
    Node *GetPrev();
    int GetData();
};


#endif