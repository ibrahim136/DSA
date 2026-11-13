#include "Max_Heap.h"

Max_Heap::Max_Heap(std::vector<int> a):size{0}
{
    for (int x : a)
    {
        Insert(x);
    }   
}
void Max_Heap::Insert(int key)
{
    arr.push_back(key);
    size++;
    Heapify_Insert();
}
int Max_Heap::Delete()
{
    if (size==0)
    {
        return INT_MIN;
    }
    int deletedvalue;
    int i;
    int j;
    deletedvalue = arr[0];
    arr[0] = arr[size-1];
    i=0;
    j=2*i+1;
    size--;
    while(j<size)
    {
        if (j+1<size && arr[j] < arr[j+1]) j++;
        if (arr[i] < arr[j])
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i=j;
            j=2*i+1;
        }
        else{
            break;
        }
    }
    arr[size] = deletedvalue;
    return deletedvalue;
}

void Max_Heap::Heapify_Insert()
{
    int temp = arr[size-1];
    int i =size-1;
    while(i>0 && temp >arr[(i-1)/2])
    {
        arr[i] = arr[(i-1)/2];
        i= (i-1)/2;
    }
    arr[i] = temp;
}

std::vector<int> Max_Heap::Heap_Sort()
{
    while(size)
    {
        Delete();
    }
    return arr;
}

void Max_Heap::print_levels()
{
    int i=0;
    int count=1;
    while(i<size)
    {
        int j=i;
        int temp_count = count;
        while(j<size && temp_count--)
        {
            std::cout << arr[j] << " ";
            j++;
        }
        std::cout << std::endl;
        count *= 2;
        i= j;
    }
}
