#include <stdio.h>
#include <stdlib.h>

#define INIT_CAPACITY 4

typedef struct {
    int* data;
    int capacity;
    int size;
} DynamicArray;

DynamicArray* init_array(void) {
    DynamicArray *arr = malloc(sizeof(DynamicArray));
    if (arr == NULL) {
        printf("Failed to allocate memory for meta-data\n");
        exit(1);
    }

    arr->data = malloc(INIT_CAPACITY * sizeof(int));
    if (arr->data == NULL) {
        printf("Failed to allocated memory for array.\n");
    }

    arr->capacity = INIT_CAPACITY;
    arr->size = 0;
}

void append(DynamicArray *arr, int value) {
    if (arr->size == arr->capacity) {
        // Double the capacity 
        arr->capacity *= 2;
        arr->data = realloc(arr->data, arr->capacity * sizeof(int));
        if (arr->data == NULL) {
            printf("Reallocation failed.\n");
            exit(1);
        }
    }

    arr->data[arr->size] = value;
    arr->size++;
}

int pop(DynamicArray *arr) {
    if (arr == NULL) {
        printf("Can't pop from empty array.\n");
        exit(1);
    }
    // Return the last element and reduce arr size
    arr->size--;
    return arr->data[arr->size];
}

void freeArray(DynamicArray *arr) {
    free(arr->data);
    free(arr);
}

int main() {
    DynamicArray *arr = init_array();

    // Append some elements in array
    for (int i = 0; i < 10; i++) {
        append(arr, i);
        printf("Added: %d | size: %d | capacity: %d\n", arr->data[i], arr->size, arr->capacity);
    }

    // test poping 
    int top = pop(arr);
    printf("Poped element: %d\n", top);
    printf("After poping size of array: %d", arr->size);

    return 0;

}