#include <stdio.h>
#include <stdlib.h>
#include <curses.h>


typedef enum {I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000} RomanNumber;


int romanToInt(char* s) {
	int map[26];
	map['I' - 'A'] = I;
	map['V' - 'A'] = V;
	map['X' - 'A'] = X;
	map['L' - 'A'] = L;
	map['C' - 'A'] = C;
	map['D' - 'A'] = D;
	map['M' - 'A'] = M;
	int retVal = 0;
	
	while (*s != '\0') {
		if ( *(s+1) != '\0') {
			if (map[*(s+1)-'A'] > map[*s-'A'])
				retVal -= map[*s - 'A'];
			else
				retVal += map[*s - 'A'];
		} else {
			retVal += map[*s - 'A'];
		}
		s++;
	}
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
	int testsAmount = 4;

	char* test_string1 = "III";
	char* test_string2 = "LVIII";
	char* test_string3 = "MCMXCIV";
	char* test_string4 = "IV";

	TestCase **testcases = calloc(testsAmount, sizeof(TestCase*));
	for (int i = 0; i < testsAmount; i++) {
		testcases[i] = calloc(1, sizeof(TestCase));
	}
	assignTestCaseValue(testcases[0],test_string1, 3);
	assignTestCaseValue(testcases[1],test_string2, 58);
	assignTestCaseValue(testcases[2],test_string3, 1994);
	assignTestCaseValue(testcases[3],test_string4, 4);

	for (int i = 0; i < testsAmount; i++) {
		if (!test(testcases[i]))
			return -i-1;
	}

	return 0;
}
