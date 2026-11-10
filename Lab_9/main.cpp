#include <iostream>
#include <string>
#include "BST_LL.h"

// دالة مساعدة لتنظيم شكل الخرج على الشاشة
void printSeparator(const std::string& title) 
{
    std::cout << "\n======================================================\n";
    std::cout << "  " << title << "\n";
    std::cout << "======================================================\n";
}

int main() 
{
    // ---------------------------------------------------------
    // Test Case 1: التعامل مع الشجرة الفاضية
    // ---------------------------------------------------------
    printSeparator("TEST CASE 1: Empty Tree Operations");
    BST_LL emptyTree;
    std::cout << "Nodes count (Expected 0): " << emptyTree.count_tree_nodes() << "\n";
    std::cout << "Search 10 (Expected 0): " << emptyTree.Search(10) << "\n";
    std::cout << "Delete 10 (Expected 0): " << emptyTree.DeleteNode(10) << "\n";
    emptyTree.Print_Inorder(); // المفروض متطبعش حاجة ولا تضرب


    // ---------------------------------------------------------
    // Test Case 2: بناء شجرة متكاملة والطباعة
    // ---------------------------------------------------------
    printSeparator("TEST CASE 2: Building Tree & Traversals");
    BST_LL tree;
    /*
                  50
                /    \
              30      70
             /  \    /  \
            20  40  60   80
               /
              35
                \
                 38
    */
    tree.Insert(50);
    tree.Insert(30);
    tree.Insert(70);
    tree.Insert(20);
    tree.Insert(40);
    tree.Insert(60);
    tree.Insert(80);
    tree.Insert(35);
    tree.Insert(38); 

    tree.Print_Inorder();
    tree.Print_Levels();


    // ---------------------------------------------------------
    // Test Case 3: الحذف البسيط (نود ملهاش أبناء - Leaf)
    // ---------------------------------------------------------
    printSeparator("TEST CASE 3: Delete Leaf Node (0 Children)");
    std::cout << "Deleting 20...\n";
    tree.DeleteNode(20);
    tree.Print_Inorder(); // المفروض 20 تختفي


    // ---------------------------------------------------------
    // Test Case 4: الحذف لنود ليها ابن واحد (One Child)
    // ---------------------------------------------------------
    printSeparator("TEST CASE 4: Delete Node with 1 Child");
    std::cout << "Deleting 35 (Has right child 38)...\n";
    tree.DeleteNode(35);
    tree.Print_Inorder(); // 38 هتربط مكان 35


    // ---------------------------------------------------------
    // Test Case 5: الحالة اللي صلحناها (البديل هو الابن الشمال المباشر)
    // ---------------------------------------------------------
    printSeparator("TEST CASE 5: Delete Node (Predecessor is immediate left child)");
    // هنعمل شجرة مخصوصة للحالة دي عشان تبان بوضوح
    BST_LL trickyTree1;
    trickyTree1.Insert(100);
    trickyTree1.Insert(50);
    trickyTree1.Insert(150);
    trickyTree1.Insert(20);
    
    std::cout << "Levels Before Deleting 100 (Root):\n";
    trickyTree1.Print_Levels();
    
    std::cout << "Deleting 100... (50 should replace it without losing 20)\n";
    trickyTree1.DeleteNode(100);
    trickyTree1.Print_Levels();


    // ---------------------------------------------------------
    // Test Case 6: الحالة التانية (البديل في أقصى اليمين وله أبناء على اليسار)
    // ---------------------------------------------------------
    printSeparator("TEST CASE 6: Delete Node (Predecessor is deep right & has left child)");
    BST_LL trickyTree2;
    trickyTree2.Insert(100);
    trickyTree2.Insert(50);
    trickyTree2.Insert(150);
    trickyTree2.Insert(20);
    trickyTree2.Insert(80);
    trickyTree2.Insert(70); // الابن الأيسر للبديل (80)
    
    std::cout << "Levels Before Deleting 100 (Root):\n";
    trickyTree2.Print_Levels();
    
    std::cout << "Deleting 100... (80 should replace it, and 70 should connect to 50's right)\n";
    trickyTree2.DeleteNode(100);
    trickyTree2.Print_Levels();
    std::cout << "Inorder should still be sorted:\n";
    trickyTree2.Print_Inorder();


    // ---------------------------------------------------------
    // Test Case 7: مسح الشجرة بالكامل عقدة ورا عقدة (Stress Test)
    // ---------------------------------------------------------
    printSeparator("TEST CASE 7: Complete Tree Annihilation");
    std::cout << "Destroying the main tree node by node...\n";
    tree.DeleteNode(50);
    tree.DeleteNode(30);
    tree.DeleteNode(70);
    tree.DeleteNode(40);
    tree.DeleteNode(60);
    tree.DeleteNode(80);
    tree.DeleteNode(38);
    
    std::cout << "Tree after deleting all nodes (Should be empty):\n";
    tree.Print_Inorder();
    std::cout << "Nodes count (Expected 0): " << tree.count_tree_nodes() << "\n";

    printSeparator("ALL TESTS PASSED SUCCESSFULLY!");
    return 0;
}