//  Remove Nth Node From End of List | Leetcode 19
#include <iostream>
#include <vector>
using namespace std;
//  Remove Nth Node From End of List

// create a Node;
class ListNode
{
public:
    int data;
    ListNode *next;
    // constructor
    ListNode(int data)
    {
        this->data = data;
        next = NULL;
    }
};
// Creating Linked List
void InsertAtStart(vector<int> &arr, int n, ListNode *&Head)
{
    for (int i = 0; i < n; i++)
    {
        if (Head == NULL)
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

//  Deleting Nth Node from last position
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    count -= n;
    if (count == 0)
    {
        head = head->next;
        delete temp;
        return head;
    }
    temp = head;
    ListNode *prev = NULL;
    while (count--)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete temp;
    return head;
}

// printing
void print(ListNode *Head)
{
    ListNode *temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    ListNode *Head = NULL;
    vector<int> arr = {5,4,3,2,1};
    int n = arr.size();
    InsertAtStart(arr, n, Head);
    // pritning
    print(Head);

    removeNthFromEnd(Head, 2);
    // pritning
    print(Head);

    return 0;
}