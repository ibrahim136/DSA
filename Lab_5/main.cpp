#include <iostream>
#include "Node.h"

int main(void)
{
    Node first(5);
    std::cout << first.GetData();
    Node second(6);
    first.SetNext(&second);
    std::cout << first.GetNext()->GetData();
}