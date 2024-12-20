#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "lib/uthash.h"

// Leetcode
typedef struct {
    int key;
    int value;
    UT_hash_handle hh;
} HashEntry;

HashEntry *hashTable = NULL;

void add(int key, int value) {
    HashEntry *entry = (HashEntry *)malloc(sizeof(HashEntry));
    entry->key = key;
    entry->value = value;
    
    HASH_ADD_INT(hashTable, key, entry);
}

HashEntry *find(int key) {
    HashEntry *entry;
    HASH_FIND_INT(hashTable, &key, entry);
    
    return entry;
}

void hashTableDestroy() {
    HashEntry *entry, *tmp;

    HASH_ITER(hh, hashTable, entry, tmp) {
        HASH_DEL(hashTable, entry);
        free(entry);
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *res = (int *)malloc(sizeof(int) * 2);
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        if (find(target - nums[i]) != NULL) {
            res[0] = find(target - nums[i])->value;
            res[1] = i;
            *returnSize = 2;
            
            break;
        }
        
        add(nums[i], i);
    }

    hashTableDestroy();
    
    return res;
}
// !Leetcode

int main() {
    int size;
    int arr1[] = {2,7,11,15};
    int *t = twoSum(arr1, sizeof(arr1)/sizeof(arr1[0]), 9, &size); 
    assert(t[0] == 0 && t[1] == 1);

    free(t);
    
    return 0;
}