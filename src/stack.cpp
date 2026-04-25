#include "stack.h"
#include <iostream>
using namespace std;

stack_ll* createLLStack() {
	stack_ll* s = new stack_ll();
	int data;
	s->head = NULL;
	return s;
}
bool isEmpty(stack_ll* s) {
	return(s->head == NULL);
}
void push(stack_ll* s, int value) {
	node* newNode = createNode(value);
	newNode->next = s->head;
	s->head = newNode;
}
int pop(stack_ll* s) {
	if (isEmpty(s)) {
		cout << "Invalid" << endl;
		return 0;
	}
	else {
		node* temp = s->head;
		int value = temp->data;
		s->head = s->head->next;
		temp->next = NULL;
		delete temp;
		return value;
	}
}
int peek(stack_ll* s) {
	if (isEmpty(s)) {
		cout << "Invalid" << endl;
		return 0;
	}
	else {
		return(s->head->data);
	}
}
void display(stack_ll* s) {
	if (isEmpty(s)) {
		cout << "Invalid" << endl;
	}
	else {
		node* temp = s->head;        
		while (temp != NULL) {      
			cout << temp->data << " ";
			temp = temp->next;     
		}
		cout << endl;
	}
}

