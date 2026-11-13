#include "vector"
#include "iostream"
#include <climits>

class Max_Heap
{
private:
    std::vector<int> arr;
    int size;
    void Heapify_Insert();
public:
    Max_Heap(std::vector<int> a);
    void Insert(int key);
    int Delete();
    std::vector<int> Heap_Sort();
    void print_levels();
};