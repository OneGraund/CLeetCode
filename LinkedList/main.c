#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
	int value;
	struct Node* next;
} Node;

void printLinkedList(Node* list) {
	Node* p = list;

	while (p != NULL) {
		printf("%d", p->value);

		if (p->next != NULL) {
			printf(" -> ");
			p = p->next;
		} 
		else {
			break;
		}
	} 
	printf("\n");
}

void freeLinkedList(Node* head) {
	Node* tmp;
	while (head != NULL) {
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int main(void) {
	Node* head = malloc(sizeof(Node));
	head->value = 30;
	head->next = malloc(sizeof(Node));
	head->next->value = 20;
	head->next->next = NULL;
	printLinkedList(head);
	freeLinkedList(head);
	return 0;
}
