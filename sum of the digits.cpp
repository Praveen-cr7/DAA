#include <stdio.h>

int sum_of_digits(int n) {
    int total_sum = 0;
    while (n > 0) {
        total_sum += n % 10;
        n /= 10;
    }
    return total_sum;
}

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    int result = sum_of_digits(num);
    printf("The sum of digits of %d is %d\n", num, result);

    return 0;
}

