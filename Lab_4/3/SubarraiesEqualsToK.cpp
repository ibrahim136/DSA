#include <iostream>
#include <vector>

int NumberOfSubarraiesSumEqualsTo_K(std::vector<int> nums, int k)
{
    int count = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            int sum = nums[i];
            if (sum== k){
                count++;
            }
            int j = i + 1;
            while ( j < (int)nums.size()) {
                sum += nums[j];
                if (sum == k) {
                    count++;
                }
                j++;
            }
        }

        return count;
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
    std::cout << NumberOfSubarraiesSumEqualsTo_K(v, 6);
}