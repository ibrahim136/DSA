#ifndef _CIRCULAR_H_
#define _CIRCULAR_H_

#include <iostream>
#include <climits>

constexpr int Default_Capacity = 5;
class Circular_Queue
{
private:
    int *arr;
    int capacity;
    int size;
    int front;
    int rear;

public:
    Circular_Queue();
    Circular_Queue(int capacity);
    ~Circular_Queue();
    int Get_Capacity() const;
    void Enqueue(int data);
    int dequeue();
    void display();
    bool IsEmpty() const;
    bool IsFull() const;
    int Increment_Index(int index);
    int Get_Size() const;
    int Get_Front() const;
    int Get_Rear() const;

};

#endif