#include "linked_list.h"

linkedList* createLinkedList() {
	linkedList* l = new linkedList(NULL, NULL, 0);

	if (l == NULL) {
		printf("mem allocation failed");
		exit(-1);
	}
	
	return l;
}

bool isListEmpty(linkedList* l) {
	if (l == NULL) { printf("list is NULL"); return false; }
	return l->head == NULL;
}

void insertAtHead(linkedList* l, int value) {
	if (l == NULL) { printf("list is NULL"); return; }

	node* n= createNode(value);

	if (isListEmpty(l)) {
		l->rear = n;
	}

	n->next = l->head;
	l->head = n;

	l->size += 1;
}

void insertAtEnd(linkedList* l, int value) {
	if (l == NULL) { printf("list is NULL"); return; }

	node* n = createNode(value);

	if (isListEmpty(l)) {
		l->head = n;
	}
	else {
		l->rear->next = n;
	}

	l->rear = n;
	l->size += 1;
}

void deleteValue(linkedList* l, int index) {
	if (l == NULL) { printf("list is NULL"); return; }
	
	//hacky implementation: using multiple declarations in a for loop via an anonymous struct
	/*for (struct { node* curr; node* prev; int i; } cell = { l->head, NULL, 0 }; 
		 cell.curr != NULL && cell.i < l->size; 
		 cell.prev = cell.curr ,cell.curr = cell.curr->next, cell.i += 1) {
		if (cell.i == index) {
			if (cell.prev == NULL) {
				l->head = cell.curr->next;
			}
			else {
				cell.prev->next = cell.curr->next;
			}

			if (cell.curr == l->rear) {
				l->rear = cell.prev;
			}

			printf("deleted element at index %i of value %i\n", cell.i, cell.curr->data);
			free(cell.curr);
			return;
		}
	}*/

	//regular implementation
	node* curr = l->head;
	node* prev = NULL;
	for (int i = 0; curr != NULL; ++i) {
		if (i  == index) {
			if (prev == NULL) {
				l->head = curr->next;
			}
			else {
				prev->next = curr->next;
			}

			if (curr == l->rear) {
				l->rear = prev;
			}

			printf("deleted element at index %i of value %i\n", i, curr->data);
			delete curr;
			return;
		}

		prev = curr;
		curr = curr->next;
	}


	printf("couldn't find element at index %i\n", index);
	
}

void display(linkedList* l) {
	printf("{");
	for (node* n = l->head; n != NULL;n = n->next)
	{
		if (n->next != NULL) printf("%i, ", n->data); 
		else printf("%i", n->data);
	}
	printf("}\n");
	
}