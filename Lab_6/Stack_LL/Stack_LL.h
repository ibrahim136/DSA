#ifndef _STACK_LL_H_
#define _STACK_LL_H_

#include <climits>
#include <iostream>

class Node
{
private:
    int data;
    Node *next;

public:
    Node();
    Node(int data);
    Node(int data, Node *next);
    void Set_data(int data);
    void Set_next(Node *next);
    int Get_data();
    Node *Get_next();
};

class Stack_LL
{
private:
    Node *head;

public:
    Stack_LL();
    Stack_LL(int data);
    ~Stack_LL();
    bool IsEmpty();
    int pop();
    int peek();
    void push(int data);
    void display();
};

#endif