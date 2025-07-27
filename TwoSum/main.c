#include <stdio.h>
#include <stdlib.h>

// sort in a decsending order based on first element
int cmpint_desc(const void *p1, const void *p2) {
	return (**(int **)p2) - (**(int **)p1);
}
int cmpint_asc(const void *p1, const void *p2) {
	return (*(int *)p1) - (*(int *)p2);
}

void printarray(int *array, int arraysize) {
	printf("[");

	for (int i = 0; i < arraysize - 1; i++) {
		printf("%d, ", array[i]);
	}
	printf("%d]\n", array[arraysize - 1]);
}
void print2darray(int **array, int arraysize) {
	printf("[ ");
	for (int i = 0; i < arraysize - 1; i++) {
		printf("[%d, %d], ", array[i][0], array[i][1]);
	}
	printf("[%d, %d] ]\n", array[arraysize - 1][0], array[arraysize - 1][1]);
}

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
	// allocate a 2d array
	int **sorted_nums = malloc(numssize * sizeof(int *));
	for (int i = 0; i < numssize; i++) {
		sorted_nums[i] = malloc(sizeof(int) * 2);
		sorted_nums[i][0] = nums[i];
		sorted_nums[i][1] = i;
	}

	print2darray(sorted_nums, numssize);
	qsort(sorted_nums, numssize, sizeof(int *), cmpint_desc);
	print2darray(sorted_nums, numssize);
	int *indices = malloc(sizeof(int) * 2);
	for (int i = 0; i < numssize; i++) {
		for (int j = i+1; j < numssize; j++) {
			if ((sorted_nums[i][0] + sorted_nums[j][0] == target) && (i != j)) {
				int *i_idx = &sorted_nums[i][1];
				int *j_idx = &sorted_nums[j][1];
				indices[0] = min(i_idx, j_idx);
				indices[1] = max(i_idx, j_idx);
			}
		}
	}
	// free memory and sort the indices array
	for (int i = 0; i < numssize; i++) {
		free(sorted_nums[i]);
	}
	free(sorted_nums);

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
	printf("->result: ");
	printarray(returnarray, returnsize);

	return 0;
}
