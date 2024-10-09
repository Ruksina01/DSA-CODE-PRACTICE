// Delete the Middle Node of a Linked List | LeetCode 2095

#include <iostream>
#include <vector>
using namespace std;
// Delete the Middle Node of a Linked List
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// Creating Linked List
void InsertAtStart(vector<int> &arr, int n, ListNode *&Head)
{
    for (int i = 0; i < n; i++)
    {
        if (Head == nullptr)
        {
            Head = new ListNode(arr[i]);
        }
        else
        {
            ListNode *temp;
            temp = new ListNode(arr[i]);
            temp->next = Head;
            Head = temp;
        }
    }
}

ListNode *deleteMiddle(ListNode *head)
{
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    ListNode *first = head;
    ListNode *second = head;
    ListNode *prev = nullptr;

    while (second != nullptr && second->next != nullptr)
    {
        prev = first;
        first = first->next;
        second = second->next->next;
    }
    prev->next = first->next;
    delete first;
    return head;
}

// printing
void print(ListNode *Head)
{
    ListNode *temp = Head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    ListNode *Head = nullptr;
    vector<int> arr = {4,3,2,1};
    int n = arr.size();
    InsertAtStart(arr, n, Head);
    // pritning
    print(Head);

    deleteMiddle(Head);
    // pritning
    print(Head);

    return 0;
}