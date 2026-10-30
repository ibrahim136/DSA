#include "DLL.h"

void DLL::CheckAllocation(Node * Node)
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
    std::cout << "Null  <->  ";
    while (temp)
    {
        std::cout << temp->GetData() << "  <->  ";
        temp = temp->GetNext();
    }
    std::cout << "Null\n";
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
        temp = temp->GetNext();
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
        temp = temp->GetNext();
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
        temp = temp->GetNext();
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
    if (pos < 1)
    {
        pos = 1;
    }
    if (pos == 1)
    {
        InsertAtHead(data);
        return;
    }
    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp->GetNext(); i++)
    {
        temp = temp->GetNext();
    }
    if (temp == tail)
    {
        InsertAtTail(data);
        return;
    }
    Node *NewNode = new Node(data);
    CheckAllocation(NewNode);
    NewNode->SetNext(temp->GetNext());
    NewNode->SetPrev(temp);
    temp->SetNext(NewNode);
    NewNode->GetNext()->SetPrev(NewNode);
    return;
}

void DLL::DeleteAtHead()
{
    Node *temp = head;
    head = head->GetNext();
    head->SetPrev(nullptr);
    delete temp;
    temp = nullptr;
}

void DLL::DeleteAtTail()
{
    Node *temp = tail;
    tail = tail->GetPrev();
    tail->SetNext(nullptr);
    delete temp;
    temp = nullptr;
}

void DLL::DeleteAtPos(int pos)
{
    if (pos < 1)
    {
        pos = 1;
    }
    if (pos == 1)
    {
        DeleteAtHead();
        return;
    }
    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp->GetNext(); i++)
    {
        temp = temp->GetNext();
    }
    if (temp == tail)
    {
        DeleteAtTail();
        return;
    }
    Node *ToBeDeletedNode = temp->GetNext();
    temp->SetNext(temp->GetNext()->GetNext());
    temp->GetNext()->SetPrev(temp);
    return;
}