#include "stack.h"
using namespace std;

// Create empty stack
stack_ll* createLLStack() {
	stack_ll* s = new stack_ll();
	int data;
	s->head = NULL;
	return s;
}

// Check if stack is empty
bool isEmpty(stack_ll* s) {
	return(s->head == NULL);
}

// Push element to top
void push(stack_ll* s, int value) {
	node* newNode = createNode(value);
	newNode->next = s->head;
	s->head = newNode;
}

// Remove and return top element
int pop(stack_ll* s) {
	if (isEmpty(s)) {
		cout << "Invalid" << endl;
		return 0;
	}
	else {
		node* temp = s->head;
		int value = temp->data;
		s->head = s->head->next;
		delete temp;
		return value;
	}
}

// Return top element without removing
int peek(stack_ll* s) {
	if (isEmpty(s)) {
		cout << "Invalid" << endl;
		return 0;
	}
	else {
		return(s->head->data);
	}
}

// Print stack elements (top to bottom)
void display(stack_ll* s) {
	if (isEmpty(s)) {
		cout << "[]" << endl;
	}
	else {
		node* temp = s->head;
		cout << "[ ";
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << "]" <<endl;
	}
}