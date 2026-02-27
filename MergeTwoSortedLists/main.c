#include "MergeTwoSortedLists.c"

int a1[] = {1, 2, 4}; int a2[] = {1, 3, 4}; int a11 = 3; int a22 = 3;

int a_res[] = {1, 1, 2, 3, 4, 4}; int a_res_size = 6;

int *b1 = NULL;        int *b2 = NULL;         int b11 = 0; int b22 = 0;

int *b_res = NULL;     int b_res_size = 0;

int *c1 = NULL;        int c2[] = {0};       int c11 = 0; int c22 = 1;

int c_res[] = {0};    int c_res_size = 1;


struct ListNode* sll_create(int* vals, int size) {
	if (size == 0) {
		return NULL;
	}
	struct ListNode* ret_root = malloc(sizeof(struct ListNode));
	struct ListNode* ret = ret_root;
	for (int i=0;i<size-1;i++) {
		ret->val = vals[i];
		ret->next = malloc(sizeof(struct ListNode));
		ret = ret->next;
	}
	ret->val = vals[size-1];
	ret->next = NULL;
	return ret_root;
}

bool sll_comp(struct ListNode* list1, struct ListNode* list2) {
	if (!list1 && !list2) return true;
	else if ((!list1 && list2) || (list1 && !list2)) return false;

	while (list1 ->next != NULL && list2->next != NULL) {
		if (list1->val != list2->val) {
			return false;
		} else {
			list1 = list1->next;
			list2 = list2->next;
		}
	}
	return list1->val == list2->val;
}

int main() {
	struct ListNode* list1 = sll_create(a1, a11);
	struct ListNode* list2 = sll_create(a2, a22);
	assert(sll_comp(sll_create(a_res, a_res_size), mergeTwoLists(list1, list2)));
	printf("Test1 passed\n");

	list1 = sll_create(b1, b11);
	list2 = sll_create(b2, b22);
	assert(sll_comp(sll_create(b_res, b_res_size), mergeTwoLists(list1, list2)));
	printf("Test2 passed\n");

	list1 = sll_create(c1, c11);
	list2 = sll_create(c2, c22);
	assert(sll_comp(sll_create(c_res, c_res_size), mergeTwoLists(list1, list2)));
	printf("Test3 passed\n");
	

	return 0;
}
