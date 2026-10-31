#ifndef _STACK_ARR_H_
#define _STACK_ARR_H_

#include <climits>
#include<iostream>

class Stack_Arr
{
private:
    int *arr;
    int capacity;
    int sp;

public:
    Stack_Arr();
    Stack_Arr(int capacity);
    ~Stack_Arr();
    bool IsEmpty();
    bool IsFull();
    int pop();
    int peek();
    void push(int data);
    void display();
};

#endif