#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char test1[] = "()[]{}";
char test2[] = "([]){}";
char test3[] = "((()))[[[]]]";
char test4[] = "";
char test5[] = "(])[";
char test6[] = "(((";
char test7[] = "()(";
char test8[] = "]]]";

typedef struct Node Node;

typedef struct Node {
	Node* prev;
	Node* next;
	char val;
} Node;

typedef struct {
	Node* start;
	Node* end;
} LinkedList;

LinkedList* ll_create() {
	LinkedList* ll = malloc(sizeof(LinkedList));
	ll->start = NULL;
	ll->end = NULL;
	return ll;
}

void ll_add(LinkedList* ll, char* sp) {
	if (ll->start == NULL && ll->end == NULL) {
		Node* root ;
		root = malloc(sizeof(Node));
		root->prev = NULL;
		root->next = NULL;
		root->val = *sp;
		ll->start = root;
		ll->end = root;
		return;
	}

	Node* pre = ll->end;
	Node* next = malloc(sizeof(Node));
	next->val = *sp;
	next->next = NULL;
	next->prev = pre;
	pre->next = next;
	ll->end = next;
}

void print_ll(LinkedList* ll) {
	Node* p = ll->start;
	do {
		printf("-> %c ", p->val);
		p = p->next;
	} while (p != NULL);
	printf("\n");
}

bool ll_isEmpty(LinkedList* ll) {
	return ll->start == NULL && ll->end == NULL;
}

bool ll_rmlast(LinkedList* ll) {
	if (ll_isEmpty(ll)) return false;

	Node* del = ll->end;
	// check if this is the last node
	if (del->prev != NULL) {
		ll->end = del->prev;
		ll->end->next = NULL;
	} else { // deleting last elem
		ll->end = NULL;
		ll->start = NULL;
	}
	free(del);
	return true;
}

bool ll_isLast(LinkedList* ll, char s) {
	if (ll_isEmpty(ll)) return false;
	return ll->end->val == s;
}

bool isValid(char* s) {
	LinkedList* ll = ll_create();
	while (*s != '\0') {
		switch (*s) {
			case ')':
				if (!ll_isLast(ll, '('))
					return false;
				else
					if (!ll_rmlast(ll))
						return false;
				break;
			case ']':
				if (!ll_isLast(ll, '['))
					return false;
				else
					if (!ll_rmlast(ll))
						return false;
				break;
			case '}':
				if (!ll_isLast(ll, '{'))
					return false;
				else
					if (!ll_rmlast(ll))
						return false;
				break;
			default:
				// open bracket
				ll_add(ll, s);
				break;
		}
		s++;
	}

	return ll_isEmpty(ll);
}


int main(int argc, char* argv[]) {
	printf("Testcase test1: %s\n", test1);
	assert(isValid(test1));
	printf("Testcase test2: %s\n", test2);
	assert(isValid(test2));
	printf("Testcase test3: %s\n", test3);
	assert(isValid(test3));
	printf("Testcase test4: %s\n", test4);
	assert(isValid(test4));
	printf("Testcase test5: %s\n", test5);
	assert(!isValid(test5));
	printf("Testcase test6: %s\n", test6);
	assert(!isValid(test6));
	printf("Testcase test7: %s\n", test7);
	assert(!isValid(test7));
	printf("Testcase test8: %s\n", test8);
	assert(!isValid(test8));
	return 0;
}
