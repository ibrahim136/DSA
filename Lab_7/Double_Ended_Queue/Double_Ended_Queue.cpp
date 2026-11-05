#include "Double_Ended_Queue.h"

Double_Ended_Queue::Double_Ended_Queue() : arr{new int[Default_Capacity_2]}, capacity(Default_Capacity_2), size{0}, front(0), rear(0) {}

Double_Ended_Queue::Double_Ended_Queue(int capacity) : arr{new int[capacity]}, capacity{capacity}, size{0}, front(0), rear(0) {}



Double_Ended_Queue::~Double_Ended_Queue()
{
    delete [] arr;
}

int Double_Ended_Queue::Get_Capacity() const{return capacity;}

void Double_Ended_Queue::Enqueue_Rear(int data)
{
    if (IsFull()){
        std::cout << "\nThe Queue is Full\n";
        return;
    }
    arr[rear] = data;
    rear = Increment_Index(rear);
    size++;
    return;
}

void Double_Ended_Queue::Enqueue_Front(int data)
{
    if (IsFull()){
        std::cout << "\nThe Queue is Full\n";
        return;
    }
    front = Decrement_Index(front);
    arr[front] = data;
    size++;
    return;
}

int Double_Ended_Queue::Dequeue_Front()
{
    if (IsEmpty()){
        std::cout << "\nThe Queue is Empty\n";
        return INT_MIN;
    }
    int temp_data = arr[front];
    front = Increment_Index(front);
    size--;
    return temp_data;
}

int Double_Ended_Queue::Dequeue_Rear()
{
    if (IsEmpty()){
        std::cout << "\nThe Queue is Empty\n";
        return INT_MIN;
    }
    rear = Decrement_Index(rear);
    size--;
    return arr[rear];
}

void Double_Ended_Queue::display()
{
    int temp_index = front;
    for (int i = 0;i<size;i++)
    {
        std::cout << arr[temp_index] << " ";
        temp_index = Increment_Index(temp_index);
    }
    return;
}

int Double_Ended_Queue::Increment_Index(int index)
{
    return ( (index+ 1) % capacity );
}

int Double_Ended_Queue::Decrement_Index(int index)
{
    return (index - 1 + capacity) % capacity;
}

bool Double_Ended_Queue::IsEmpty () const
{
    return size==0;
}
bool Double_Ended_Queue::IsFull() const{
    return size==capacity;
}

int Double_Ended_Queue::Get_Size() const{
    return size;
}

int Double_Ended_Queue::Get_Front() const
{
    if (IsEmpty()){
        std::cout << "\nThe Queue is Empty\n";
        return INT_MIN;
    }
    return arr[front];
}

int Double_Ended_Queue::Get_Rear() const
{
    if (IsEmpty()){
        std::cout << "\nThe Queue is Empty\n";
        return INT_MIN;
    }
    return arr[(rear - 1 + capacity) % capacity];
}
