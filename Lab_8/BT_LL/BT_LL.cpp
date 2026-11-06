#include "BT_LL.h"

Node::Node() : left{nullptr}, right{nullptr} {}
Node::Node(int data) : data{data}, left{nullptr}, right{nullptr} {}

void Node::Set_Left(Node *left)
{
    this->left = left;
    return;
}

void Node::Set_Right(Node *right)
{
    this->right = right;
    return;
}

void Node::Set_Data(int data)
{
    this->data = data;
    return;
}

Node *Node::Get_Left()
{
    return left;
}

Node *Node::Get_Right()
{
    return right;
}
int Node::Get_Data()
{
    return data;
}

//--------------------------------------------------------------------------------------------

BT_LL::BT_LL() : root{nullptr} {}

BT_LL::BT_LL(std::vector<int> array)
{
    if (array.empty() || array[0] == INT_MIN)
    {
        root = nullptr;
        return;
    }
    std::queue<Node *> q;
    root = new Node(array[0]);
    q.push(root);
    Node *temp;
    int i = 0;
    while (!q.empty())
    {
        if (array[i] == INT_MIN)
        {
            i++;
            continue;
        }
        temp = q.front();
        q.pop();
        if (2 * i + 1 < (int)array.size() && array[2 * i + 1] != INT_MIN)
        {
            Node *temp_left = new Node(array[2 * i + 1]);
            q.push(temp_left);
            temp->Set_Left(temp_left);
        }
        if (2 * i + 2 < (int)array.size() && array[2 * i + 2] != INT_MIN)
        {
            Node *temp_right = new Node(array[2 * i + 2]);
            q.push(temp_right);
            temp->Set_Right(temp_right);
        }
        i++;
    }
}

BT_LL::~BT_LL()
{
    free_all_nodes(root);
}

void BT_LL::free_all_nodes(Node *node)
{
    if (node)
    {
        if (node->Get_Left())
        {
            free_all_nodes(node->Get_Left());
        }
        if (node->Get_Right())
        {
            free_all_nodes(node->Get_Right());
        }
        node->Set_Left(nullptr);
        node->Set_Right(nullptr);
        delete node;
        node = nullptr;
    }
    return;
}

void BT_LL::enter_tree()
{
    std::vector<int> tree_data;
    std::queue<int> q;
    int val;
    std::cout << "Please Enter the root (type any letter for no root): ";

    if (std::cin >> val)
    {
        tree_data.push_back(val);
        q.push(val);
    }
    else
    {
        std::cin.clear();
        while (std::cin.get() != '\n')
            ;
        tree_data.push_back(INT_MIN);
    }

    while (!q.empty())
    {
        int current_val = q.front();
        q.pop();

        std::cout << "Enter left child of " << current_val << " (type any letter for no child): ";
        if (std::cin >> val)
        {
            tree_data.push_back(val);
            q.push(val);
        }
        else
        {
            std::cin.clear();
            while (std::cin.get() != '\n')
                ;
            tree_data.push_back(INT_MIN);
        }

        std::cout << "Enter right child of " << current_val << " (type any letter for no child): ";
        if (std::cin >> val)
        {
            tree_data.push_back(val);
            q.push(val);
        }
        else
        {
            std::cin.clear();
            while (std::cin.get() != '\n')
                ;
            tree_data.push_back(INT_MIN);
        }
    }

    free_all_nodes(root);
    BT_LL temp_tree(tree_data);
    root = temp_tree.root;
    temp_tree.root = nullptr;
}

void BT_LL::Print_Preorder(Node *node) const
{
    if (node)
    {
        std::cout << node->Get_Data() << " ";
        if (node->Get_Left())
        {
            Print_Preorder(node->Get_Left());
        }
        if (node->Get_Right())
        {
            Print_Preorder(node->Get_Right());
        }
    }

    return;
}

void BT_LL::Print_Inorder(Node *node) const
{
    if (node)
    {
        if (node->Get_Left())
        {
            Print_Inorder(node->Get_Left());
        }
        std::cout << node->Get_Data() << " ";
        if (node->Get_Right())
        {
            Print_Inorder(node->Get_Right());
        }
    }

    return;
}

void BT_LL::Print_Postorder(Node *node) const
{
    if (node)
    {
        if (node->Get_Left())
        {
            Print_Postorder(node->Get_Left());
        }
        if (node->Get_Right())
        {
            Print_Postorder(node->Get_Right());
        }
        std::cout << node->Get_Data() << " ";
    }

    return;
}

void BT_LL::Print_Preorder() const
{
    std::cout << "Preorder: ";
    Print_Preorder(root);
    std::cout << std::endl;
    return;
}

void BT_LL::Print_Inorder() const
{
    std::cout << "Inorder: ";
    Print_Inorder(root);
    std::cout << std::endl;
    return;
}

void BT_LL::Print_Postorder() const
{
    std::cout << "Postorder: ";
    Print_Postorder(root);
    std::cout << std::endl;
    return;
}

int BT_LL::count_leaf_nodes(Node *node) const
{
    if (!node)
    {
        return 0;
    }
    else if (!node->Get_Left() && !node->Get_Right())
    {
        return 1;
    }
    else
    {
        return count_leaf_nodes(node->Get_Left()) + count_leaf_nodes(node->Get_Right());
    }
}

int BT_LL::count_leaf_nodes() const
{
    return count_leaf_nodes(root);
}

int BT_LL::count_tree_nodes(Node *node) const
{
    if (!node)
    {
        return 0;
    }
    else
    {
        return 1 + count_tree_nodes(node->Get_Left()) + count_tree_nodes(node->Get_Right());
    }
}

int BT_LL::count_tree_nodes() const
{
    return count_tree_nodes(root);
}

void BT_LL::Print_Levels(Node* node) const
{
    if (node)
    {
        std::queue<Node*> q;
        q.push(node);
        int level_count =1;
        int next_level_count=0;
        while(!q.empty())
        {
            if (level_count==0)
            {
                std::cout << std::endl;
                level_count = next_level_count;
                next_level_count =0;
            }

            Node* temp = q.front();
            q.pop();
            std::cout << temp->Get_Data() << " ";
            if (temp->Get_Left())
            {
                q.push(temp->Get_Left());
                next_level_count++;
            }
            if (temp->Get_Right())
            {
                q.push(temp->Get_Right());
                next_level_count++;
            }
            level_count--;
        }
    }

    return;
}

void BT_LL::Print_Levels() const
{
    std::cout << "Levels: \n";
    Print_Levels(root);
    std::cout << std::endl;
    return;
}