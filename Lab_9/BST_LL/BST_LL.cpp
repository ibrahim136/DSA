#include "BST_LL.h"

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

Node* &Node::Get_Left()
{
    return left;
}

Node *& Node::Get_Right()
{
    return right;
}
int Node::Get_Data()
{
    return data;
}
Node& Node::operator=(const Node& other)
{
    if (this != &other) {
        this->left = other.left;
        this->right = other.right;
        this->data = other.data;
    }
    return *this;
}

//--------------------------------------------------------------------------------------------

BST_LL::BST_LL() : root{nullptr} {}

BST_LL::BST_LL(const std::vector<int>& array, Order order) : root(nullptr)
{
    if (array.empty() || array[0] == INT_MIN)
    {
        return;
    }
    if (order == Postorder)
    {
        std::stack<Node *> s;
        root = new Node(array.back());
        s.push(root);
        for (int i = static_cast<int>(array.size()) - 2; i >= 0; i--)
        {
            Node * NewNode = new Node(array[i]);
            if (s.top()->Get_Data() < array[i])
            {
                s.top()->Set_Right(NewNode);
            }
            else
            {
                Node *temp = nullptr;
                while (!s.empty() && s.top()->Get_Data() > array[i])
                {
                    temp = s.top();
                    s.pop();
                }
                if (temp) temp->Set_Left(NewNode);
            }
            s.push(NewNode);
        }
    }
    else if (order == Preorder)
    {
        std::stack<Node *> s;
        root = new Node(array[0]);
        s.push(root);
        for (int i = 1; i < static_cast<int>(array.size()); i++)
        {
            Node * NewNode = new Node(array[i]);
            if (s.top()->Get_Data() > array[i])
            {
                s.top()->Set_Left(NewNode);
            }
            else
            {
                Node *temp = nullptr;
                while (!s.empty() && s.top()->Get_Data() < array[i])
                {
                    temp = s.top();
                    s.pop();
                }
                if (temp) temp->Set_Right(NewNode);
            }
            s.push(NewNode);
        }
    }
}

BST_LL::~BST_LL()
{
    free_all_nodes(root);
}

void BST_LL::free_all_nodes(Node *node)
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



void BST_LL::Print_Preorder(Node *node) const
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

void BST_LL::Print_Inorder(Node *node) const
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

void BST_LL::Print_Postorder(Node *node) const
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

void BST_LL::Print_Preorder() const
{
    std::cout << "Preorder: ";
    Print_Preorder(root);
    std::cout << std::endl;
    return;
}

void BST_LL::Print_Inorder() const
{
    std::cout << "Inorder: ";
    Print_Inorder(root);
    std::cout << std::endl;
    return;
}

void BST_LL::Print_Postorder() const
{
    std::cout << "Postorder: ";
    Print_Postorder(root);
    std::cout << std::endl;
    return;
}

int BST_LL::count_leaf_nodes(Node *node) const
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

int BST_LL::count_leaf_nodes() const
{
    return count_leaf_nodes(root);
}

int BST_LL::count_tree_nodes(Node *node) const
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

int BST_LL::count_tree_nodes() const
{
    return count_tree_nodes(root);
}

void BST_LL::Print_Levels(Node *node) const
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

void BST_LL::Print_Levels() const
{
    std::cout << "Levels: \n";
    Print_Levels(root);
    std::cout << std::endl;
    return;
}

bool BST_LL::Search(int key) const
{
    Node* curr = root;
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

void BST_LL::Insert(int key)
{
    Node** curr = &root;
    while (*curr)
    {
        if (key < (*curr)->Get_Data())
        {
            curr = &((*curr)->Get_Left());
        }
        else if (key > (*curr)->Get_Data())
        {
            curr = &((*curr)->Get_Right());
        }
        else
        {
            break;
        }
    }
    if (!*curr) *curr = new Node(key);
    return;
}

Node* BST_LL::PredecessorParent(Node* node) const
{
    while (node->Get_Right() && node->Get_Right()->Get_Right())
    {
        node = node->Get_Right();
    }
    return node;
}

bool BST_LL::DeleteNode(Node*& node, int key)
{
    if (!node) return false;
    if (key < node->Get_Data())
    {
        return DeleteNode(node->Get_Left(),key);
    }
    else if (key > node->Get_Data())
    {
        return DeleteNode(node->Get_Right(),key);
    }
    else
    {
        if (!node->Get_Left())
        {
            Node * temp = node;
            node = node->Get_Right();
            delete temp;
            return true;
        }
        else if (!node->Get_Right())
        {
            Node * temp = node;
            node = node->Get_Left();
            delete temp;
            return true;
        }
        else
        {
            Node* preparent = PredecessorParent(node->Get_Left());
            if (!preparent->Get_Right())
            {
                node->Set_Data(preparent->Get_Data());
                node->Set_Left(preparent->Get_Left());
                delete preparent;
                return true;
            }
            Node * temp = preparent->Get_Right();
            node->Set_Data(temp->Get_Data());
            preparent->Set_Right(temp->Get_Left());
            delete temp;
            return true;
        }
    }
}

bool BST_LL::DeleteNode(int key)
{
    return DeleteNode(root,key);
}