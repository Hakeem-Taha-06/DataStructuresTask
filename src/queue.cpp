#include "queue.h"

queue_ll* createLLQueue() {
	queue_ll* q = new queue_ll(NULL, NULL); //allocate new queue_ll, initialize its values

	if (q == NULL) { //if allocation fails, exit
		printf("mem allocation failed");
		exit(-1);
	}

	return q;
}

int peek(queue_ll* q) {
	if (q == NULL) { printf("queue is NULL\n"); return -1; }//make sure we don't dereference a null ptr
	return q->head->data; //return the first node's data
}

bool isEmpty(queue_ll* q) {
	if (q == NULL) { printf("queue is NULL\n"); return true; }//make sure we don't dereference a null ptr
	return q->head == NULL; //if head is null then queue is empty
}

void enqueue(queue_ll* q, int value) {
	if (q == NULL) { printf("queue is NULL\n"); return; }//make sure we don't dereference a null ptr

	node* n = createNode(value);

	if (isEmpty(q)) { //special case: empty queue, both tail and head point at the same node
		q->head = n;
		q->tail = n;
		return;
	}

	//general case: the next of the new node points at whatever the head was pointing at (could be NULL or next node)

	n->next = q->head;
	q->head = n; //head points at new node
}

int dequeue(queue_ll* q) {
	if (q == NULL) { printf("queue is NULL\n"); return -1; }//make sure we don't dereference a null ptr

	if (isEmpty(q)) {
		printf("queue is empty\n");
		return -1;
	}

	int value = q->head->data; //store the values of the node to be deleted in temporary variables
	node* temp = q->head->next;

	delete q->head; //delete the first node
	q->head = temp; //make the head point at the next node

	return value;
}

void display(queue_ll* q) {
	if (q == NULL) { printf("queue is NULL\n"); return; }//make sure we don't dereference a null ptr
	
	printf("{");
	for (node* n = q->head; n != NULL; n = n->next) {
		if (n->next != NULL) { printf("%i, ", n->data); } //if we are not at the last element, we can print a ", " 
		else { printf("%i", n->data); } //at the end, no ", " is needed
	}
	printf("}\n");
}

//we pass a copy of the pointer's address (reference) so we can set it to NULL
void deleteQueue(queue_ll** q) {
	if (q == NULL) { printf("queue is NULL\n"); return; }//make sure we don't dereference a null ptr

	node* n = (*q)->head; //start from the first node
	node* temp = n;

	delete *q; //we delete the pointer itself 
	*q = NULL; //and set its value to NULL

	//loop until the end
	while (n != NULL) {
		n = n->next; //move n
		delete temp; //delete the node before it
		temp = n;    //update temp to sync with n
	}

	std::cout << "queue deleted" << std::endl;
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