#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    int count = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0) {
        n = -n;
    }

    int previous_digit = -1;

    while (n > 9) {
        int last_two_digits = n % 100;
        if (isPrime(last_two_digits)) {
            count++;
        }
        n /= 10;
    }

    printf("Number of two-digit prime numbers: %d\n", count);

    return 0;
}
