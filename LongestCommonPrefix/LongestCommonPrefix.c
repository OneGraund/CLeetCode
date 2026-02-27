#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) { 
	// corner cases
	if (strsSize == 1) 
		return strs[0];

	char res = '\0';
	bool test = 1;
	int i = -1;
	while (test) {
		i++;
		res = strs[0][i];
		for (int j = 1; j < strsSize; j++) {
			if (res == '\0' || strs[j][i] == '\0') {
				test = false;
				break;
			} else {
				if (res != strs[j][i])  {
					test = false;
					break;
				}
			}
		}
	}
	printf("i = %d\n", i);
	char* retStr;
	retStr = malloc(sizeof(char) * (i+2));
	strncpy(retStr, strs[0], i);
	retStr[i] = '\0';
	return retStr;
}

int main(int argc, char* argv[]) {
	char* strs1[3];
	strs1[0] = "c";
	strs1[1] = "acc";
	strs1[2] = "ccc";
	printf("\nAns: %s\n", longestCommonPrefix(strs1, 3));
	return 0;
}
