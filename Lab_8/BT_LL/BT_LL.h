#ifndef _BT_LL_H_
#define _BT_LL_H_

#include <iostream>
#include <vector>
#include <climits>
#include <queue>

class Node
{
private:
    int data;
    Node *left;
    Node *right;

public:
    Node();
    Node(int data);
    void Set_Left(Node *left);
    void Set_Right(Node *right);
    void Set_Data(int data);
    Node *Get_Left();
    Node *Get_Right();
    int Get_Data();
    
};

class BT_LL
{
private:
    Node *root;
    void free_all_nodes(Node * node);
    void Print_Preorder(Node * node) const;
    void Print_Inorder(Node * node) const;
    void Print_Postorder(Node * node) const;
    void Print_Levels(Node * node) const;
    int count_tree_nodes(Node * node) const;
    int count_leaf_nodes(Node * node) const;
public:
    BT_LL();
    BT_LL(std::vector<int> array);
    ~BT_LL();
    void enter_tree();
    void Print_Preorder() const;
    void Print_Inorder() const;
    void Print_Postorder() const;
    void Print_Levels() const;
    int count_tree_nodes() const;
    int count_leaf_nodes() const;
    
};

#endif