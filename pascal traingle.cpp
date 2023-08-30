#include <stdio.h>

int binomial_coefficient(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    return binomial_coefficient(n - 1, k - 1) + binomial_coefficient(n - 1, k);
}

void generate_pascals_triangle(int num_rows) {
    for (int line = 0; line < num_rows; line++) {
        for (int j = 0; j <= line; j++) {
            printf("%d ", binomial_coefficient(line, j));
        }
        printf("\n");
    }
}

int main() {
    int num_rows;

    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &num_rows);

    generate_pascals_triangle(num_rows);

    return 0;
}

