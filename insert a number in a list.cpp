#include <stdio.h>

void insert_number(int num_list[], int num, int position, int size) {
    for (int i = size - 1; i >= position; i--) {
        num_list[i + 1] = num_list[i];
    }
    num_list[position] = num;
}

int main() {
    int num_list[100];
    int size, num, position;

    printf("Enter the size of the list: ");
    scanf("%d", &size);

    printf("Enter %d numbers: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &num_list[i]);
    }

    printf("Enter the number to insert: ");
    scanf("%d", &num);

    printf("Enter the position to insert at: ");
    scanf("%d", &position);

    insert_number(num_list, num, position, size);

    printf("Updated list: ");
    for (int i = 0; i < size + 1; i++) {
        printf("%d ", num_list[i]);
    }
    printf("\n");

    return 0;
}

