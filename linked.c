#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCKS 100

// Structure to represent a block
struct Block {
    int blockNumber;
    struct Block* next;
};

// Structure to represent a file
struct File {
    char fileName[20];
    struct Block* start;
};

int main() {
    int numFiles, numBlocks;
    struct File* files;

    // Prompt the user to enter the number of files
    printf("Enter the number of files: ");
    scanf("%d", &numFiles);

    // Allocate memory for the files array
    files = (struct File*)malloc(numFiles * sizeof(struct File));

    // Process each file
    for (int i = 0; i < numFiles; i++) {
        struct File* file = &files[i];

        // Prompt the user to enter the file name
        printf("Enter the file name: ");
        scanf("%s", file->fileName);

        // Prompt the user to enter the number of blocks allocated to the file
        printf("Enter the number of blocks allocated to %s: ", file->fileName);
        scanf("%d", &numBlocks);

        // Allocate memory for the blocks
        struct Block* blocks = (struct Block*)malloc(numBlocks * sizeof(struct Block));

        // Assign blocks to the file
        for (int j = 0; j < numBlocks; j++) {
            blocks[j].blockNumber = j;
            blocks[j].next = (j < numBlocks - 1) ? &blocks[j + 1] : NULL;
        }

        // Set the starting block of the file
        file->start = blocks;
    }

    // Display the file allocation status
    printf("\nFile Allocation Status:\n");
    printf("------------------------------\n");
    for (int i = 0; i < numFiles; i++) {
        struct File* file = &files[i];
        printf("File Name: %s\n", file->fileName);
        printf("Blocks Allocated: ");
        struct Block* block = file->start;
        while (block != NULL) {
            printf("%d ", block->blockNumber);
            block = block->next;
        }
        printf("\n");
    }
    printf("------------------------------\n");

    // Free allocated memory
    for (int i = 0; i < numFiles; i++) {
        free(files[i].start);
    }
    free(files);

    return 0;
}

