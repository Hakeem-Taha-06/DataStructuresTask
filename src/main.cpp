#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "queue.h"
#include "stack.h"
#include "linked_list.h"

using namespace std;
int main(){
	//Queue Linked List -------------------------------------------------------
	/*
	queue_ll* qll = createLLQueue();

	cout << "Before enqueue: ";
	display(qll);

	for (int i = 1; i <= 10; ++i) enqueue(qll, 10 * i);
	cout << "After enqueue: ";
	display(qll); //should be {100, 90, 80, 70, 60, 50, 40, 30, 20, 10}

	cout << "dequeued " << dequeue(qll) << endl;
	cout << "after 1 dequeue: ";
	display(qll); //should be {90, 80, 70, 60, 50, 40, 30, 20, 10}

	enqueue(qll, 100);
	for (int i = 1; i <= 10; ++i) { 
		cout << "dequeued " << dequeue(qll) << endl;
	}

	cout << "Attempting dequeue with queue empty: ";
	dequeue(qll); //should say that queue is empty

	deleteQueue(&qll); //should delete queue and set qll to NULL

	cout << "Attmepting display after deleting queue: ";
	display(qll); //should say that queue is NULL
	*/

	//Queue Array--------------------------------------------------------------
	/*
	QueueArr q;

	// Initially empty
	cout << "Initial queue: ";
	q.print();
	cout << "Capacity: " << q.capacity() << '\n';
	cout << "Available space: " << q.available() << '\n';
	cout << "length: " << q.length() << "\n===============\n\n";

	// Enqueue elements
	for (int i = 1; i <= q.capacity(); i++)
		q.enqueue(i);

	cout << "After enqueue (1 then 2 ...... then 10): ";
	q.print();
	cout << "Capacity: " << q.capacity() << '\n';
	cout << "Available space: " << q.available() << '\n';
	cout << "length: " << q.length() << "\n===============\n\n";

	// Front element
	cout << "Front: " << q.front() << "\nthe queue after front() : ";
	q.print();
	cout << "Available space: " << q.available() << '\n';

	// Dequeue
	cout << "Dequeued: " << q.dequeue() << '\n';

	cout << "After dequeue: ";
	q.print();
	cout << "Capacity: " << q.capacity() << '\n';
	cout << "Available space: " << q.available() << '\n';
	cout << "length: " << q.length() << "\n\n===============\n";

	// dequeue two elemnets
	q.dequeue();
	q.dequeue();

	cout << "After two dequeue: ";
	q.print();
	cout << "Capacity: " << q.capacity() << '\n';
	cout << "Available space: " << q.available() << '\n';
	cout << "length: " << q.length() << "\n\n===============\n";

	// clearing the queue
	q.clear();

	// Try dequeue on empty
	cout << "Dequeue on empty: " << q.dequeue() << '\n';
	q.print();
	cout << "Available space: " << q.available() << '\n';
	cout << "Capacity: " << q.capacity() << '\n';
	cout << "length: " << q.length() << "\n\n===============\n";
	

	// making a queue of given size
	cout << " --------------- testing a queue of given size --------------\n";
	QueueArr q2(3);

	// Initially empty
	cout << "Initial queue: ";
	q2.print();
	cout << "Capacity: " << q2.capacity() << '\n';
	cout << "Available space: " << q2.available() << '\n';
	cout << "length: " << q2.length() << "\n===============\n\n";

	// enqueing
	q2.enqueue(10); q2.enqueue(20); q2.enqueue(30); q2.enqueue(40);
	cout << "queue after enqueing (10, 20, 30, 40): ";
	q2.print();
	cout << "Available space: " << q2.available() << '\n';
	cout << "Capacity: " << q2.capacity() << '\n';
	cout << "length: " << q2.length() << "\n===============\n\n";
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

	//Stack Array Test------------------------------------------------------------
	//cout << "=== Test 1: Create & display empty stack ===" << endl;
	//stack_a* s = createArrayStack(5);
	//display(s);                              // Expected: []
	//cout << "isEmpty: " << (isEmpty(s) ? "true" : "false") << endl; // Expected: true

	//cout << "\n=== Test 2: Push elements ===" << endl;
	//push(s, 10);
	//push(s, 20);
	//push(s, 30);
	//display(s);                              // Expected: [ 30 20 10 ]
	//cout << "isEmpty: " << (isEmpty(s) ? "true" : "false") << endl; // Expected: false

	//cout << "\n=== Test 3: Peek top ===" << endl;
	//cout << "Top: " << peek(s) << endl;      // Expected: 30

	//cout << "\n=== Test 4: Pop elements ===" << endl;
	//cout << "Popped: " << pop(s) << endl;    // Expected: 30
	//cout << "Popped: " << pop(s) << endl;    // Expected: 20
	//display(s);                              // Expected: [ 10 ]

	//cout << "\n=== Test 5: Fill to capacity ===" << endl;
	//push(s, 40);
	//push(s, 50);
	//push(s, 60);
	//push(s, 70);
	//display(s);                              // Expected: [ 70 60 50 40 10 ]
	//push(s, 80);                             // Expected: overflow message (stack is full)

	//cout << "\n=== Test 6: Pop until empty ===" << endl;
	//while (!isEmpty(s)) cout << "Popped: " << pop(s) << endl;
	//display(s);                              // Expected: []

	//cout << "\n=== Test 7: Underflow - pop & peek on empty ===" << endl;
	//pop(s);                                  // Expected: underflow message
	//peek(s);                                 // Expected: empty message

	//cout << "\n=== Test 8: Invalid creation (size <= 0) ===" << endl;
	//stack_a* bad = createArrayStack(-1);     // Expected: error message, returns NULL
	//(void)bad;

	//cout << "\n=== Test 9: Delete stack ===" << endl;            
	//display(s);                              // Expected: "Stack is NULL"


	return 0;
}
