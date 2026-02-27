#include <stdio.h>
#include <stdlib.h>


 struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* ret = malloc(sizeof(struct ListNode));
	struct ListNode* root = ret;

	while (list1 != NULL || list2 != NULL) {
		if (list1 == NULL) {
			root->val = list2->val;
			list2 = list2->next;
		} else if (list2 == NULL) {
			root->val = list1->val;
			list1 = list1->next;
		} else {
			if (list1->val <= list2->val) {
				root->val = list1->val;
				list1 = list1->next;
			} else {
				root->val = list2->val;
				list2 = list2->next;
			}
		}

		root->next = malloc(sizeof(struct ListNode));
		root = root->next;
	}

	return ret;
}

void sll_print(struct ListNode* sll) {
	do {
		printf("-> %d ", sll->val);
		sll = sll->next;
	} while (sll != NULL);
	printf("\n");
}

struct ListNode* sll_create(int* vals, int size) {
	struct ListNode* root = malloc(sizeof(struct ListNode));
	struct ListNode* p = root;
	for (int i=0; i<size-1;i++) {
		p->val = vals[i];
		p->next = malloc(sizeof(struct ListNode));
		p = p->next;
	} 
	p->val = vals[size-1];
	p->next = NULL;
	return root;
}


int main(int argc, char* argv[]) {
	/* Input: list1 = [1,2,4], list2 = [1,3,4] */
	/* Output: [1,1,2,3,4,4] */
	int a1[] = {1,2,4};
	struct ListNode* list1 = sll_create(a1, 3);
	sll_print(list1);

	int a2[] = {1,3,4};
	struct ListNode* list2 = sll_create(a2, 3);
	sll_print(list2);

	sll_print(mergeTwoLists(list1, list2));

	return 0;
}
