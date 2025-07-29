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
	entryStatus status;
} Entry;

typedef struct {
	Entry** buckets;
	int size;
} HashMap;

void printHashMap(HashMap* table) {
	// table is a pointer to the hashmap, therefore we access it's values via ->
	printf("HashMap at addr: %p\n", (void*)table); // %p expects (void*)
	int key, val;
	for (int i = 0; i < table->size; i++) {
		key = table->buckets[i]->key;
		val = table->buckets[i]->value;
		printf("[%d]: {%d:%d} -- ", i, key, val);
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

void addHashMapEntry(HashMap* table, int key, int value) {
	int idx = 0;
	for (int i = 0; i < table->size; i++) {
		idx = hashFunction(key, i, table->size);
		if (table->buckets[idx]->status == EMPTY) {
			table->buckets[idx]->key = key;
			table->buckets[idx]->value = value;
			table->buckets[idx]->status = OCCUPIED;
			printf("Entry for hashmap: %p added. [%d]: {%d:%d}\n", (void*)table, idx, key, value);
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
	}
	HashMap *table = malloc(sizeof(HashMap));
	table->buckets = entries;
	table->size = size;
	return table;
}

int isKeyOccupied(HashMap *table, int key) {
	int idx = 0;
	for (int i = 0; i < table->size; i++) {
		idx = hashFunction(key, i, table->size);
		if (table->buckets[idx]->status == OCCUPIED && table->buckets[idx]->key == key) {
			printf("Key {%d:%d} is occupied at id %d\n", key, table->buckets[idx]->value, idx);
			return 1;
		} else if (table->buckets[idx]->status == EMPTY) {
			break;
		}
	}
	printf("Key %d is not occupied\n", key);
	return -1;
}

int main(int argc, char* argv[]) {
	HashMap *table = createHashMap(20);
	addHashMapEntry(table, 10, 20);
	addHashMapEntry(table, 30, 21);
	isKeyOccupied(table, 10);
	isKeyOccupied(table, 30);
	// printHashMap(table);
	
	// test negative key
	addHashMapEntry(table, -8, 123);
	return 0;
}
