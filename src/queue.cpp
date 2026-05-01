#include "queue.h"
#include "iostream"

queue_ll* createLLQueue() {
	queue_ll* q = new queue_ll(NULL, NULL);

	if (q == NULL) {
		printf("mem allocation failed");
		exit(-1);
	}

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

void deleteQueue(queue_ll** q) {
	if (*q == NULL) { return; } //make sure we are not dereferencing a null pointer

	node* n = (*q)->head; //start from the first node
	node* temp = n;

	delete *q;
	*q = NULL;

	while (n != NULL) {
		n = n->next;
		delete temp;
		temp = n;
	}
}

// ================== Queue Array ========================

QueueArr::QueueArr() : size(10), _front(-1), rear(-1) { arr = new int[size]; }


QueueArr::QueueArr(int s) : size(s), _front(-1), rear(-1) { arr = new int[size]; }


QueueArr::~QueueArr() { delete[] arr; }


bool QueueArr::isEmpty() { return _front == -1; }


bool QueueArr::isFull() { return (rear + 1) % size == _front; }


int QueueArr::front() {
	if (isEmpty()) {
		std::cout << "The queue is Empty, No front element.\n";
		return NULL;
	}
	return arr[_front];
}


int QueueArr::dequeue() {
	if (isEmpty()) {
		std::cout << "The queue is Empty!, No elements to dequeue.\n";
		return NULL;
	}
	int data = arr[_front];

	if (_front == rear) {
		_front = -1;
		rear = -1;
	}
	else
		_front = (_front + 1) % size;

	return data;
}


void QueueArr::enqueue(int value) {
	if (isFull()) {
		std::cout << "The Queue is Full, can not enqueue.\n";
		return;
	}
	if (_front == -1) _front++;

	rear = (rear + 1) % size;
	arr[rear] = value;
}


void QueueArr::print() {
	std::cout << "Front <--------------- Rear\n";
	std::cout << "   [";
	if (isEmpty()) std::cout << "]\n";
	else{
		for (int i = _front; ; i = (i+1) % size) {
			std::cout << this->arr[i] << ", ";
			if (i == rear) break;
		}
		std::cout << "\b\b]\n";	// \b\b are to adjust the printing format of the last element
	}
}