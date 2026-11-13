#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    stack<ListNode *> s;
    ListNode *curr = head;
    while (curr)
    {
        s.push(curr);
        if (curr->next)
            curr = curr->next;
        else
            break;
    }
    int i = 1;
    if (n = 1)
    {
        delete curr;
        curr = nullptr;
    }
    else
    {
        while (i < n)
        {
            curr = s.top();
            s.pop();
            i++;
        }
        if (s.empty())
        {
            ListNode *temp = head;
            head = head->next;
            temp = nullptr;
        }
        else
        {
            ListNode *temp = s.top();
            temp->next = temp->next->next;
            delete curr;
            curr = nullptr;
        }
    }
    return head;
}

int main()
{
    ListNode* head;
    head->val = 1;
    ListNode* temp;
    temp->val=2;
    head->next = temp;
    temp->next = new ListNode(3);
    temp = temp->next;
    temp->next = new ListNode(4);
    temp = temp->next;
    temp->next = new ListNode(5);
    temp = temp->next;
    head=  removeNthFromEnd(head,4);
    
}
