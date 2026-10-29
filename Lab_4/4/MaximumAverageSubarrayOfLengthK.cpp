#include <iostream>
#include <vector>

double MaxAverageSubarray(std::vector<int> nums, int k)
{
    double max = 0;
    for (int i = 0; i < k; i++)
    {
        max += nums[i];
    }
    int sum = max;
    for (int i = 0; i < (int)nums.size() - k; i++)
    {
        sum = sum -nums[i] + nums[i+k] ;
        max = max < sum ? sum : max;
    }
    return max / k;
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
    std::vector<int> v = {1, 2, 3, 1, 1, 5, 2, 3};
    PrintVector(v);
    std::cout << MaxAverageSubarray(v, 6);
}