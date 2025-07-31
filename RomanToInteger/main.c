#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

/*
 Symbol       Value		Rank
I             1			0
V             5			1
X             10		2
L             50		3
C             100		4
D             500		5
M             1000		6
 */

typedef enum {I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000} RomanNumber;

typedef struct {
	RomanNumber numberType;	
	int amount;
} compressedRoman;

typedef struct Node {
	compressedRoman value;	
	struct Node* next;
} Node;

void freeLinkedList(Node* head) {
	Node* tmp;
	while (head != NULL) {
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void printcr(compressedRoman val) {
	printf("%d:%d", val.numberType, val.amount);
}
void printLinkedList(Node* list) {
	Node* p = list;
	while (p != NULL) {
		printcr(p->value);
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

int romanToInt(char* s) {
	char* s_p = s;
	int retVal = 0;

	// init head, default assignment
	Node* head = malloc(sizeof(Node));
	head->value.amount = 0;
	head->value.numberType = 0;
	head->next = NULL;

	Node* curNode = head;
	RomanNumber lastRoman = -1;
	RomanNumber currentRoman = -1;

	while (*s_p != '\0') {
		switch (*s_p) {
			case 'I': currentRoman = I; break;
			case 'V': currentRoman = V; break;
			case 'X': currentRoman = X; break;
			case 'L': currentRoman = L; break;
			case 'C': currentRoman = C; break;
			case 'D': currentRoman = D; break;
			case 'M': currentRoman = M; break;
			default: freeLinkedList(head); return -1;
		}
		if (currentRoman == lastRoman || lastRoman == -1) {
			curNode->value.numberType = currentRoman;
			curNode->value.amount++;
		} else {
			curNode->next = malloc(sizeof(Node));
			curNode->next->value.numberType = currentRoman;
			curNode->next->value.amount = 1;
			curNode->next->next = NULL;
			curNode = curNode->next;
		}
		lastRoman = currentRoman;
		s_p++;
	}

	curNode = head;
	while (curNode != NULL) {
		// we don't want to add exactly amount of roman characters, in case
		//	the next character has lower "rank"
		if (curNode->next != NULL) {
			if (curNode->next->value.numberType > curNode->value.numberType) {
				retVal -= curNode->value.amount * curNode->value.numberType;
			} else {
				retVal += curNode->value.amount * curNode->value.numberType;
			}
		} else {
			retVal += curNode->value.amount * curNode->value.numberType;
		}
		curNode = curNode->next;
	}

	printLinkedList(head);
	freeLinkedList(head);
	return retVal;
}





typedef struct {
	char* test_string;
	int result_int;
} TestCase;

void assignTestCaseValue(TestCase *testcase, char* test_string, int result_int) {
	testcase->test_string = test_string;
	testcase->result_int = result_int;
}

bool test(TestCase *testcase) {
	printf("Testing (%s, %d)\n", testcase->test_string, testcase->result_int);
	int testRes = romanToInt(testcase->test_string);
	if (testcase->result_int != testRes) {
		printf("[ERROR] Expected %d, but got %d\n", testcase->result_int, testRes);
		return false;
	} else {
		printf("Test passed!\n");
		return true;
	}
}

int main(int argc, char* argv[]) {
	int testsAmount = 5;

	char* test_string1 = "III";
	char* test_string2 = "LVIII";
	char* test_string3 = "MCMXCIV";
	char* test_string4 = "IV";
	char* test_string5 = "IIV";

	TestCase **testcases = calloc(testsAmount, sizeof(TestCase*));
	for (int i = 0; i < testsAmount; i++) {
		testcases[i] = calloc(1, sizeof(TestCase));
	}
	assignTestCaseValue(testcases[0],test_string1, 3);
	assignTestCaseValue(testcases[1],test_string2, 58);
	assignTestCaseValue(testcases[2],test_string3, 1994);
	assignTestCaseValue(testcases[3],test_string4, 4);
	assignTestCaseValue(testcases[4],test_string5, 3);

	for (int i = 0; i < testsAmount; i++) {
		if (!test(testcases[i]))
			return -i-1;
	}

	return 0;
}
