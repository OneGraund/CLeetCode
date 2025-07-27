#include <stdlib.h>

int min(const int *p1, const int *p2) {
	if (*p1 < *p2)
		return *p1;
	else
		return *p2;
}

int max(const int *p1, const int *p2) {
	if (*p1 < *p2)
		return *p2;
	else
		return *p1;
}

int *twoSum(int *nums, int numssize, int target, int *returnsize) {

	int *indices = malloc(sizeof(int) * 2);
	for (int i = 0; i < numssize; i++) {
		for (int j = i+1; j < numssize; j++) {
			if ((nums[i] + nums[j] == target) && (i != j)) {
				indices[0] = min(&i, &j);
				indices[1] = max(&i, &j);
			}
		}
	}
	*returnsize = 2;
	return indices;
}

int main(int argc, char *argv[]) {
	int nums[] = {-3, 4, 3, 90};
	// int* returnsize = 0; // this is dumb, because i am literally assigning a
	// null pointer int* returnarray = 0;
	int returnsize;
	int *returnarray;

	returnarray = twoSum(nums, 4, 0, &returnsize);

	return 0;
}
