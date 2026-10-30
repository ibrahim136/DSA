#include <iostream>
#include "DLL.h"

int main(void)
{
    std::vector<int> v = {1,2,3,4,5};
    DLL Double_Linked_List(v);
    std::cout << "\n\nDouble Linked List Content: \n";
    Double_Linked_List.Display();
    std:: cout << "\nDLL Count  : " << Double_Linked_List.count();
    std:: cout << "\nDLL Sum    : " << Double_Linked_List.sum();
    std:: cout << "\nDLL Min    : " << Double_Linked_List.min();
    std:: cout << "\nDLL Max    : " << Double_Linked_List.max() << "\n\n";

    std:: cout << "DLL Before inserting at Head : \n";
    Double_Linked_List.Display();
    Double_Linked_List.InsertAtHead(47);
    std:: cout << "DLL After inserting 47 at Head : \n";
    Double_Linked_List.Display();

    std:: cout << "\n\nDLL Before inserting at End : \n";
    Double_Linked_List.Display();
    Double_Linked_List.InsertAtTail(48);
    std:: cout << "DLL After inserting 48 at End : \n";
    Double_Linked_List.Display();
    
    std:: cout << "\n\nDLL Before inserting at Specific Position : \n";
    Double_Linked_List.Display();
    Double_Linked_List.InsertAtPos(49,3);
    std:: cout << "DLL After inserting 49 at Position 3 (1-Based Index): \n";
    Double_Linked_List.Display();
    
    std:: cout << "\n\nDLL Before deleting at Head : \n";
    Double_Linked_List.Display();
    Double_Linked_List.DeleteAtHead();
    std:: cout << "DLL After deleting at Head : \n";
    Double_Linked_List.Display();

    std:: cout << "\n\nDLL Before deleting at End : \n";
    Double_Linked_List.Display();
    Double_Linked_List.DeleteAtTail();
    std:: cout << "DLL After deleting at End : \n";
    Double_Linked_List.Display();
    
    std:: cout << "\n\nDLL Before inserting at Specific Position : \n";
    Double_Linked_List.Display();
    Double_Linked_List.DeleteAtPos(2);
    std:: cout << "DLL After deleting at Position 2 (1-Based Index): \n";
    Double_Linked_List.Display();
    
    return 0;
}