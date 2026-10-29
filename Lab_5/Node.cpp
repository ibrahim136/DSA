#include <iostream>
#include "Node.h"

Node::Node() : next{nullptr}, prev{nullptr} {}

Node::Node(int data) : data(data), next{nullptr}, prev{nullptr} {}

Node::Node(int data, Node *next, Node *prev)
{
    this->data = data;
    this->next = next;
    this->prev = prev;
}

void Node::SetNext(Node *next)
{
    this->next = next;
}

void Node::SetPrev(Node *prev)
{
    this->prev = prev;
}

void Node::SetData(int data)
{
    this->data = data;
}

Node *Node::GetNext()
{
    return next;
}

Node *Node::GetPrev()
{
    return prev;
}

int Node::GetData()
{
    return data;
}