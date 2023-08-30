#include <stdio.h>
#include <stdbool.h>

void print_subset(int subset[], int size) {
    printf("Subset: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}

void subset_sum_backtracking(int numbers[], int target_sum, int subset[], int size, int current_sum, int index) {
    if (current_sum == target_sum) {
        print_subset(subset, size);
        return;
    }

    if (index >= size || current_sum > target_sum) {
        return;
    }

    subset[size] = numbers[index];
    subset_sum_backtracking(numbers, target_sum, subset, size + 1, current_sum + numbers[index], index + 1);

    subset_sum_backtracking(numbers, target_sum, subset, size, current_sum, index + 1);
}

int main() {
    int num_numbers;
    printf("Enter the number of numbers: ");
    scanf("%d", &num_numbers);

    int numbers[num_numbers];
    printf("Enter the numbers: ");
    for (int i = 0; i < num_numbers; i++) {
        scanf("%d", &numbers[i]);
    }

    int target_sum;
    printf("Enter the target sum: ");
    scanf("%d", &target_sum);

    int subset[num_numbers];
    subset_sum_backtracking(numbers, target_sum, subset, 0, 0, 0);

    return 0;
}

