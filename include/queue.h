#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "node.h"

typedef struct queue_ll; //implementation in header files acts as encapsulation, any other file can't access the data inside the struct

queue_ll* createLLQueue();

void enqueue(queue_ll* q, int value);

int dequeue(queue_ll* q);

bool isEmpty(queue_ll* q);

int peek(queue_ll* q);

int size(queue_ll* q);

void clear(queue_ll* q);

void display(queue_ll* q);

void deleteQueue(queue_ll** q);

// =================== Queue Array part ==================
class QueueArr {
private:
	const int size;			// The size of the array, either user-passed parameter or default is 10
	int* arr;				// initialized here as a pointer as the size will be determined in the constructor
	int _front, rear;
public:
	// constructors
	QueueArr();
	QueueArr(int size);
	~QueueArr();

	// deep copying logic
	QueueArr(const QueueArr& other);
	QueueArr& operator=(const QueueArr& other);

	// check helpers
	bool isEmpty() const;
	bool isFull() const;

	// main queue functions
	void enqueue(int value);
	int dequeue();				// Dequeue: front() + pop()
	void clear();
	int length() const;			// Returns the current length of the queue
	int capacity() const;			// Returns the total size of the queue
	int available() const;		// Returns the number of available spaces in the queue

	// Displays the whole queue
	void print() const;

	//retrieve without changing the queue
	int front() const;

};