#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#include "FindTheIndexOfTheFirstOccurreenceInAString.c"

typedef struct {
	char* name;
	char* haystack;
	char* needle;
	int expected;
} testcase_t;

void test(testcase_t testcase) {
	printf("Performing %s\n", testcase.name);
	int res = strStr(testcase.haystack, testcase.needle);
	assert( testcase.expected == res );
	printf("%s SUCCESS\n", testcase.name);
}

int main() {

	testcase_t test1 = { "Test1", "mississippi", "issip", 4};
	test(test1);

	return 0;
}
