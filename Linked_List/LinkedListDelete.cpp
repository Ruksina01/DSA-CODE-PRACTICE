#include <iostream>
#include <vector>
using namespace std;

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
//  Deleting the start or Head
Node *DeletetStart(Node *Head)
{
    if (Head == NULL)
        return Head;
    Node *temp = Head;
    Head = Head->next;
    // free(temp);
    delete temp;
    return Head;
}

//  Deleting the end or tail
Node *DeleteAtEnd(Node *Head)
{
    if (Head == NULL || Head->next == NULL)
    {
        return Head;
    }

    Node *temp = Head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;

    return Head;
}
//  Deleting from any Position
Node *DeleteAtPos(Node *Head, int k)
{
    if (Head == NULL || Head->next == NULL)
    {
        return Head;
    }
    // pos is first
    if (k == 1)
    {
        Node *temp = Head;
        Head = Head->next;
        delete temp->next;
        temp->next = NULL;
    }
    Node *prev = NULL;
    int count = 0;
    Node *temp = Head;
    while (temp != NULL)
    {
        count++;
        if (count == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return Head;
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
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int n = arr.size();
    InsertAtStart(arr, n, Head);
    // pritning
    print(Head);

    Head = DeletetStart(Head);
    // pritning
    print(Head);

    Head = DeleteAtEnd(Head);
    // pritning
    print(Head);

    Head = DeleteAtPos(Head, 3);
    // pritning
    print(Head);

    return 0;
}