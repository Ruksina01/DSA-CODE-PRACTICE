//  Middle of the Linked List | Leetcode 876

#include <iostream>
#include <vector>
using namespace std;
//  Middle of the Linked List

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
// CODE PART FOR Middle Node of LINKED LIST
ListNode *middleNode(ListNode *head)
{
    ListNode *first = head;
    ListNode *second = head;
    while (second != NULL && second->next != NULL)
    {
        first = first->next;
        second = second->next->next;
    }
    return first;
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
	vector<int> arr = {1,2,3,4,5,6};
	int n = arr.size();
    cout << "ORIGINAL LINKED LIST " << endl;
	InsertAtStart(arr, n, Head);
	//pritning
	print(Head);
    cout << "Middle Node" << endl;
    ListNode* temp = middleNode(Head);
    //pritning
    cout << temp->data;

	return 0;
}