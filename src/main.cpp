#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "queue.h"
#include "stack.h"
#include "linked_list.h"

using namespace std;
int main(){
	//Queue Linked List -------------------------------------------------------
	queue_ll* qll = createLLQueue();

	cout << "Before enqueue: ";
	display(qll);

	for (int i = 1; i <= 10; ++i) enqueue(qll, 10 * i);
	cout << "After enqueue: ";
	display(qll); //should be {100, 90, 80, 70, 60, 50, 40, 30, 20, 10}
	cout << "Size: " << size(qll) << '\n';
	cout << "dequeued " << dequeue(qll) << endl;
	cout << "After 1 dequeue: ";
	display(qll); //should be {90, 80, 70, 60, 50, 40, 30, 20, 10}
	cout << "Size: " << size(qll) << '\n';
	clear(qll);
	cout << "After clear: " << '\n';
	cout << "Size: " << size(qll) << '\n';

	cout << "Attempting dequeue with queue empty: ";
	dequeue(qll); //should say that queue is empty

	deleteQueue(&qll); //should delete queue and set qll to NULL
	cout << "After Delete: ";
	cout << "Size: " << size(qll) << '\n';
	cout << "Attmepting display after deleting queue: ";
	display(qll); //should say that queue is NULL

	cout << "-------------------------------------------------------------------" << '\n';
	cout << '\n';
	cout << "-------------------------------------------------------------------" << '\n';

	//Queue Array--------------------------------------------------------------
	QueueArr qa;

	// Initially empty
	cout << "Initial queue: ";
	qa.print();
	cout << "Capacity: " << qa.capacity() << '\n';
	cout << "Available space: " << qa.available() << '\n';
	cout << "length: " << qa.length() << "\n===============\n\n";

	// Enqueue elements
	for (int i = 1; i <= qa.capacity(); i++)
		qa.enqueue(i);

	cout << "After enqueue (1 then 2 ...... then 10): ";
	qa.print();
	cout << "Capacity: " << qa.capacity() << '\n';
	cout << "Available space: " << qa.available() << '\n';
	cout << "length: " << qa.length() << "\n===============\n\n";

	// Front element
	cout << "Front: " << qa.front() << "\nthe queue after front() : ";
	qa.print();
	cout << "Available space: " << qa.available() << '\n';

	// Dequeue
	cout << "Dequeued: " << qa.dequeue() << '\n';

	cout << "After dequeue: ";
	qa.print();
	cout << "Capacity: " << qa.capacity() << '\n';
	cout << "Available space: " << qa.available() << '\n';
	cout << "length: " << qa.length() << "\n\n===============\n";

	// dequeue two elemnets
	qa.dequeue();
	qa.dequeue();

	cout << "After two dequeue: ";
	qa.print();
	cout << "Capacity: " << qa.capacity() << '\n';
	cout << "Available space: " << qa.available() << '\n';
	cout << "length: " << qa.length() << "\n\n===============\n";

	// clearing the queue
	qa.clear();
	cout << "clear() is called\n";
	cout << "the queue after clear(): ";
	qa.print();

	// Try dequeue on empty
	cout << "Dequeue on empty: " << qa.dequeue() << '\n';
	qa.print();
	cout << "Available space: " << qa.available() << '\n';
	cout << "Capacity: " << qa.capacity() << '\n';
	cout << "length: " << qa.length() << "\n\n===============\n";
	

	// making a queue of given size
	cout << " --------------- testing a queue of given size --------------\n";
	QueueArr qa2(3);

	// Initially empty
	cout << "Initial queue: ";
	qa2.print();
	cout << "Capacity: " << qa2.capacity() << '\n';
	cout << "Available space: " << qa2.available() << '\n';
	cout << "length: " << qa2.length() << "\n===============\n\n";

	// enqueing
	qa2.enqueue(10); qa2.enqueue(20); qa2.enqueue(30); qa2.enqueue(40);
	cout << "queue after enqueing (10, 20, 30, 40): ";
	qa2.print();
	cout << "Available space: " << qa2.available() << '\n';
	cout << "Capacity: " << qa2.capacity() << '\n';
	cout << "length: " << qa2.length() << "\n===============\n\n";

	// queue of one element
	qa2.clear();
	cout << "clear() is called: the queue is empty\n";
	qa2.enqueue(10);
	cout << "queue after enqueing (10): ";
	qa2.print();
	cout << "Available space: " << qa2.available() << '\n';
	cout << "Capacity: " << qa2.capacity() << '\n';
	cout << "length: " << qa2.length() << "\n===============\n\n";
	
	//qa2 = qa;						// give error and exit the app as the two queues sizes are different
	//qa2.print();

	cout << "-------------------------------------------------------------------" << '\n';
	cout << '\n';
	cout << "-------------------------------------------------------------------" << '\n';


	//Stack Linkedlist Test------------------------------------------------------------
	stack_ll* sll = createLLStack();

	// Initially empty
	cout << "Initial stack: ";
	display(sll);

	// Push elements
	push(sll, 10);
	push(sll, 20);
	push(sll, 30);

	cout << "After pushes: ";
	display(sll);   // Expected: 30 20 10

	// Peek top
	cout << "Top element: " << peek(sll) << endl; // Expected: 30

	// Pop element
	cout << "Popped: " << pop(sll) << endl; // Expected: 30

	cout << "After pop: ";
	display(sll);   // Expected: 20 10

	// Pop all
	pop(sll);
	pop(sll);

	cout << "After removing all: ";
	display(sll);   // Expected: Invalid

	// Try pop on empty
	cout << "Pop on empty: " << pop(sll) << endl;

	deleteStack(&sll);

	cout << "-------------------------------------------------------------------" << '\n';
	cout << '\n';
	cout << "-------------------------------------------------------------------" << '\n';

	//Stack Array Test------------------------------------------------------------
	cout << "=== Test 1: Create & display empty stack ===" << endl;
	stack_a* sa = createArrayStack(5);
	display(sa);                              // Expected: []
	cout << "isEmpty: " << (isEmpty(sa) ? "true" : "false") << endl; // Expected: true

	cout << "\n=== Test 2: Push elements ===" << endl;
	push(sa, 10);
	push(sa, 20);
	push(sa, 30);
	display(sa);                              // Expected: [ 30 20 10 ]
	cout << "isEmpty: " << (isEmpty(sa) ? "true" : "false") << endl; // Expected: false

	cout << "\n=== Test 3: Peek top ===" << endl;
	cout << "Top: " << peek(sa) << endl;      // Expected: 30

	cout << "\n=== Test 4: Pop elements ===" << endl;
	cout << "Popped: " << pop(sa) << endl;    // Expected: 30
	cout << "Popped: " << pop(sa) << endl;    // Expected: 20
	display(sa);                              // Expected: [ 10 ]

	cout << "\n=== Test 5: Fill to capacity ===" << endl;
	push(sa, 40);
	push(sa, 50);
	push(sa, 60);
	push(sa, 70);
	display(sa);                              // Expected: [ 70 60 50 40 10 ]
	push(sa, 80);                             // Expected: overflow message (stack is full)

	cout << "\n=== Test 6: Pop until empty ===" << endl;
	while (!isEmpty(sa)) cout << "Popped: " << pop(sa) << endl;
	display(sa);                              // Expected: []

	cout << "\n=== Test 7: Underflow - pop & peek on empty ===" << endl;
	pop(sa);                                  // Expected: underflow message
	peek(sa);                                 // Expected: empty message

	cout << "\n=== Test 8: Invalid creation (size <= 0) ===" << endl;
	stack_a* bad = createArrayStack(-1);     // Expected: error message, returns NULL
	(void)bad;

	cout << "\n=== Test 9: Delete stack ===" << endl;            
	display(sa);                              // Expected: "Stack is NULL"
	deleteStack(&sa);


	return 0;
}
