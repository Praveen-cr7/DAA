#include <stdio.h>

void generate_factors(int n) {
    printf("Factors of %d: ", n);
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter a value of n: ");
    scanf("%d", &n);

    generate_factors(n);

    return 0;
}

