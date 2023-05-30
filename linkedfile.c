#include <stdio.h>
#include <stdlib.h>

// Structure to represent a block
struct Block {
    int blockNumber;      // Block number
    struct Block* next;   // Pointer to the next block
};

// Structure to represent a file
struct File {
    char fileName[20];    // File name
    struct Block* start;  // Pointer to the starting block
};

// Function to allocate a new block
struct Block* allocateBlock(int blockNumber) {
    struct Block* newBlock = (struct Block*)malloc(sizeof(struct Block));
    newBlock->blockNumber = blockNumber;
    newBlock->next = NULL;
    return newBlock;
}

// Function to create a file
void createFile(struct File* file) {
    printf("Enter the file name: ");
    scanf("%s", file->fileName);
    file->start = NULL;
}

// Function to add a block to a file
void addBlock(struct File* file, int blockNumber) {
    struct Block* newBlock = allocateBlock(blockNumber);

    if (file->start == NULL) {
        file->start = newBlock;
    } else {
        struct Block* current = file->start;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newBlock;
    }
}

// Function to display the file allocation
void displayFileAllocation(struct File* file) {
    printf("File Name: %s\n", file->fileName);
    printf("Blocks Allocated: ");

    struct Block* current = file->start;
    while (current != NULL) {
        printf("%d ", current->blockNumber);
        current = current->next;
    }

    printf("\n");
}

int main() {
    int numFiles, numBlocks;

    printf("Enter the number of files: ");
    scanf("%d", &numFiles);

    struct File files[numFiles];

    for (int i = 0; i < numFiles; i++) {
        createFile(&files[i]);

        printf("Enter the number of blocks allocated to %s: ", files[i].fileName);
        scanf("%d", &numBlocks);

        for (int j = 0; j < numBlocks; j++) {
            int blockNumber;
            printf("Enter block number %d: ", j + 1);
            scanf("%d", &blockNumber);
            addBlock(&files[i], blockNumber);
        }
    }

    printf("\nFile Allocation Status:\n");
    printf("------------------------------\n");
    for (int i = 0; i < numFiles; i++) {
        displayFileAllocation(&files[i]);
    }
    printf("------------------------------\n");

    return 0;
}

