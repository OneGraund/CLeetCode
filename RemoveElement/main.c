#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int removeElement(int* nums, int numsSize, int val);

#include "RemoveElement.c"

typedef struct {
	char* name;
	int nums[16];
	int numsSize;
	int val;
	int expectedNums[16];
	int expectedNumsSize;
} testcase_t;

void test(testcase_t testcase) {
	printf("Performing %s\n", testcase.name);
	int res = removeElement(testcase.nums, testcase.numsSize, testcase.val);
	assert( testcase.expectedNumsSize == res );
	for (int i = 0; i < res; i++) {
		assert (testcase.expectedNums[i] == testcase.nums[i]);
	}
	printf("%s SUCCESS\n", testcase.name);
}

int main() {

	testcase_t test1 = { "Test1", {3,2,2,3}, 4, 3, {2,2}, 2};
	test(test1);
	testcase_t test2 = { "Test2", {0,1,2,2,3,0,4,2}, 8, 2, {0,1,3,0,4}, 5};
	test(test2);

	return 0;
}
