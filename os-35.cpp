#include <stdio.h>

int main() {
    int indexBlock, i, n;
    int block[50] = {0};
    int fileBlocks[20];

    printf("Enter the index block: ");
    scanf("%d", &indexBlock);

    if(block[indexBlock] == 1) {
        printf("Index block already allocated. Try another.\n");
        return 0;
    }

    block[indexBlock] = 1;

    printf("Enter number of blocks allocated for the file: ");
    scanf("%d", &n);

    printf("Enter block numbers allocated to file:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &fileBlocks[i]);
    }

    // Check if any block is already allocated
    for(i = 0; i < n; i++) {
        if(block[fileBlocks[i]] == 1) {
            printf("Block %d is already allocated. Allocation failed.\n", fileBlocks[i]);
            return 0;
        }
    }

    // Allocate blocks
    for(i = 0; i < n; i++) {
        block[fileBlocks[i]] = 1;
    }

    printf("\nFile allocated successfully!\n");
    printf("Index Block: %d\n", indexBlock);
    printf("Blocks allocated: ");
    for(i = 0; i < n; i++)
        printf("%d ", fileBlocks[i]);

    printf("\n");
    return 0;
}

