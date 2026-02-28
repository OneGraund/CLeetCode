#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

int removeDuplicates(int* nums, int numsSize);
#include "RemoveDuplicatesFromSortedArray.c"

typedef struct {
	char* name;
	int nums[16];
	int numsSize;
	int expectedNums[16];
	int expectedNumsSize;
} testcase_t;

void test(testcase_t test) {
	printf("Executing: %s\n", test.name);
	int k = removeDuplicates(test.nums, test.numsSize); // Calls your implementation

	assert(k == test.expectedNumsSize);
	for (int i = 0; i < k; i++) {
		printf("test.nums[i]: %d ?= test.expectedNums[i]: %d\n", test.nums[i], test.expectedNums[i]);
		assert(test.nums[i] == test.expectedNums[i]);
	}
	printf("%s SUCCESS\n\n************************************************************\n", test.name);
}

int main() {

	testcase_t test1 = {
		"Test1",
		{1, 1, 2}, 3,
		{1, 2},    2
	};
	test(test1);

	testcase_t test2 = {
		"Test2",
		{0,0,1,1,1,2,2,3,3,4}, 10,
		{0,1,2,3,4},           5
	};
	test(test2);

	return 0;
}
