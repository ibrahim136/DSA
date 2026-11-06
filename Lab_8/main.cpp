#include "BT_LL/BT_LL.h"

int main()
{
    /*
            1
        2       3
      4   5       6

    */

    std::vector<int> arr = {1, 2, 3, 4, 5, INT_MIN, 6};
    BT_LL tree1(arr);

    std::cout << "Testing Vector Constructor:\n";
    tree1.Print_Preorder();
    tree1.Print_Inorder();
    tree1.Print_Postorder();
    tree1.Print_Levels();
    
    std::cout << "Total Nodes: " << tree1.count_tree_nodes() << "\n";
    std::cout << "Leaf Nodes: " << tree1.count_leaf_nodes() << "\n\n";
    
    std::cout << "Testing enter_tree():\n";
    BT_LL tree2;
    tree2.enter_tree();
    
    
    tree2.Print_Preorder();
    tree2.Print_Inorder();
    tree2.Print_Postorder();
    tree2.Print_Levels();

    std::cout << "Total Nodes: " << tree2.count_tree_nodes() << "\n";
    std::cout << "Leaf Nodes: " << tree2.count_leaf_nodes() << "\n";

    return 0;
}