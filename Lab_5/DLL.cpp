#include "DLL.h"

void DLL::CheckAllocation(Node *Node)
{
    if (!Node)
    {
        exit(1);
    }
}

DLL::DLL() : head{nullptr}, tail{nullptr} {}

DLL::DLL(int num) : tail{nullptr}
{
    head->SetData(num);
}

DLL::DLL(std::vector<int> v)
{
    if (!(int)v.size())
    {
        DLL();
        return;
    }
    head = new Node(v[0]);
    CheckAllocation(head);
    tail = head;
    Node *temp = head;
    for (int i = 1; i < (int)v.size(); i++)
    {
        Node *NewNode = new Node(v[i]);
        CheckAllocation(NewNode);
        temp->SetNext(NewNode);
        NewNode->SetPrev(temp);
        temp = temp->GetNext();
        tail = temp;
    }
}

void DLL::Display()
{
    Node *temp = head;
    while (temp)
    {
        std::cout << temp->GetData() << " <---> ";
    }
    std::cout << "Null Pointer\n";
}

int DLL::count()
{
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count++;
        temp = temp->GetNext();
    }
    return count;
}

int DLL::sum()
{
    int sum = 0;
    Node *temp = head;
    while (temp)
    {
        sum += temp->GetData();
    }
    return sum;
}

int DLL::max()
{
    if (!head)
    {
        return INT_MIN;
    }
    int max = head->GetData();
    Node *temp = head->GetNext();
    while (temp)
    {
        max = max < temp->GetData() ? temp->GetData() : max;
    }
    return max;
}

int DLL::min()
{
    if (!head)
    {
        return INT_MAX;
    }
    int min = head->GetData();
    Node *temp = head->GetNext();
    while (temp)
    {
        min = min > temp->GetData() ? temp->GetData() : min;
    }
    return min;
}

void DLL::InsertAtHead(int data)
{
    Node *NewNode = new Node(data);
    CheckAllocation(NewNode);
    NewNode->SetNext(head);
    head->SetPrev(NewNode);
    head = NewNode;
}

void DLL::InsertAtTail(int data)
{
    Node *NewNode = new Node(data);
    CheckAllocation(NewNode);
    tail->SetNext(NewNode);
    NewNode->SetPrev(tail);
    tail = NewNode;
}

void DLL::InsertAtPos(int data, int pos)
{
}
void DLL::DeleteAtHead(int data)
{
    Node *temp = head;
    head = head->GetNext();
    head->SetPrev(nullptr);
    delete temp;
    temp = nullptr;
}

void DLL::DeleteAtTail(int data)
{
    Node *temp = tail;
    tail = tail->GetPrev();
    tail->SetNext(nullptr);
    delete temp;
    temp = nullptr;
}

void DeleteAtPos(int data, int pos)
{
    
}