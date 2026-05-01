#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "node.h"

typedef struct {
	node* head;
	node* tail;
}queue_ll;

queue_ll* createLLQueue();

void enqueue(queue_ll* q, int value);

int dequeue(queue_ll* q);

bool isEmpty(queue_ll* q);

int peek(queue_ll* q);

void display(queue_ll* q);

void deleteQueue(queue_ll** q);

// =================== Queue Array part ==================
class QueueArr {
private:
	const int size;
	int *arr;
	int _front, rear;
public:
	QueueArr();
	QueueArr(int size);

	~QueueArr();

	bool isEmpty();
	bool isFull();

	void enqueue(int value);
	int dequeue();

	void print();
	int front();

};