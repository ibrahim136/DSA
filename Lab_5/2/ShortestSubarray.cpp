#include <iostream>
#include <vector>

int ShortestSubarray(std::vector<int> v, int k)
{
    int n = v.size();
    int l = 0, r = 0, min_len = n+1, sum = 0;
    while (r < n)
    {
        if (sum < k)
        {
            sum += v[r];
        }
        if (sum >= k)
        {
            min_len = std::min(min_len, r - l +1 );
        }
        if (sum >= k)
        {
            sum -= v[l];
            l++;
        }
        
        if (sum < k)
        {
            r++;
        }
        
    }
    return min_len > n ? 0 : min_len;
}

void PrintVector(std::vector<int> v)
{
    for (int num : v) // خلتها num
    // بس مش مبصمجها كدة
    {
        std::cout << num << " ";
    }
    std::cout << "\n\n";
}

int main()
{
    std::vector<int> v = {1,2,3,1,1,5,2,3};
    PrintVector(v);
    std::cout << ShortestSubarray(v,6) ;
}