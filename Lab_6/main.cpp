#include <iostream>
#include "Stack_Arr.h"
#include "Stack_LL.h"

int main(void)
{
    std::cout << "\n\nTesting Stack_Arr Class\n\n";
    Stack_Arr Stack_Arr_Object_test(5);
    Stack_Arr_Object_test.push(10);
    Stack_Arr_Object_test.push(20);
    Stack_Arr_Object_test.push(30);
    Stack_Arr_Object_test.push(40);
    Stack_Arr_Object_test.push(50);
    Stack_Arr_Object_test.push(60);
    std::cout << "Stack elements: ";
    Stack_Arr_Object_test.display();
    std::cout << "\nTop element (peek): " << Stack_Arr_Object_test.peek() << "\n";
    std::cout << "Popped: " << Stack_Arr_Object_test.pop() << "\n";
    std::cout << "After pop: ";
    Stack_Arr_Object_test.display();
    std::cout << "\n\n";

    for (int i=0;i<5;i++){
        Stack_Arr_Object_test.pop();
    }

    std::cout << "\n\nTesting Stack_LL Class\n\n";
    Stack_LL Stack_LL_Object_test;
    Stack_LL_Object_test.push(100);
    Stack_LL_Object_test.push(200);
    Stack_LL_Object_test.push(300);
    std::cout << "Stack elements: ";
    Stack_LL_Object_test.display();
    std::cout << "\nTop element (peek): " << Stack_LL_Object_test.peek() << "\n";
    std::cout << "Popped: " << Stack_LL_Object_test.pop() << "\n";
    std::cout << "After pop: ";
    Stack_LL_Object_test.display();
    std::cout << "\n";

    for (int i=0;i<3;i++){
        Stack_LL_Object_test.pop();
    }

    return 0;
}