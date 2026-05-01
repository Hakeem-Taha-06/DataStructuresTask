#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "node.h"

typedef struct {
	node* head;
}stack_ll;

typedef struct {
	int* data;
	int size, count;
}stack_a;

stack_ll* createLLStack();

stack_a* createArrayStack(int size);

void push(stack_a* s, int value);

void push(stack_ll* s, int value);

int pop(stack_a* s);

int pop(stack_ll* s);

bool isEmpty(stack_a* s);

bool isEmpty(stack_ll* s);

int peek(stack_a* s);

int peek(stack_ll* s);

void display(stack_ll* s);

void display(stack_a* s);