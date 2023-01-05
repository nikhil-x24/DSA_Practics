#include <iostream>
using namespace std;

class Node{
    public:
	int data;
	Node* link;
};

Node* top = 0;

void push(int data){
	
	Node* temp = new Node();

	if (!temp){
		cout << "\nStack Overflow";
		exit(1);
	}

	temp->data = data;

	temp->link = top;

	top = temp;
}

int isEmpty(){
	return top == NULL;
}

int peek(){
	
	if (!isEmpty())
		return top->data;
	else
		exit(1);
}

void pop(){
	Node* temp;

	if (top == NULL){
		cout << "\nStack Underflow" << endl;
		exit(1);
	}
	else{
		
		// Assign top to temp
		temp = top;

		// Assign second node to top
		top = top->link;

		// Release memory of top node
		//i.e delete the node
		free(temp);
	}
}

void display(){
	Node* temp;

	// Check for stack underflow
	if (top == NULL){
		cout << "\nStack Underflow";
		exit(1);
	}
	else{
		temp = top;
		while (temp != NULL){

			// Print node data
			cout << temp->data << "-> ";

			// Assign temp link to temp
			temp = temp->link;
		}
	}
}

int main(){
	
	push(11);
	push(22);
	push(33);
	push(44);

	// Display stack elements
	display();

	// Print top element of stack
	cout << "\nTop element is "
		<< peek() << endl;

	// Delete top elements of stack
	pop();
	pop();

	// Display stack elements
	display();

	// Print top element of stack
	cout << "\nTop element is "
		<< peek() << endl;
		
	return 0;
}
