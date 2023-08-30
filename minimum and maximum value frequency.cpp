#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

void min_max_subsequence(int num_list[], int size) {
    int min_subsequence[MAX_SIZE], max_subsequence[MAX_SIZE];

    int min_value = INT_MAX, max_value = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (num_list[i] < min_value) {
            min_value = num_list[i];
        }
        min_subsequence[i] = min_value;
    }

    for (int i = size - 1; i >= 0; i--) {
        if (num_list[i] > max_value) {
            max_value = num_list[i];
        }
        max_subsequence[i] = max_value;
    }

    printf("Minimum value subsequences:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", min_subsequence[i]);
    }
    printf("\n");

    printf("Maximum value subsequences:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", max_subsequence[i]);
    }
    printf("\n");
}

int main() {
    int num_list[MAX_SIZE], size;

    printf("Enter the size of the list: ");
    scanf("%d", &size);

    printf("Enter %d numbers: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &num_list[i]);
    }

    min_max_subsequence(num_list, size);

    return 0;
}

