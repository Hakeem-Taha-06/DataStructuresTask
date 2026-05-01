#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "queue.h"
#include "stack.h"
#include "linked_list.h"
using namespace std;
int main(){
	/*
	queue_ll* qll = createLLQueue();

	for(int i = 1; i <= 10; ++i) enqueue(qll, 10*i);
	
	display(qll);
	dequeue(qll);
	dequeue(qll);
	display(qll);

	for (int i = 1; i <= 5; ++i) insertAtHead(ll, i);
	display(ll);
	for (int i = 10; i >= 6; --i) insertAtEnd(ll, i);
	display(ll);

	
	stack_ll* sll = createLLStack();
	cout << isEmpty(sll) << endl;
	push(sll, 27);
	push(sll, 28);
	push(sll, 29);
	push(sll, 30);
	display(sll);
	pop(sll);
	pop(sll);
	display(sll);
	cout << peek(sll) << endl;
	cout << isEmpty(sll) << endl;
	*/

	//Queue Linked List -------------------------------------------------------
	queue_ll* qll = createLLQueue();

	for (int i = 1; i <= 10; ++i) enqueue(qll, 10 * i);
	display(qll); //should be {100, 90, 80, 70, 60, 50, 40, 30, 20, 10}

	cout << "dequeued " << dequeue(qll) << endl;
	display(qll); //should be {90, 80, 70, 60, 50, 40, 30, 20, 10}

	enqueue(qll, 100);
	for (int i = 1; i <= 10; ++i) { 
		cout << "dequeued " << dequeue(qll) << endl;
	}

	dequeue(qll); //should say that queue is empty

	deleteQueue(&qll); //should delete queue and set qll to NULL
	display(qll); //should say that queue is NULL
	
	//Queue Array--------------------------------------------------------------
	/*
	QueueArr q;

	// Initially empty
	cout << "Initial queue: ";
	q.print();

	// Enqueue elements
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);

	cout << "After enqueue: ";
	q.print();   // Expected: 10 20 30

	// Front element
	cout << "Front: " << q.front() << endl; // Expected: 10

	// Dequeue
	cout << "Dequeued: " << q.dequeue() << endl; // Expected: 10

	cout << "After dequeue: ";
	q.print();   // Expected: 20 30

	// Remove all
	q.dequeue();
	q.dequeue();

	cout << "After removing all: ";
	q.print();   // Expected: empty / error

	// Try dequeue on empty
	cout << "Dequeue on empty: " << q.dequeue() << endl;
	*/
	


	//Stack Linkedlist Test------------------------------------------------------------
	/*
	stack_ll* s = createLLStack();

	// Initially empty
	cout << "Initial stack: ";
	display(s);

	// Push elements
	push(s, 10);
	push(s, 20);
	push(s, 30);

	cout << "After pushes: ";
	display(s);   // Expected: 30 20 10

	// Peek top
	cout << "Top element: " << peek(s) << endl; // Expected: 30

	// Pop element
	cout << "Popped: " << pop(s) << endl; // Expected: 30

	cout << "After pop: ";
	display(s);   // Expected: 20 10

	// Pop all
	pop(s);
	pop(s);

	cout << "After removing all: ";
	display(s);   // Expected: Invalid

	// Try pop on empty
	cout << "Pop on empty: " << pop(s) << endl;
	*/

	return 0;
}
