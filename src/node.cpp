#include "node.h"

node* createNode(int value) {
	node* n = (node*)malloc(sizeof(node));

	if (n == NULL) {
		printf("mem allocation failed");
		exit(-1);
	}

	n->data = value;
	n->next = NULL;

	return n;
}