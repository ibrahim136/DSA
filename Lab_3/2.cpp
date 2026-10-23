#include <vector>
#include <iostream>
#include <limits.h>

int* get_missing_single_element_in_sorted_array(std::vector<int> v)
{
    int* ret;
    if ((int)v.size() <3)
    {
        ret = nullptr;
    }
    else{
        ret = nullptr;
        int diff = (v.back() - v.front()) / ((int)v.size());
        for (int i{1};i<(int)v.size();i++)
        {
            if (v[i] != v[i-1] + diff)
            {
                ret = new int (v[i-1] + diff);
                break;
            }
        }
    }
    return ret;
}

void print_get_missing_single_element_in_sorted_array(std::vector<int> v)
{
    if ((int)v.size()){
        std::cout << "Elements in the vector: ";
        for (int x: v)
        {
            std::cout << x << " ";
        }
        std::cout << "\n";
        int * missing_element = get_missing_single_element_in_sorted_array(v);
        if (!missing_element)
        {
            std::cout << "There's no missing element";
            if ((int)v.size() < 3)
            {
                std::cout << "\nThere's no Logic to get missing element for Vector of elements lees than 3\n";
            }
        }
        else{
            std::cout << "\nThe missing Element: ";
            std::cout << *missing_element;
            delete missing_element;
        }
    }
    return;
}

int main(void)
{
    print_get_missing_single_element_in_sorted_array({5,20});
    print_get_missing_single_element_in_sorted_array({5,20,35});

}