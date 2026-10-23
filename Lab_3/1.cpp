#include <vector>
#include <iostream>

std::vector <std::pair<int,int>> pairs_to_get_sum(std::vector <int> v,int k)
{
    std::vector<std::pair<int,int>> ret;
    for (int i{0};i<(int)(v.size());i++)
    {
        for (int j{i};j<(int)(v.size());j++)
        {
            if (v[i] + v[j] == k){
                ret.push_back(std::make_pair(v[i],v[j]));
            }
        }
    }
    return ret;

}


int  main()
{
    std::vector<int> test = {1,2,3,4,5,6};
    int k = 7;
    std::vector<std::pair<int,int>> result = pairs_to_get_sum(test,k);
    for (std::pair pair_result : result){
        std::cout << pair_result.first << " + " << pair_result.second;
        std::cout << " = " << k << std::endl;
    }
    return 0;
}