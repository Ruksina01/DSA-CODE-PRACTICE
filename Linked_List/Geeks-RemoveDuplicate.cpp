//  Remove Duplicates from a Sorted Linked List | GEEKSFORGEEKS

#include <iostream>
#include <vector>
using namespace std;
// Singly LINKED LIST Structure
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *removeDuplicates(Node *head)
{
    if (!head)
        return head;
    Node *prev = head;
    Node *current = head->next;
    while (current)
    {
        if (prev->data == current->data)
        {
            prev->next = current->next;
            delete current;
            current = prev->next;
        }
        else
        {
            prev = prev->next;
            current = current->next;
        }
    }
    return head;
}
void InsertAtStart(int arr[], int n, Node*& Head) {

	for (int i = 0; i < n ; i++) {
		if(Head==NULL) {
			Head = new Node(arr[i]);
		}
		else {
			Node* temp;
			temp = new Node(arr[i]);
			temp->next = Head;
			Head = temp;

		}
	}
}

//printing
void print(Node* Head) {
	Node* temp = Head;
	while(temp!=NULL) {
		cout << temp->data << " ";
		temp=temp->next;
	}
}
int main()
{
	Node* Head = NULL;
	Node* Tail = NULL;

	int arr[] = {1,2,2,3,4,4,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	InsertAtStart(arr, n, Head);
	//pritning
	print(Head);
    cout << endl;
    removeDuplicates(Head);
    print(Head);

    return 0;
}