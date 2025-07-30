#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

bool isPalindrome(int x) {
	if (x < 0) return false;
	else if (x==0) return true;

	int intSize = 0;
	int* intAsArr = calloc(10, sizeof(int));
	int remainder = 0;
	while (x > 0) {
		remainder = x % 10;
		intAsArr[intSize] = remainder;
		intSize++;
		x /= 10;
	}
	printf("[");
	for (int i = 0; i < intSize-1; i++)
		printf("%d, ", intAsArr[i]);
	printf("%d]\n", intAsArr[intSize-1]);

	for (int i = 0; i < intSize; i++) {
		if (intAsArr[i] != intAsArr[intSize-i-1]) {
			printf("[%d] != [%d]\n", i, intSize-i);
			return false;
		}
	}
	return true;
}

typedef struct {
	int test_value;
	bool test_result;
} TestCase;

void assignTestCaseValue(TestCase *testcase, int test_value, bool test_result) {
	testcase->test_value = test_value;
	testcase->test_result = test_result;
}

bool test(TestCase *testcase) {
	printf("Testing (%d, %d)\n", testcase->test_value, testcase->test_result);
	bool testRes = isPalindrome(testcase->test_value);
	if (testcase->test_result != testRes) {
		printf("[ERROR] Expected %d, but got %d\n", testcase->test_result, testRes);
		return false;
	} else {
		printf("Test passed!\n");
		return true;
	}
}

int main(int argc, char* argv[]) {
	int testsAmount = 4;

	TestCase **testcases = calloc(testsAmount, sizeof(TestCase*));
	for (int i = 0; i < testsAmount; i++) {
		testcases[i] = calloc(1, sizeof(TestCase));
	}
	assignTestCaseValue(testcases[0], 121, true);
	assignTestCaseValue(testcases[1], -121, false);
	assignTestCaseValue(testcases[2], 10, false);
	assignTestCaseValue(testcases[3], 1234567899, false);

	for (int i = 0; i < testsAmount; i++) {
		if (!test(testcases[i]))
			return -i-1;
	}

	return 0;
}
