#include <stdio.h>

int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index where the target is found
        }
    }
    return -1; // Return -1 if target is not found
}

int main() {
    int arr[] = {12, 34, 45, 67, 89, 90, 23, 56};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    int result = linear_search(arr, size, target);

    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}

