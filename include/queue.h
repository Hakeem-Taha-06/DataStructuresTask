#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

typedef struct {
	node* head;
	node* tail;
}queue_ll;

typedef struct {
	int* data;
	int size, count;
}queue_a;

queue_ll* createLLQueue();

queue_a* createArrayQueue(int size);

void enqueue(queue_a* q, int value);

void enqueue(queue_ll* q, int value);

int dequeue(queue_a* q);

int dequeue(queue_ll* q);

bool isFull(queue_a* q);

bool isEmpty(queue_a* q);

bool isEmpty(queue_ll* q);

int peek(queue_a* q);

int peek(queue_ll* q);

void display(queue_ll* q);

