#include "node.h"

node* createNode(int value) {
	node* n = new node(value, NULL);

	if (n == NULL) {
		printf("mem allocation failed");
		exit(-1);
	}

	return n;
}