#include "Circular_Queue.h"

Circular_Queue::Circular_Queue() : arr{new int[Default_Capacity]}, capacity(Default_Capacity), size{0}, front(0), rear(0) {}

Circular_Queue::Circular_Queue(int capacity) : arr{new int[capacity]}, capacity{capacity}, size{0}, front(0), rear(0) {}



Circular_Queue::~Circular_Queue()
{
    delete [] arr;
}

int Circular_Queue::Get_Capacity() const{return capacity;}

void Circular_Queue::Enqueue(int data)
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

int Circular_Queue::dequeue()
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
void Circular_Queue::display()
{
    int temp_index = front;
    for (int i = 0;i<size;i++)
    {
        std::cout << arr[temp_index] << " ";
        temp_index = Increment_Index(temp_index);
    }
    return;
}

int Circular_Queue::Increment_Index(int index)
{
    return ( (index+ 1) % capacity );
}

bool Circular_Queue::IsEmpty () const
{
    return size==0;
}
bool Circular_Queue::IsFull() const{
    return size==capacity;
}

int Circular_Queue::Get_Size() const{
    return size;
}

int Circular_Queue::Get_Front() const
{
    if (IsEmpty()){
        std::cout << "\nThe Queue is Empty\n";
        return INT_MIN;
    }
    return arr[front];
}

int Circular_Queue::Get_Rear() const
{
    if (IsEmpty()){
        std::cout << "\nThe Queue is Empty\n";
        return INT_MIN;
    }
    return arr[(rear - 1 + capacity) % capacity];
}
