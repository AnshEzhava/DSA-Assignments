#include <stdio.h>
#include <stdlib.h>

int main() {
    int *inventory;
    int current_size = 10;
    int new_size;
    int i;
    
    inventory = (int*) malloc(current_size * sizeof(int));

    if (inventory == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    for (i = 0; i < current_size; i++) {
        inventory[i] = i + 1;
    }

    printf("Initial inventory:\n");
    for (i = 0; i < current_size; i++) {
        printf("Packet %d: %d\n", i+1, inventory[i]);
    }

    printf("\nEnter new inventory size (greater than %d): ", current_size);
    scanf("%d", &new_size);

    if (new_size > current_size) {
        inventory = (int*) realloc(inventory, new_size * sizeof(int));
        if (inventory == NULL) {
            printf("Memory reallocation failed!\n");
            return 1;
        }
        
        for (i = current_size; i < new_size; i++) {
            inventory[i] = i + 1;
        }

        current_size = new_size;
    }

    printf("\nExpanded inventory:\n");
    for (i = 0; i < current_size; i++) {
        printf("Packet %d: %d\n", i+1, inventory[i]);
    }

    printf("\nEnter new inventory size (less than %d): ", current_size);
    scanf("%d", &new_size);

    if (new_size < current_size) {
        inventory = (int*) realloc(inventory, new_size * sizeof(int));
        if (inventory == NULL) {
            printf("Memory reallocation failed!\n");
            return 1;
        }

        current_size = new_size;
    }

    printf("\nShrunk inventory:\n");
    for (i = 0; i < current_size; i++) {
        printf("Packet %d: %d\n", i+1, inventory[i]);
    }

    free(inventory);

    return 0;
}
