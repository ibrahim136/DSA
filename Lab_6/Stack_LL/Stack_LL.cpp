#include "Stack_LL.h"

Node::Node() : next{nullptr} {}
Node::Node(int data) : data{data}, next{nullptr} {}
Node::Node(int data, Node *next) : data{data}, next{next} {}

void Node::Set_data(int data)
{
    this->data = data;
}

void Node::Set_next(Node *next)
{
    this->next = next;
}

int Node::Get_data()
{
    return data;
}

Node *Node::Get_next()
{
    return next;
}

Stack_LL::Stack_LL() : head(nullptr) {}

Stack_LL::Stack_LL(int head) : head(new Node(head)) {}

Stack_LL::~Stack_LL()
{
    while (head)
    {
        Node *temp = head;
        head = head->Get_next();
        delete temp;
    }
    head = nullptr;
}

bool Stack_LL::IsEmpty() { return !head; }

int Stack_LL::pop()
{
    if (IsEmpty())
    {
        return INT_MIN;
    }
    int ret = head->Get_data();
    Node *temp = head;
    head = head->Get_next();
    delete temp;
    return ret;
}

int Stack_LL::peek()
{
    if (IsEmpty())
    {
        return INT_MIN;
    }
    return head->Get_data();
}

void Stack_LL::push(int data)
{
    Node *NewNode = new Node(data, head);
    head = NewNode;
}

void Stack_LL::display()
{
    Node *temp = head;
    while (temp)
    {
        std::cout << temp->Get_data() << " ";
        temp = temp->Get_next();
    }
}