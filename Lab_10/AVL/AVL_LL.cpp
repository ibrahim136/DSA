#include "AVL_LL.h"

Node::Node() : left{nullptr}, right{nullptr} {}
Node::Node(int data) : data{data}, left{nullptr}, right{nullptr}, height{1} {}

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

void Node::Set_Height(int height)
{
    this->height = height;
    return;
}

Node *&Node::Get_Left()
{
    return left;
}

Node *&Node::Get_Right()
{
    return right;
}
int Node::Get_Data()
{
    return data;
}

int Node::Get_Height()
{
    return height;
}

Node &Node::operator=(const Node &other)
{
    if (this != &other)
    {
        this->left = other.left;
        this->right = other.right;
        this->data = other.data;
    }
    return *this;
}

//--------------------------------------------------------------------------------------------

AVL_LL::AVL_LL() : root{nullptr} {}

AVL_LL::AVL_LL(const std::vector<int> &array, Order order) : root(nullptr)
{
    if (array.empty() || array[0] == INT_MIN)
    {
        return;
    }
    if (order == Postorder)
    {
        for (int i = static_cast<int>(array.size()) - 1; i >= 0; i--)
        {
            Insert(array[i]);
        }
    }
    else if (order == Preorder)
    {
        for (int i = 0; i < static_cast<int>(array.size()); i++)
        {
            Insert(array[i]);
        }
    }
}

AVL_LL::~AVL_LL()
{
    free_all_nodes(root);
}

void AVL_LL::free_all_nodes(Node *node)
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

void AVL_LL::Print_Preorder(Node *node) const
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

void AVL_LL::Print_Inorder(Node *node) const
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

void AVL_LL::Print_Postorder(Node *node) const
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

void AVL_LL::Print_Preorder() const
{
    std::cout << "Preorder: ";
    Print_Preorder(root);
    std::cout << std::endl;
    return;
}

void AVL_LL::Print_Inorder() const
{
    std::cout << "Inorder: ";
    Print_Inorder(root);
    std::cout << std::endl;
    return;
}

void AVL_LL::Print_Postorder() const
{
    std::cout << "Postorder: ";
    Print_Postorder(root);
    std::cout << std::endl;
    return;
}

int AVL_LL::count_leaf_nodes(Node *node) const
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

int AVL_LL::count_leaf_nodes() const
{
    return count_leaf_nodes(root);
}

int AVL_LL::count_tree_nodes(Node *node) const
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

int AVL_LL::count_tree_nodes() const
{
    return count_tree_nodes(root);
}

void AVL_LL::Print_Levels(Node *node) const
{
    if (node)
    {
        std::queue<Node *> q;
        q.push(node);
        int level_count = 1;
        int next_level_count = 0;
        while (!q.empty())
        {
            if (level_count == 0)
            {
                std::cout << std::endl;
                level_count = next_level_count;
                next_level_count = 0;
            }

            Node *temp = q.front();
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

void AVL_LL::Print_Levels() const
{
    std::cout << "Levels: \n";
    Print_Levels(root);
    std::cout << std::endl;
    return;
}

bool AVL_LL::Search(int key) const
{
    Node *curr = root;
    while (curr != nullptr)
    {
        if (curr->Get_Data() == key)
            return true;
        else if (key < curr->Get_Data())
            curr = curr->Get_Left();
        else
            curr = curr->Get_Right();
    }
    return false;
}

void AVL_LL::Insert(Node **node, int key)
{
    if (!(*node))
    {
        *node = new Node(key);
        return;
    }
    if (key < (*node)->Get_Data())
    {
        Insert(&((*node)->Get_Left()), key);
    }
    else if (key > (*node)->Get_Data())
    {
        Insert(&((*node)->Get_Right()), key);
    }
    else
    {
        return;
    }
    Set_Node_height(node);
    BalanceTree(node);
}

void AVL_LL::Insert(int key)
{
    Insert(&root, key);
}



bool AVL_LL::DeleteNode(Node *&node, int key)
{
    if (!node)
        return false;

    bool isDeleted = false;
    if (key < node->Get_Data())
    {
        isDeleted = DeleteNode(node->Get_Left(), key);
    }
    else if (key > node->Get_Data())
    {
        isDeleted = DeleteNode(node->Get_Right(), key);
    }
    else
    {
        isDeleted = true;
        if (!node->Get_Left())
        {
            Node *temp = node;
            node = node->Get_Right();
            delete temp;
        }
        else if (!node->Get_Right())
        {
            Node *temp = node;
            node = node->Get_Left();
            delete temp;
        }
        else
        {
            Node *temp = node->Get_Left();
            while (temp->Get_Right())
            {
                temp = temp->Get_Right();
            }
            node->Set_Data(temp->Get_Data());
            DeleteNode(node->Get_Left(), temp->Get_Data());
        }
    }
    if (node)
    {
        Set_Node_height(&node);
        BalanceTree(&node);
    }

    return isDeleted;
}

bool AVL_LL::DeleteNode(int key)
{
    return DeleteNode(root, key);
}

Node *AVL_LL::R_Rotation(Node **node)
{
    Node *left_child = (*node)->Get_Left();     // B
    (*node)->Set_Left(left_child->Get_Right()); // left of A = Right of B
    left_child->Set_Right(*node);               // right of B = A
    Set_Node_height(node);
    Set_Node_height(&left_child);
    return left_child; // B
}

Node *AVL_LL::L_Rotation(Node **node)
{
    Node *right_child = (*node)->Get_Right();
    (*node)->Set_Right(right_child->Get_Left());
    right_child->Set_Right(*node);
    Set_Node_height(node);
    Set_Node_height(&right_child);
    return right_child;
}

Node *AVL_LL::RL_Rotation(Node **node)
{
    (*node)->Set_Right(R_Rotation(&((*node)->Get_Right())));
    *node = L_Rotation(node);
    return *node;
}

Node *AVL_LL::LR_Rotation(Node **node)
{
    (*node)->Set_Left(L_Rotation(&((*node)->Get_Left())));
    *node = R_Rotation(node);
    return *node;
}

void AVL_LL::Set_Node_height(Node **node)
{
    int lh, rh;
    lh = (*node) && (*node)->Get_Left() ? (*node)->Get_Left()->Get_Height() : 0;
    rh = (*node) && (*node)->Get_Right() ? (*node)->Get_Right()->Get_Height() : 0;
    (*node)->Set_Height(lh > rh ? lh + 1 : rh + 1);
}

int AVL_LL::BalanceFactor(Node **node)
{
    int lh, rh;
    lh = (*node) && (*node)->Get_Left() ? (*node)->Get_Left()->Get_Height() : 0;
    rh = (*node) && (*node)->Get_Right() ? (*node)->Get_Right()->Get_Height() : 0;
    return lh - rh;
}

void AVL_LL::BalanceTree(Node **node)
{
    int BF_node = BalanceFactor(node);
    if (BF_node == 2)
    {
        int BF_left = BalanceFactor(&(*node)->Get_Left());
        if (BF_left == 1 || BF_left == 0)
        {
            *node = R_Rotation(node);
        }
        else
        {
            *node = LR_Rotation(node);
        }
    }
    else if (BF_node == -2)
    {
        int BF_right = BalanceFactor(&(*node)->Get_Right());
        if (BF_right == -1 || BF_right == 0)
        {
            *node = L_Rotation(node);
        }
        else
        {
            *node = RL_Rotation(node);
        }
    }
    Set_Node_height(node);
}
