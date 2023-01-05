#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node *down;
};

Node* head = NULL;

Node* merge(Node* a, Node* b){

	if (a == NULL)
		return b;

	if (b == NULL)
		return a;

	Node* result;

	if (a->data < b->data){
		result = a;
		result->down = merge(a -> down, b);
	}

	else{
		result = b;
		result->down = merge(a, b -> down);
	}
	result->next = NULL;
	return result;
}

Node* flatten(Node* head){
	
	// Base Cases
	if (head == NULL || head->next == NULL)
		return head;

	// Recur for list on right
	head->next = flatten(head->next);

	head = merge(head, head->next);

	return head;
}

Node* push(Node* head_ref, int data){
	
	// Allocate the Node & Put in the data
	Node* new_node = new Node();

	new_node->data = data;
	new_node->next = NULL;

	// Make next of new Node as head
	new_node->down = head_ref;

	// Move the head to point to new Node
	head_ref = new_node;

	return head_ref;
}

void print(){
	Node* temp = head;
	while (temp != NULL){
		cout << temp->data << " ";
		temp = temp->down;
	}
	cout << endl;
}

int main(){
    //copy me ye wala testcase bna hai
    
	head = push(head, 30);
	head = push(head, 8);
	head = push(head, 7);
	head = push(head, 5);

	head->next = push(head->next, 20);
	head->next = push(head->next, 10);

	head->next->next = push(head->next->next, 50);
	head->next->next = push(head->next->next, 22);
	head->next->next = push(head->next->next, 19);

	head->next->next->next = push(head->next->next->next, 45);
	head->next->next->next = push(head->next->next->next, 40);
	head->next->next->next = push(head->next->next->next, 35);
	head->next->next->next = push(head->next->next->next, 20);

	// Flatten the list
	head = flatten(head);

	print();
	return 0;
}