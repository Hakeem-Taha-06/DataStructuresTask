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

	//stack_a* sa = createArrayStack(256);
	//stack_ll* sll = createLLStack();

	linkedList* ll = createLinkedList();

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
	
	//================== Queue array test ==============
	QueueArr q_arr;
	cout << "============= Queue Array ================\n";
	q_arr.print();
	cout << q_arr.front() << "\n";

	for (int i = 0; i < 12; i++)
		q_arr.enqueue(i);

	q_arr.print();

	q_arr.dequeue();
	q_arr.dequeue();
	q_arr.dequeue();
	q_arr.dequeue();

	q_arr.print();


			// AI-generated tests for circular queue array
	
	// 1. Test Parameterized Constructor (Size 5)
	std::cout << "\n\n\n[TEST 1] Creating Queue of size 5...\n";
	QueueArr myQueue(5);
	myQueue.print();
	std::cout << "\n";

	// 2. Test Enqueue and Wrap-Around readiness
	std::cout << "[TEST 2] Enqueuing 5 items (Filling the queue)...\n";
	for (int i = 10; i <= 50; i += 10) {
		myQueue.enqueue(i);
	}
	myQueue.print();
	std::cout << "\n";

	// 3. Test isFull restriction
	std::cout << "[TEST 3] Attempting to overfill (Should show error)...\n";
	myQueue.enqueue(60);
	std::cout << "\n";

	// 4. Test Dequeue (Making room for wrap-around)
	std::cout << "[TEST 4] Dequeuing 2 items...\n";
	std::cout << "Removed: " << myQueue.dequeue() << "\n";
	std::cout << "Removed: " << myQueue.dequeue() << "\n";
	myQueue.print();
	std::cout << "\n";

	// 5. Test Circular Wrap-Around
	std::cout << "[TEST 5] Enqueuing 2 new items to force wrap-around...\n";
	myQueue.enqueue(99);
	myQueue.enqueue(88);
	myQueue.print(); // Visually, the print function should handle this seamlessly
	std::cout << "\n";

	// 6. Test Emptying the Queue completely
	std::cout << "[TEST 6] Emptying the queue completely...\n";
	while (!myQueue.isEmpty()) {
		std::cout << "Removed: " << myQueue.dequeue() << "\n";
	}
	myQueue.print();
	std::cout << "\n";

	// 7. Test Recovery (Can we use it again after it was emptied?)
	std::cout << "[TEST 7] Adding one item to empty queue...\n";
	myQueue.enqueue(777);
	myQueue.print();


	printf("Push any button to exit...");

	getchar();
	return 0;
}
