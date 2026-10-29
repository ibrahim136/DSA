#include <iostream>
#include <vector>


void RemoveDuplicates(std::vector<int> & v)
{
    std::vector<int>::iterator slow = v.begin();
    while (slow != v.end())
    {
        std::vector<int>::iterator fast = slow+1;
        while(fast != v.end())  //{1,15,7,20,1,16,15,7,4,2,1};
        {
            if (*slow == * fast)
            {
                std::vector<int>::iterator temp_it = fast;
                v.erase(fast);
                fast = temp_it;
            }
            else{
            fast++;
            }
        }
        slow++;
    }
    return;
}

void PrintVector(std::vector<int> v)
{
    for (int num : v) //خلتها num
    // بس مش مبصمجها كدة
    {
        std::cout << num << " ";
    }
    std::cout << "\n\n";
}

int main(){
    std::vector<int> v = {1,15,7,20,1,16,15,7,4,2,1};
    PrintVector(v);
    RemoveDuplicates(v);
    PrintVector(v);
}