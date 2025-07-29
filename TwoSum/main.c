#include <stdio.h>
#include <stdlib.h>

#define STD_HASHMAP_SIZE 10000

/* the entries of the hashmap are formed in such way, that the hash function maps 
 * each key to the unique index, but if we are trying to pack the same two keys 
 * in the hashmap, then it may lead to a collision, which will require recalculation
 * of the index
 */
typedef enum { EMPTY = 0, OCCUPIED = 1, DELETED = 2} entryStatus; 
typedef struct Entry {
	int key;
	int value;
	int nums_idx;
	entryStatus status;
} Entry;

typedef struct {
	Entry** buckets;
	int size;
} HashMap;

void printHashMap(HashMap* table) {
	// table is a pointer to the hashmap, therefore we access it's values via ->
	printf("HashMap at addr: %p\n", (void*)table); // %p expects (void*)
	int key, val, nums_idx;
	for (int i = 0; i < table->size; i++) {
		key = table->buckets[i]->key;
		val = table->buckets[i]->value;
		nums_idx = table->buckets[i]->nums_idx;
		printf("[%d]: {%d:[%d, %d]} -- ", i, key, val, nums_idx);
		switch (table->buckets[i]->status) {
			case EMPTY:
				printf("EMPTY\n");
				break;
			case OCCUPIED:
				printf("OCCUPIED\n");
				break;
			case DELETED:
				printf("DELETED\n");
				break;
		}
	}
}

int mod(int a, int b) { // appratentlly % is not mod, but remainder
	int r = a % b;
	return r < 0 ? r + b : r;
}

int hashFunction(int key, int attempt, int tableSize) {
	// linear probing 
	int idx = mod((mod(key, tableSize) + attempt), tableSize);
	return idx;
}

void addHashMapEntry(HashMap* table, int key, int value, int nums_idx) {
	int idx = 0;
	for (int i = 0; i < table->size; i++) {
		idx = hashFunction(key, i, table->size);
		if (table->buckets[idx]->status == EMPTY) {
			table->buckets[idx]->key = key;
			table->buckets[idx]->value = value;
			table->buckets[idx]->status = OCCUPIED;
			table->buckets[idx]->nums_idx = nums_idx;
			printf("Entry for hashmap: %p added. [%d]: {%d:%d} (nums idx: %d)\n", (void*)table, 
					idx, key, value, nums_idx);
			break;
		} 
	}
}

HashMap* createHashMap(int size) {
	Entry** entries = malloc(sizeof(Entry*) * size);
	for (int i=0; i < size; i++) {
		entries[i] = malloc(sizeof(Entry));
		entries[i]->key = 0;
		entries[i]->value = 0;
		entries[i]->status = EMPTY;
		entries[i]->nums_idx = 0;
	}
	HashMap *table = malloc(sizeof(HashMap));
	table->buckets = entries;
	table->size = size;
	return table;
}

// returns Entry array index if found this key and -1 if didn't
int isKeyOccupied(HashMap *table, int key) {
	int idx = 0;
	for (int i = 0; i < table->size; i++) {
		idx = hashFunction(key, i, table->size);
		if (table->buckets[idx]->status == OCCUPIED && table->buckets[idx]->key == key) {
			printf("Key {%d:%d (%d)} is occupied at id %d\n", key, table->buckets[idx]->value, idx, 
					table->buckets[idx]->nums_idx);
			return idx;
		} else if (table->buckets[idx]->status == EMPTY) {
			break;
		}
	}
	printf("Key %d is not occupied\n", key);
	return -1;
}

void freeHashMap(HashMap *table) {
	// Entry** entries = malloc(sizeof(Entry*) * size);
	// for (int i=0; i < size; i++) {
	// 	entries[i] = malloc(sizeof(Entry));
	// 	entries[i]->key = 0;
	// 	entries[i]->value = 0;
	// 	entries[i]->status = EMPTY;
	// 	entries[i]->nums_idx = 0;
	// }
	// HashMap *table = malloc(sizeof(HashMap));
	for (int i = 0; i < table->size; i++) {
		free(table->buckets[i]);
	}
	free(table->buckets);
	free(table);
	return;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
	int *indices = malloc(sizeof(int) * 2);
	*returnSize = 2;
	HashMap *table = createHashMap(numsSize);
	int complement = 0;
	int searchRes = 0;
	for (int i = 0; i < numsSize; i++) {
		complement = target - nums[i];
		searchRes = isKeyOccupied(table, complement); // 0
		addHashMapEntry(table, nums[i], complement, i);
		if (searchRes != -1) {
			indices[0] = table->buckets[searchRes]->nums_idx;
			indices[1] = i;
			printHashMap(table);
			freeHashMap(table);
			return indices;
		} 
	}
	printHashMap(table);
	freeHashMap(table);
	return NULL;
}

int main(int argc, char *argv[]) {
	
	int nums1[] = {2,7,11,15};
	int nums2[] = {-3, 4, 3, 90};
	int numsSize = 4;
	// int* returnsize = 0; // this is dumb, because i am literally assigning a
	// null pointer int* returnarray = 0;
	int returnsize;
	int *returnarray;

	int target = 9;
	returnarray = twoSum(nums1, numsSize, target, &returnsize);
	if (returnarray[0] == 0 && returnarray[1] == 1) {
		printf("For array [");
		for (int i = 0; i < numsSize-1; i++) {
			printf("%d, ", nums1[i]);
		} printf("%d], target=%d, indices are: [%d, %d]\n\n\n", nums1[numsSize-1], target,
				returnarray[0], returnarray[1]);
		free(returnarray);
	} else {
		printf("Expected return [0, 1], but got [%d, %d]\n", returnarray[0], returnarray[1]);
		free(returnarray); 
		return -1;
	}

	target = 0;
	returnarray = twoSum(nums2, numsSize, target, &returnsize);
	if (returnarray[0] == 0 && returnarray[1] == 2) {
		printf("For array [");
		for (int i = 0; i < numsSize-1; i++) {
			printf("%d, ", nums2[i]);
		} printf("%d], target=%d, indices are: [%d, %d]\n\n\n", nums2[numsSize-1], target,
				returnarray[0], returnarray[1]);
		free(returnarray);
	} else {
		printf("Expected return [0, 2], but got [%d, %d]\n", returnarray[0], returnarray[1]);
		free(returnarray); 
		return -1;
	}

	int nums3[] = {3, 2, 4};
	numsSize = 3;
	target = 6;
	returnarray = twoSum(nums3, numsSize, target, &returnsize);
	if (returnarray[0] == 1 && returnarray[1] == 2) {
		printf("For array [");
		for (int i = 0; i < numsSize-1; i++) {
			printf("%d, ", nums3[i]);
		} printf("%d], target=%d, indices are: [%d, %d]\n", nums3[numsSize-1], target,
				returnarray[0], returnarray[1]);
		free(returnarray);
	} else {
		printf("Expected return [1, 2], but got [%d, %d]\n", returnarray[0], returnarray[1]);
		free(returnarray); 
		return -1;
	}
	return 0;
}
