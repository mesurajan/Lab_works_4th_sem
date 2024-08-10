#include <stdio.h>
#define SIZE 8

int main() {
    int bitmap[SIZE] = {0};  
    int choice, block;

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Display Bitmap\n");
        printf("2. Allocate Block\n");
        printf("3. Free Block\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Bitmap: ");
                for (int i = 0; i < SIZE; i++) {
                    printf("%d ", bitmap[i]);
                }
                printf("\n");
                break;

            case 2:
                
                printf("Enter block number to allocate (0-%d): ", SIZE-1);
                scanf("%d", &block);
                if (block >= 0 && block < SIZE) {
                    if (bitmap[block] == 0) {
                        bitmap[block] = 1;
                        printf("Block %d allocated.\n", block);
                    } else {
                        printf("Block %d is already occupied.\n", block);
                    }
                } else {
                    printf("Invalid block number.\n");
                }
                break;

            case 3:
                
                printf("Enter block number to free (0-%d): ", SIZE-1);
                scanf("%d", &block);
                if (block >= 0 && block < SIZE) {
                    if (bitmap[block] == 1) {
                        bitmap[block] = 0;
                        printf("Block %d freed.\n", block);
                    } else {
                        printf("Block %d is already free.\n", block);
                    }
                } else {
                    printf("Invalid block number.\n");
                }
                break;

            case 4:
                
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
