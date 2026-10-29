#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>


void print_vector(std::vector<int> v, std::string label)
{
    std::cout << label << ": ";
    for (int item : v)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector <int> v1{1,20,5,18,35};
    std::vector<int>::iterator it = v1.begin();
    while (it < v1.end()){
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
    std::cout << *v1.data() << std::endl;
    std::vector <int> v2{1,2,3,4,5};
    v2.swap(v1);
    print_vector(v1,"V1");
    print_vector(v2,"V2");
    std::sort(v2.begin(),v2.end());
    print_vector(v2,"V2 after sorting");
    std::ranges::sort(v2);
    print_vector(v2,"V2 after sorting using ranges");
    std::reverse(v2.begin(),v2.end());
    print_vector(v2,"V2 after reversing");
    std::ranges::reverse(v2);
    print_vector(v2,"V2 after reversing using ranges");
    
    std::vector<int>::iterator search = std::find(v2.begin(),v2.end(),20);
    std::string result = (search == v2.end()) ? "not found" : "found";
    std::cout << "searching for key 20: " <<result << std::endl;

    search = std::ranges::find(v2,20);
    result = (search == v2.end()) ? "not found" : "found";
    std::cout << "searching for key 20 using ranges: " <<result << std::endl;

    v2.push_back(18);
    std::cout << "Frequncy of key 18: " <<  std::count(v2.begin(),v2.end(),18) << std::endl;
    std::cout << "Frequncy using ranges of key 18: " <<  std::ranges::count(v2,18) << std::endl;
    std::cout << "Max of vector 2: " <<  std::ranges::max(v2) << std::endl;
    std::cout << "Min of vector 2: " <<  std::ranges::min(v2) << std::endl;
    int sum = std::accumulate(v2.begin(), v2.end(), 0);
    std::cout << "Sum of elements of vector 2: " <<  sum << std::endl;

    std::vector<int> v3 = {1,2,3,3,4,5,5,5,5,5,5};
    print_vector(v3,"V3");
    
    std::vector<int>::iterator it3 = std::unique(v3.begin(), v3.end());
    v3.erase(it3, v3.end());
    print_vector(v3,"V3 after deleting duplicates");









}