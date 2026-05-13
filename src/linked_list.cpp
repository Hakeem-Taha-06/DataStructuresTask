#include "linked_list.h"

linkedList* createLinkedList() {
	linkedList* l = new linkedList(NULL, NULL, 0); //allocate mem for linked list, and initialize values

	if (l == NULL) { //if allocation fails, exit
		printf("mem allocation failed");
		exit(-1);
	}
	
	return l;
}

bool isEmpty(linkedList* l) {
	if (l == NULL) { printf("list is NULL\n"); return false; }//make sure we don't dereference a null ptr
	return l->head == NULL; //if head is null then the list is empty
}

void insertAtHead(linkedList* l, int value) {
	if (l == NULL) { printf("list is NULL\n"); return; }//make sure we don't dereference a null ptr

	node* n= createNode(value);

	if (isEmpty(l)) { //special case: empty list, the rear will also point at the inserted node
		l->rear = n;
	}

	//general case: the new node points at whatever the head was pointing at
	n->next = l->head;

	//then, the head points at the new node
	l->head = n;

	l->size += 1;
}

void insertAtEnd(linkedList* l, int value) {
	if (l == NULL) { printf("list is NULL\n"); return; }//make sure we don't dereference a null ptr

	node* n = createNode(value);

	//in case list is empty, the head will also point at the new node
	if (isEmpty(l)) {
		l->head = n;
	}//if it's not empty then we can dereference l->rear and make it point at the new inserted node
	else {
		l->rear->next = n;
	}


	//in both cases, the rear will point at the new inserted node in the end
	l->rear = n;
	l->size += 1;
}

void deletebyIndex(linkedList* l, int index) {
	if (l == NULL) { printf("list is NULL\n"); return; }//make sure we don't dereference a null ptr

	//create two pointers to track two nodes at the same time
	node* curr = l->head; //the node to be deleted
	node* prev = NULL; //the node that needs to point at the next of curr after deleting


	//loop until we reach the index to delete
	for (int i = 0; curr != NULL; ++i) {
		if (i  == index) {
			if (prev == NULL) { //if it's the first node
				l->head = curr->next; //the head will point at whatever the curr node was pointing at
			}
			else {//if it's in the middle
				prev->next = curr->next; //then prev != NULL, and we can dereference it and set its next to whatever curr was pointing at
			}

			if (curr == l->rear) { //if it's the last node
				l->rear = prev; //the we can make the rear point at the prev node
			}

			printf("deleted element at index %i of value %i\n", i, curr->data);
			delete curr; //in all cases we delete the curr node
			curr = NULL;
			return;
		}

		prev = curr; //prev moves one step forward
		curr = curr->next; //curr moves one step forward, now prev is directly behind it
	}


	printf("couldn't find element at index %i\n", index);
	
}

//second fix: deleteValue should take a value instead of an index, i was aware this was the intended behaviour, but i couldn't decide whether i should delete
//            only the first element that is found from the beginning of the list containing that value, or delete all elements that contain that value one by one
//            until the end of the list, this is why i chose the less ambiguous option by deleting by index

//i will implement the first option because it is easier
void deleteValue(linkedList* l, int value) {
	if (l == NULL) { printf("list is NULL");return; }
	
	node* prev = NULL;
	node* curr = l->head;
	
	while (curr != NULL) {
		if (curr->data == value) {
			if (prev == NULL) { //if it's the first node
				l->head = curr->next; //the head will point at whatever the curr node was pointing at
			}
			else {//if it's in the middle
				prev->next = curr->next; //then prev != NULL, and we can dereference it and set its next to whatever curr was pointing at
			}

			if (curr == l->rear) { //if it's the last node
				l->rear = prev; //the we can make the rear point at the prev node
			}

			printf("deleted of value %i\n", curr->data);
			delete curr; //in all cases we delete the curr node
			curr = NULL;
			return;
		}
		prev = curr; //prev moves one step forward
		curr = curr->next; //curr moves one step forward, now prev is directly behind it
	}
}

void display(linkedList* l) {
	if (l == NULL) { printf("list is NULL\n"); return; }//make sure we don't dereference a null ptr

	printf("{");
	for (node* n = l->head; n != NULL;n = n->next)
	{
		if (n->next != NULL) printf("%i, ", n->data); //if we are not at the last element, we can print a ", " 
		else printf("%i", n->data); //at the end, no ", " is needed
	}
	printf("}\n");
	
}

//we pass a copy of the pointer's address (reference) so we can set it to NULL
void deleteLL(linkedList** l) {
	if (l == NULL) { printf("l is NULL\n"); return; }//make sure we don't dereference a null ptr

	node* n = (*l)->head; //start from the first node
	node* temp = n;

	delete *l; //we delete the pointer itself 
	*l = NULL; //and set its value to NULL

	//loop until the end
	while (n != NULL) {
		n = n->next; //move n
		delete temp; //delete the node before it
		temp = n;    //update temp to sync with n
	}
}