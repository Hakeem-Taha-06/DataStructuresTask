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

// Stack Array 

// Create an empty stack
stack_a* createArrayStack(int size) {
	if (size <= 0) {
		cout << "Size must be positive" << endl;
		return NULL;
	}
	stack_a* s = new stack_a();
	s->data = new int[size];
	s->size = size;
	s->count = 0;
	return s;
}

// Returns true if the stack has no elements
bool isEmpty(stack_a* s) {
	if (s == NULL) { cout << "Stack is NULL" << endl; return true; }
	return s->count == 0;
}

// Returns true if the stack has reached its max size
bool isFull(stack_a* s) {
	if (s == NULL) { cout << "Stack is NULL" << endl; return false; }
	return s->count == s->size;
}

// Push a value onto the top of the stack
void push(stack_a* s, int value) {
	if (s == NULL) { cout << "Stack is NULL" << endl; return; }
	if (isFull(s)) { cout << "Stack overflow: stack is full" << endl; return; }
	s->data[s->count] = value;   // write at the next free slot
	s->count++;
}

// Remove and return the top element
int pop(stack_a* s) {
	if (s == NULL) { cout << "Stack is NULL" << endl; return -1; }
	if (isEmpty(s)) { cout << "Stack underflow: stack is empty" << endl; return -1; }
	s->count--;
	return s->data[s->count];    // slot is now logically free
}

// Return the top element without removing it
int peek(stack_a* s) {
	if (s == NULL) { cout << "Stack is NULL" << endl; return -1; }
	if (isEmpty(s)) { cout << "Stack is empty, no top element" << endl; return -1; }
	return s->data[s->count - 1];
}

// Print all elements from top to bottom
void display(stack_a* s) {
	if (s == NULL) { cout << "Stack is NULL" << endl; return; }
	if (isEmpty(s)) { cout << "[]" << endl; return; }
	cout << "[ ";
	for (int i = s->count - 1; i >= 0; --i) {
		cout << s->data[i] << " ";
	}
	cout << "]" << endl;
}