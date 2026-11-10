#ifndef _BST_LL_H_
#define _BST_LL_H_

#include <iostream>
#include <vector>
#include <climits>
#include <stack>
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
    Node *&Get_Left();
    Node *&Get_Right();
    int Get_Data();
    Node& operator=(const Node& other);
};

enum Order{
    Preorder,
    Inorder,
    Postorder
};

class BST_LL
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
    Node* PredecessorParent(Node* node) const;
    bool DeleteNode(Node*& node, int key);
public:
    BST_LL();
    BST_LL(const std::vector<int>& array, Order order);
    ~BST_LL();
    void Print_Preorder() const;
    void Print_Inorder() const;
    void Print_Postorder() const;
    void Print_Levels() const;
    int count_tree_nodes() const;
    int count_leaf_nodes() const;
    bool Search(int key) const;
    void Insert(int key);
    bool DeleteNode(int key);
};

#endif