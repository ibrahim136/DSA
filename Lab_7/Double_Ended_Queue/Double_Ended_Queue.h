#ifndef _DOUBLE_ENDED_QUEUE_H_
#define _DOUBLE_ENDED_QUEUE_H_

#include <iostream>
#include <climits>

constexpr int Default_Capacity_2 = 5;
class Double_Ended_Queue
{
private:
    int *arr;
    int capacity;
    int size;
    int front;
    int rear;

public:
    Double_Ended_Queue();
    Double_Ended_Queue(int capacity);
    ~Double_Ended_Queue();
    int Get_Capacity() const;
    void Enqueue_Rear(int data);
    void Enqueue_Front(int data);
    int Dequeue_Front();
    int Dequeue_Rear();
    void display();
    bool IsEmpty() const;
    bool IsFull() const;
    int Increment_Index(int index);
    int Decrement_Index(int index);
    int Get_Size() const;
    int Get_Front() const;
    int Get_Rear() const;

};

#endif