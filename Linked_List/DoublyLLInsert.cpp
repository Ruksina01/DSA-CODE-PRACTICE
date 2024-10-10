//  Inserting Nodes in Doubly LL
#include <iostream>
#include <vector>
using namespace std;
// DOUBLY LINKED LIST Structure
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
//  insertStart
void insertStart(vector<int> &arr, Node *&Head)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (Head == NULL)
        {
            Head = new Node(arr[i]);
        }
        else
        {
            Node *temp = Head;
            temp = new Node(arr[i]);
            temp->next = Head;
            Head->prev = temp;
            Head = temp;
        }
    }
}
//  insertEnd
void insertEnd(vector<int> &arr, Node *&Head, Node *&Tail)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (Head == NULL)
        {
            Head = new Node(arr[i]);
            Tail = Head;
        }
        else
        {
            Node *temp = new Node(arr[i]);
            Tail->next = temp;
            temp->prev = Tail;
            Tail = temp;
        }
    }
}
//  insertanyPosition
void insertPos(Node *&Head, Node *&Tail, int pos, int value)
{
    if (pos < 0)
        return;
    if (pos == 0 || Head == NULL)
    {
        Node *newNode = new Node(value);
        newNode->next = Head;
        if (Head != NULL)
            Head->prev = newNode;
        Head = newNode;
        if (Tail == NULL)
            Tail = Head; // If the list was empty
        return;
    }
    Node *temp = Head;
    while (--pos)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        Node *newNode = new Node(value);
        Tail->next = newNode;
        newNode->prev = Tail;
        Tail = newNode;
    }
    Node *newNode = new Node(value);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    if (newNode->next == NULL) // If inserted at the end
        Tail = newNode;
}
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
    // Write C++ code here
    vector<int> arr = {5, 4, 3, 2, 1};
    Node *Head = NULL;
    Node *Tail = NULL;
    cout << "Insert AT start" << endl;
    insertStart(arr, Head);
    print(Head);
    // cout << "Insert AT end" << endl;
    // insertEnd(arr, Head, Tail);
    // print(Head);
    cout << "Insert AT ANy Position" << endl;
    insertPos(Head, Tail, 2, 99);
    print(Head);

    return 0;
}