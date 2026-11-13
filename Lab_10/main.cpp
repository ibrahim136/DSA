#include "AVL_LL.h"
#include <iostream>
#include <vector>

int main()
{
    std::cout << "========================================\n";
    std::cout << "       AVL Tree Comprehensive Test      \n";
    std::cout << "========================================\n\n";

    // ---------------------------------------------------------
    // 1. اختبار الإضافة والـ Rotations
    // ---------------------------------------------------------
    std::cout << "[1] Testing Insertions & Rotations...\n";
    AVL_LL tree;
    
    // الأرقام دي متعمدة عشان تجبر الشجرة تعمل Single و Double Rotations
    std::vector<int> elements = {50, 30, 70, 20, 40, 60, 80, 10, 45, 35};
    for (int el : elements)
    {
        tree.Insert(el);
    }
    
    // المفروض الروت يفضل 50، والشجرة تتوزع يمين وشمال بشكل متوازن
    tree.Print_Levels();


    // ---------------------------------------------------------
    // 2. اختبار دوال الطباعة (Traversals)
    // ---------------------------------------------------------
    std::cout << "\n[2] Testing Traversals...\n";
    // الـ Inorder لازم دايماً يطبع الأرقام مترتبة تصاعدياً (لو مش مترتبة يبقى فيه بج)
    tree.Print_Inorder();   
    tree.Print_Preorder();
    tree.Print_Postorder();


    // ---------------------------------------------------------
    // 3. اختبار البحث والعدادات
    // ---------------------------------------------------------
    std::cout << "\n[3] Testing Utilities (Search & Counters)...\n";
    std::cout << "Total Tree Nodes (Expected 10): " << tree.count_tree_nodes() << "\n";
    std::cout << "Total Leaf Nodes: " << tree.count_leaf_nodes() << "\n";
    
    std::cout << "Search for 45 (Exists): " << (tree.Search(45) ? "Found" : "Not Found") << "\n";
    std::cout << "Search for 99 (Not Exists): " << (tree.Search(99) ? "Found" : "Not Found") << "\n";


    // ---------------------------------------------------------
    // 4. اختبار المسح (Deletions) - أهم وأعقد جزء
    // ---------------------------------------------------------
    std::cout << "\n[4] Testing Deletions (With Re-balancing)...\n";
    
    std::cout << "-> Case 1: Deleting a Leaf Node (10)\n";
    tree.DeleteNode(10);
    tree.Print_Levels();

    std::cout << "\n-> Case 2: Deleting a Node with 1 Child (20)\n";
    // النود 20 دلوقتي ملهاش غير Child واحد بعد مسح الـ 10
    tree.DeleteNode(20);
    tree.Print_Levels();

    std::cout << "\n-> Case 3: Deleting a Node with 2 Children (30) - Tests Predecessor logic\n";
    // النود 30 ليها (35) في الشمال و (40 و 45) في اليمين
    tree.DeleteNode(30);
    tree.Print_Levels();

    std::cout << "\n-> Edge Case: Deleting the Root (50)\n";
    // هيمسح الروت ويجيب أكبر قيمة في فرع الشمال (45) يخليها الروت الجديد
    tree.DeleteNode(50);
    tree.Print_Levels();


    // ---------------------------------------------------------
    // 5. اختبار بناء الشجرة من Vectors (Constructors)
    // ---------------------------------------------------------
    std::cout << "\n[5] Testing Constructors from Vectors...\n";
    
    std::cout << "-> Building Tree from Preorder Vector {30, 20, 10, 25, 40}:\n";
    std::vector<int> pre_vec = {30, 20, 10, 25, 40};
    AVL_LL pre_tree(pre_vec, Preorder);
    pre_tree.Print_Levels();
    pre_tree.Print_Inorder(); // للتأكد إنها AVL سليمة ومترتبة

    std::cout << "\n-> Building Tree from Postorder Vector {10, 25, 20, 40, 30}:\n";
    std::vector<int> post_vec = {10, 25, 20, 40, 30};
    AVL_LL post_tree(post_vec, Postorder);
    post_tree.Print_Levels();
    post_tree.Print_Inorder();

    std::cout << "\n========================================\n";
    std::cout << "          All Tests Completed!          \n";
    std::cout << "========================================\n";

    return 0;
}