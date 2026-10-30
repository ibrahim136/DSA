#ifndef _DLL_H_
#define _DLL_H_

#include "Node.h"
#include <vector>

class DLL
{
private:
    Node *head;
    Node *tail;
    void CheckAllocation(Node * Node);
public:
    DLL();
    DLL(int num);
    DLL(std::vector<int> v);
    void Display();
    int count();
    int sum();
    int max();
    int min();
    void InsertAtHead(int data);
    void InsertAtTail(int data);
    void InsertAtPos(int data,int pos);
    void DeleteAtHead();
    void DeleteAtTail();
    void DeleteAtPos(int pos);

};

#endif