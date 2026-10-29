#include <vector>
#include <iostream>
#include <limits.h>

int get_smallest_diff(std::vector<int> v)
{
    int min = v[1] - v[0]; //اول فرق
    int corr = min<0? -1 : 1; //لو سالب هات سالب هنستعمله
    min *= corr; //اضرب ف التعديل
    for (int i=2;i<(int)v.size();i++) //لف
    {
        if (corr*(v[i]-v[i-1]) < min){ // قارن القيم تكون موجبة فقط
            min = corr*(v[i]-v[i-1]); //حط القيمة موجبة
        }
        else if (v[i]-v[i-1] == min) // لو قابلت زييها خلاص كدة الباقي زييه
        {
            break;
        }
    }
    return corr*min; // رجع الاصل لو كان سالب رجع سالب
}

int* get_missing_single_element_in_sorted_array(std::vector<int> v)
{
    int* ret = nullptr;
    if ((int)v.size()>2) //لازم اكبر من عنصرين عشان اعلاف اقارن
    {
        ret = nullptr; 
        int diff = (v.back() - v.front()) / ((int)v.size()); //الفرق بين الكبير و الصغير
        int smallest_diff = get_smallest_diff(v); //اصغر فرق بين عنصرين
        if (diff == smallest_diff) // لو زي بعض يبقا فيه عنصر ناقص
        {
            for (int i{1};i<(int)v.size();i++) //لف اقفشه
            {
                if (v[i] != v[i-1] + diff) // لو دة مش زي اللي فات + الفرق
                {
                    ret = new int (v[i-1] + diff); //اقفشه
                    break; //يلا برا مش حلاوة هي
                }
            }
        }
    }
    return ret; //سلام
}

void print_get_missing_single_element_in_sorted_array(std::vector<int> v)
{
    if ((int)v.size()){ //هو فيه عناصر اصلاً ؟
        std::cout << "Elements in the vector: ";
        for (int x: v) // اطبع بال for range
        {
            std::cout << x << " ";
        }
        std::cout << "\n";
        int * missing_element = get_missing_single_element_in_sorted_array(v); // هات العنصر الناقص
        if (!missing_element) // لو مفيش عنصر ناقص
        {
            std::cout << "There's no missing element\n";
            if ((int)v.size() < 3) // لو العناصر عددها اقل من 3
            {
                std::cout << "There's no Logic to get missing element for Vector of elements lees than 3\n";
            }
        }
        else{ // لو فيه عنصر ناقص
            std::cout << "\nThe missing Element: "; 
            std::cout << *missing_element << "\n\n";
            delete missing_element;
        }
    }
    std::cout << "---------------------------------------\n";
    return;
}

int main(void)
{
    //test cases يارب ميكنوش فيه اي قطط فطسانة
    print_get_missing_single_element_in_sorted_array({5,20});
    print_get_missing_single_element_in_sorted_array({5,20,35});
    print_get_missing_single_element_in_sorted_array({-5,-20,-35});
    print_get_missing_single_element_in_sorted_array({5,35,50});
    print_get_missing_single_element_in_sorted_array({-5,-35,-50});

}