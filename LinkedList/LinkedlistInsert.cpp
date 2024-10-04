
#include <iostream>
#include <vector>
using namespace std;

//create a Node;
class Node {
public:
	int data;
	Node* next;
	//constructor
	Node(int data) {
		this->data=data;
		next = NULL;
	}
};
//  Inserting at start;
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

//  Inserting at end;
void InsertAtEnd(int arr[], int n, Node*& Head, Node*& Tail) {

	for (int i = 0; i < n ; i++) {
		if(Head==NULL) {
			Head = new Node(arr[i]);
			Tail = Head;
		}
		else {
			Tail->next = new Node(arr[i]);
			Tail = Tail->next;

		}
	}
}

//  Inserting at Any Position;
void InsertAtPosition(Node*& Head, int pos, int value) {
    Node* newNode = new Node(value);
    
    // Case: Inserting at the head (position 0)
    if (pos == 0) {
        newNode->next = Head;
        Head = newNode;       
        return;
    }
    
    Node* temp = Head;

    // Traverse to the node before the desired position
    for (int i = 0; i < pos - 1; i++) {
        if (temp == NULL) { // BASE
            cout << "Position out of bounds!" << endl;
            return; 
        }
        temp = temp->next; 
    }

    newNode->next = temp->next; 
    temp->next = newNode;       
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

	int arr[] = {1,2,3,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	// InsertAtStart(arr, n, Head);
	//pritning
	// print(Head);

	InsertAtEnd(arr, n, Head, Tail);
	// pritning
	// print(Head);
    
    InsertAtPosition(Head, 3, 10);
    InsertAtPosition(Head, 1, 20);
    print(Head);

	return 0;
}