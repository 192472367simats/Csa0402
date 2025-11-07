#include <stdio.h>

int main() {
    int block[50] = {0};
    int start, length, next, i;

    printf("Enter starting block of the file: ");
    scanf("%d", &start);

    printf("Enter number of blocks needed for the file: ");
    scanf("%d", &length);

    next = start;

    // Check and allocate blocks
    for(i = 0; i < length; i++) {
        if(block[next] == 0) {
            block[next] = 1;
            printf("Block %d allocated.\n", next);
            printf("Enter the next block number linked with this: ");
            scanf("%d", &next);  
        } 
        else {
            printf("Block %d is already allocated. Allocation stopped.\n", next);
            return 0;
        }
    }

    printf("\nFile allocated successfully using Linked Allocation.\n");
    return 0;
}

