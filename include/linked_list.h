#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct linkedList {
	node* head;
	node* rear;
	int size;
};

linkedList* createLinkedList();

bool isListEmpty(linkedList* l);

void insertAtHead(linkedList* l, int value); 

void insertAtEnd(linkedList* l, int value);

void deleteValue(linkedList* l, int value);

void display(linkedList* l);

void deleteLL(linkedList** l);