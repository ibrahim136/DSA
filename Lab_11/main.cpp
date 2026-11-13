#include <iostream>
#include <vector>
#include <climits>
#include "Max_Heap.h"

int main() {
    // 1. Testing Constructor & Initialization
    std::cout << "=== 1. Testing Constructor ===" << std::endl;
    // هنستخدم نفس الأرقام اللي كانت في السلايدز عشان نسهل التتبع
    std::vector<int> initial_data = {10, 20, 30, 25, 5, 40, 35};
    std::cout << "Original elements: 10, 20, 30, 25, 5, 40, 35\n";
    
    Max_Heap heap(initial_data);
    
    std::cout << "Heap levels after creation:\n";
    heap.print_levels(); 

    // 2. Testing Insert
    std::cout << "\n=== 2. Testing Insert (50) ===" << std::endl;
    heap.Insert(50);
    std::cout << "Heap levels after inserting 50:\n";
    heap.print_levels(); 

    // 3. Testing Delete (Extract Max)
    std::cout << "\n=== 3. Testing Delete ===" << std::endl;
    int max_val = heap.Delete();
    std::cout << "Deleted Value (Max): " << max_val << std::endl; 
    std::cout << "Heap levels after deletion:\n";
    heap.print_levels(); 

    // 4. Testing Heap Sort
    std::cout << "\n=== 4. Testing Heap Sort ===" << std::endl;
    // دالة السورت بتفضي الشجرة كلها
    std::vector<int> sorted_arr = heap.Heap_Sort();
    
    std::cout << "Sorted Array (Ascending In-place): ";
    for(int num : sorted_arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 5. Testing Edge Case: Delete from Empty Heap
    std::cout << "\n=== 5. Testing Delete on Empty Heap ===" << std::endl;
    // بما إن الـ Heap_Sort مسحت كل حاجة، المفروض الـ size دلوقتي بصفر
    int empty_delete_val = heap.Delete();
    
    if (empty_delete_val == INT_MIN) {
        std::cout << "Success! Attempted to delete from empty heap and received INT_MIN (-2147483648) as expected." << std::endl;
    } else {
        std::cout << "Failed: Received " << empty_delete_val << " instead of INT_MIN." << std::endl;
    }
    std::cout << "=======================================\n";

    return 0;
}