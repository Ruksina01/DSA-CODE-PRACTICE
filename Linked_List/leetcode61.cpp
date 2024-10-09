//  Rotate the Linked List | LeetCode 61
#include <iostream>
#include <vector>
using namespace std;
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void insertAtStart(vector<int> &arr, int n, ListNode* &Head)
{
    for (int i = 0; i < n; i++)
    {
        if (Head == nullptr)
        {
            Head = new ListNode(arr[i]);
        }
        else
        {
            ListNode* temp;
            temp = new ListNode(arr[i]);
            temp->next = Head;
            Head = temp;
        }
    }
}
//  Rotate the Linked List
ListNode* rotateRight(ListNode* Head, int k)
{
    if (Head == NULL)
        return NULL;
    if (Head->next == NULL)
        return Head;
    int count = 0;
    ListNode* temp = Head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    k = k % count;
    if (k == 0)
        return Head;
    count = count - k;
    ListNode* prev = NULL;
    temp = Head;
    while (count--)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    ListNode* tail = temp;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = Head;
    Head = temp;
    return Head;
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
    vector<int> arr = {5,4, 3, 2, 1};
    int n = arr.size();
    insertAtStart(arr, n, Head);
    // pritning
    print(Head);
    cout << "Roated List" << endl;
    ListNode* roated = rotateRight(Head, 2);
    // pritning
    print(roated);

    return 0;
}