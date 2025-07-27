#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// sort in a decsending order based on first element
int cmpint_desc(const void *p1, const void *p2) {
	return (**(int**)p2) - (**(int**)p1); // int* means that it's a pointer to an int and another *(int*)
}
int cmpint_asc(const void *p1, const void *p2) {
	return (*(int*)p1) - (*(int*)p2); // int* means that it's a pointer to an int and another *(int*)
}

void printArray(int* array, int arraySize) {
	printf("[");
	for (int i = 0; i < arraySize-1; i++) {
		printf("%d, ", array[i]);
	} printf("%d]\n", array[arraySize-1]);
}
void print2DArray(int** array, int arraySize) {
	printf("[ ");
	for (int i = 0; i < arraySize-1; i++) {
		printf("[%d, %d], ", array[i][0], array[i][1]);
	} printf("[%d, %d] ]\n", array[arraySize-1][0], array[arraySize-1][1]);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	*returnSize = 0;

	// allocate a 2D array
	int** sorted_nums = malloc(numsSize * sizeof(int*)); 
	for (int i = 0; i < numsSize; i ++) {
		sorted_nums[i] = malloc(sizeof(int) * 2);
		sorted_nums[i][0] = nums[i];
		sorted_nums[i][1] = i;
	}
	// memcpy(sorted_nums, nums, numsSize*sizeof(int));

	print2DArray(sorted_nums, numsSize);
	qsort(sorted_nums, numsSize, sizeof(int*), cmpint_desc);
	print2DArray(sorted_nums, numsSize);

	int best_res = 0;
	// I think that in the end effect I can just pass the amount of elements in the array
	//  and don't care about the rest [1, 2, 3, ...] the ... part we don't care about 
	//  because returnSize is 3 (for example)
	// int indices[numsSize]; 
	
	// Apparently it does make a big diff. We need to dynamically allocate it on the heap, 
	// because like that it is saved on the stack and may be erased, which is bad
	// [2, 5, 3, 10, 20]
	// [0, 1, 2,  3,  4]
	// ->[20, 10, 5, 3, 2]
	// ->[4,   3, 1, 2, 0]
	int* indices = malloc(sizeof(int) * numsSize);
	for (int i=0; i<numsSize; i++) {
		printf("currently checking %d (index %d)\n", sorted_nums[i][0], sorted_nums[i][1]);
		if (sorted_nums[i][0] <= target) {
			printf("does fit our needs, adding\n");
			printf("retSize: %d. current indices array:\n", *returnSize);
			// i want to use the same approach I do when converting decimal to binary
			indices[*returnSize] = sorted_nums[i][1];
			best_res += sorted_nums[i][0];
			(*returnSize)++;
			target   -= sorted_nums[i][0];
			printArray(indices, *returnSize);
		}
	}
	// free memory and sort the indices array
	for (int i = 0; i < numsSize; i ++) {
		free(sorted_nums[i]);
	} free(sorted_nums);

	qsort(indices, *returnSize, sizeof(int), cmpint_asc);
	return indices;
}


int main(int argc, char* argv[]) {
	int nums[] = {-3,4,3,90};
	// int* returnSize = 0; // this is dumb, because I am literally assigning a null pointer
	// int* returnArray = 0;
	int returnSize;
	int* returnArray;
	
	returnArray = twoSum(nums, 4, 0, &returnSize);
	printf("->Result: ");
	printArray(returnArray, returnSize);

	return 0;
}
