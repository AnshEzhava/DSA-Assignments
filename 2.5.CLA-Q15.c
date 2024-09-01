#include <stdio.h>

#define MAX_BOOKS 100

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int book_ids[MAX_BOOKS];
    int n, target, result;

    printf("Enter the number of books: ");
    scanf("%d", &n);

    printf("Enter the book IDs in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("Book ID %d: ", i + 1);
        scanf("%d", &book_ids[i]);
    }

    printf("Enter the book ID to search: ");
    scanf("%d", &target);

    result = binarySearch(book_ids, n, target);

    if (result != -1) {
        printf("Book ID %d is available in the library.\n", target);
    } else {
        printf("Book ID %d is not available in the library.\n", target);
    }

    return 0;
}
