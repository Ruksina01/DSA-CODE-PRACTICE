//  Remove Kth Node From End of List | GEEKSFORGEEKS
#include <iostream>
#include <vector>
using namespace std;
//  Remove Every Kth Node From End of List

// create a Node;
class Node
{
public:
    int data;
    Node *next;
    // constructor
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
// Creating Linked List
void InsertAtStart(vector<int> &arr, int n, Node *&Head)
{
    for (int i = 0; i < n; i++)
    {
        if (Head == NULL)
        {
            Head = new Node(arr[i]);
        }
        else
        {
            Node *temp;
            temp = new Node(arr[i]);
            temp->next = Head;
            Head = temp;
        }
    }
}
Node *deleteK(Node *head, int k)
{
    // code here
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *temp = head;
    Node *prev = NULL;
    int count = 1;
    while (temp != NULL)
    {
        if (count == k)
        {
            count = 1;
            prev->next = temp->next;
            delete temp;
            temp = prev->next;
        }
        else
        {
            count++;
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}
// printing
void print(Node *Head)
{
    Node *temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *Head = NULL;
    vector<int> arr = {78,7,6,5, 4, 3, 2, 1};
    int n = arr.size();
    InsertAtStart(arr, n, Head);
    // pritning
    print(Head);

    deleteK(Head, 2);
    // pritning
    print(Head);
    return 0;
}