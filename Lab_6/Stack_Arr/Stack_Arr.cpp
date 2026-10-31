#include "Stack_Arr.h"

Stack_Arr::Stack_Arr() : arr{new int[5]}, capacity(5), sp(-1) {}

Stack_Arr::Stack_Arr(int capacity) : arr{new int[capacity]}, capacity(capacity), sp(-1) {}

Stack_Arr::~Stack_Arr() { delete [] arr ; }

bool Stack_Arr::IsEmpty() {return sp==-1;}

bool Stack_Arr::IsFull() {return sp+1 == capacity;}

int Stack_Arr::pop() 
{
    if (IsEmpty())
    {
        return INT_MIN;
    }
    int ret = arr[sp];
    sp--;
    return ret;
}

int Stack_Arr::peek()
{
    if (IsEmpty())
    {
        return INT_MIN;
    }
    return arr[sp];
}

void Stack_Arr::push(int data)
{
    if (IsFull())
    {
        
        return;
    }
    arr[++sp] = data;
}

void Stack_Arr::display()
{
    for (int i =sp;i>=0;i--)
    {
        std::cout << arr[i] << " ";
    }
}