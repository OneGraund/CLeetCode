/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

#define LN_EMPTY 101

void ln_popstart(struct ListNode **list) {
    if ((*list)->next) {
        *list = (*list)->next;
    } else {
        (*list)->val = LN_EMPTY;
    }
}

bool ln_isEmpty(struct ListNode* list) {
    return list->val == LN_EMPTY;
}

int helper(struct ListNode** ret, struct ListNode **smaller, struct ListNode **bigger) {
    if (!ln_isEmpty(*smaller)) {
        (*ret)->val = (*smaller)->val;
        ln_popstart(&(*smaller));
		if (!(ln_isEmpty(*smaller) && ln_isEmpty(*bigger))) {
			(*ret)->next = malloc(sizeof(struct ListNode));
			(*ret) = (*ret)->next;
			(*ret)->next = NULL;
			(*ret)->val  = -101;
		} else {
			return 0;
		}
        return 1;
    }
    return 0;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	if (!list1) {
		if (!list2) {
			return NULL;
		} else {
			return list2;
		}
	} else if (!list2) {
		return list1;
	}
    struct ListNode* root_ret = malloc(sizeof(struct  ListNode));
    struct ListNode* ret = root_ret;

    int status = 1;
    while (status) {
        if (list1->val <= list2->val) {
            status = helper(&ret, &list1, &list2);
        } else {
            status = helper(&ret, &list2, &list1);
        }
    }
    return root_ret;
}

