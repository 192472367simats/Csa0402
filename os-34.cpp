#include <stdio.h>

int main() {
    int start, length, i;
    int memory[50] = {0};   // 0 means free, 1 means allocated

    printf("Enter starting block: ");
    scanf("%d", &start);

    printf("Enter length of file (number of blocks required): ");
    scanf("%d", &length);

    // Check if blocks are free
    for(i = start; i < start + length; i++) {
        if(memory[i] == 1) {
            printf("Block %d is already allocated. File cannot be allocated.\n", i);
            return 0;
        }
    }

    // Allocate blocks
    for(i = start; i < start + length; i++)
        memory[i] = 1;

    printf("\nFile allocated successfully!\n");
    printf("Blocks allocated: ");
    for(i = start; i < start + length; i++)
        printf("%d ", i);

    printf("\n");
    return 0;
}

