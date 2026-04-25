#include "queue.h"

queue_ll* createLLQueue() {
	queue_ll* q = new queue_ll(NULL, NULL);

	if (q == NULL) {
		printf("mem allocation failed");
		exit(-1);
	}
	q->head = NULL;
	q->tail = NULL;

	return q;
}

queue_a* createArrayQueue(int size) {
	queue_a* q = new queue_a(NULL, size, 0);

	if (q == NULL) {
		printf("mem allocation failed");
		exit(-1);
	}

	q->data = new int[size]; // == new int[size];

	return q;
}

int peek(queue_ll* q) {
	return q->head->data;
}

bool isEmpty(queue_ll* q) {
	return q->head == NULL;
}

void enqueue(queue_ll* q, int value) {
	if (q == NULL) { printf("queue is NULL"); return; }

	node* n = createNode(value);

	if (isEmpty(q)) {
		q->head = n;
		q->tail = n;
		return;
	}

	n->next = q->head;
	q->head = n;
}

int dequeue(queue_ll* q) {
	if (q == NULL) { printf("queue is NULL"); return -1; }

	if (isEmpty(q)) {
		printf("queue is empty");
		return -1;
	}

	int value = q->head->data;
	node* temp = q->head->next;

	delete q->head;
	q->head = temp;

	return value;
}

void display(queue_ll* q) {
	printf("{");
	for (node* n = q->head; n != NULL; n = n->next) {
		if (n->next != NULL) { printf("%i, ", n->data); }
		else { printf("%i", n->data); }
	}
	printf("}\n");
}