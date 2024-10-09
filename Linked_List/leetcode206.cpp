//  Reverse Linked List | Leetcode 206

#include <iostream>
#include <vector>
using namespace std;
//  Reverse Linked List

//create a Node;
class ListNode {
public:
	int data;
	ListNode* next;
	//constructor
	ListNode(int data) {
		this->data=data;
		next = NULL;
	}
};
//  Inserting at start;
void InsertAtStart(vector<int>& arr, int n, ListNode*& Head) {

	for (int i = 0; i < n ; i++) {
		if(Head==NULL) {
			Head = new ListNode(arr[i]);
		}
		else {
			ListNode* temp;
			temp = new ListNode(arr[i]);
			temp->next = Head;
			Head = temp;

		}
	}
}
// CODE PART FOR REVERSE LINKED LIST
ListNode* reverseList(ListNode* Head) {
        ListNode* current = Head, *prev = NULL, *temp = NULL;
        while(current!=NULL){
            temp = current->next;
            current->next=prev;
            prev=current;
            current=temp;
        }
        Head = prev;
        return Head;
    }

//printing
void print(ListNode* Head) {
	ListNode* temp = Head;
	while(temp!=NULL) {
		cout << temp->data << " ";
		temp=temp->next;
	}
    cout << endl;
}

int main()
{
	ListNode* Head = NULL;

	vector<int> arr = {1,2,3,4,5};
	int n = arr.size();
    cout << "ORIGINAL LINKED LIST" << endl;
	InsertAtStart(arr, n, Head);
	//pritning
	print(Head);
    cout << "REVERSED LINKED LIST" << endl;
    Head = reverseList(Head);
    //pritning
    print(Head);

	return 0;
}