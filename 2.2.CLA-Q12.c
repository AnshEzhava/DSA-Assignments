#include <stdio.h>

int main() {
    int weights[5];
    int total_weight = 0;

    printf("Enter the weights of the 5 treasures:\n");

    for (int i = 0; i < 5; i++) {
        printf("Treasure %d: ", i + 1);
        scanf("%d", &weights[i]);
    }

    for (int i = 0; i < 5; i++) {
        total_weight += weights[i];
    }

    printf("\nTotal weight collected: %d\n", total_weight);

    return 0;
}
