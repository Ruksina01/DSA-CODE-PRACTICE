//  Palindrome Linked List | LeetCode 234
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
void insertAtStart(vector<int> &arr, int n, ListNode *&head)
{
    for (int i = 0; i < n; i++)
    {
        if (head == nullptr)
        {
            head = new ListNode(arr[i]);
        }
        else
        {
            ListNode *temp;
            temp = new ListNode(arr[i]);
            temp->next = head;
            head = temp;
        }
    }
}
//  Palindrome Linked List
bool isPalindrome(ListNode *head)
{
    if (head->next==NULL)
        return 1;
    int count = 0;
    ListNode *temp = head;
    //counting nodes in LL
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    count /= 2;
    ListNode* current=head;
    ListNode *prev = NULL;
    //Finding mid point to break
    while (count--)
    {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    ListNode *future = NULL;
    prev = NULL;
    //reversing the second half
    while (current)
    {
        future = current->next;
        current->next = prev;
        prev = current;
        current = future;
    }
    ListNode *first = head;
    ListNode *second = prev;
    // checking the both partitions values are Equal or not
    while (first)
    {
        if (first->val != second->val) // if not return 0;
            return 0;
        first = first->next;// otherwise Move next
        second = second->next;
    }
    return 1;
}

// printing
void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    ListNode *head = nullptr;
    vector<int> arr = {1, 2, 3, 2, 1};
    int n = arr.size();
    insertAtStart(arr, n, head);
    // pritning
    print(head);
    cout << "Is Palindrome: " << (isPalindrome(head) ? "Yes" : "No") << endl;

    return 0;
}