#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void generate_permutations(int arr[], int start, int size) {
    if (start == size - 1) {
        print_array(arr, size);
        return;
    }

    for (int i = start; i < size; i++) {
        swap(&arr[start], &arr[i]);
        generate_permutations(arr, start + 1, size);
        swap(&arr[start], &arr[i]); // Backtrack
    }
}

int main() {
    int arr[] = {1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Permutations of the array:\n");
    generate_permutations(arr, 0, size);

    return 0;
}

