#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"
#include "linked_list.h"

int main(){
	
	queue_a* qa = createArrayQueue(256);
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


	printf("Push any button to exit...");

	getchar();

	return 0;
}
