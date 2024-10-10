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

// Insert at start
void insertStart(vector<int> &arr, Node *&Head, Node *&Tail)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (Head == NULL)
        {
            Head = new Node(arr[i]);
            Tail = Head; // Set Tail as well when inserting the first node
        }
        else
        {
            Node *temp = new Node(arr[i]);
            temp->next = Head;
            Head->prev = temp;
            Head = temp;
        }
    }
}

// Delete at start
void deleteStart(Node *&Head, Node *&Tail)
{
    if (Head == NULL) // Empty list
        return;

    if (Head->next == NULL) // Only one node in the list
    {
        delete Head;
        Head = Tail = NULL;
        return;
    }
    Node *temp = Head;
    Head = Head->next;
    Head->prev = NULL; // Set the prev pointer of the new Head to NULL
    delete temp;       // Delete the old Head
}

// Delete at end
void deleteEnd(Node *&Head, Node *&Tail)
{
    if (Head == NULL) // Empty list
        return;

    if (Head->next == NULL) // If there's only one node
    {
        delete Head;
        Head = Tail = NULL;
        return;
    }

    // If there are multiple nodes
    Node *temp = Tail; // Point to the last node
    Tail = Tail->prev; // Move Tail to the second-to-last node
    Tail->next = NULL; // Disconnect the last node
    delete temp;       // Delete the last node
}

// Delete any Position
// Delete any Position
void deletePos(Node *&Head, Node *&Tail, int pos)
{
    if (Head == NULL) // Empty list
        return;

    Node *temp = Head;

    if (pos == 0) // Deleting the head
    {
        deleteStart(Head, Tail); //calling deletestart
        return;
    }

    // Traverse to the node at the given position
    for (int i = 0; i < pos; i++)
    {
        temp = temp->next;
        if (temp == NULL) // out of bounds
            return;
    }

    if (temp->next == NULL) // If we're deleting the last node (tail)
    {
        deleteEnd(Head, Tail); // Call deleteEnd 
    }
    else // Deleting a node in the middle
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
}

// Print the list
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
    vector<int> arr = {5, 4, 3, 2, 1};
    Node *Head = NULL;
    Node *Tail = NULL;

    cout << "Insert at start" << endl;
    insertStart(arr, Head, Tail);
    print(Head);

    cout << "Delete at Tail" << endl;
    // deleteEnd(Head, Tail);
    // print(Head);
    cout << "Delete at Start" << endl;
    // deleteStart(Head, Tail);
    // print(Head);
    cout << "Delete at Position" << endl;
    deletePos(Head, Tail, 0);
    print(Head);

    return 0;
}
