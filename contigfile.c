#include <stdio.h>
#define MAX_BLOCKS 100
// Function to allocate a file in contiguous blocks
void allocateFile(int blocks[], int start, int num) {
    for (int i = start; i < start + num; i++) {
        blocks[i] = 1;  // Mark the block as allocated
    }
}
// Function to display the file allocation status
void displayFileAllocation(int blocks[], int totalBlocks) {
    printf("File Allocation Status:\n");
    printf("------------------------------\n");
    printf("Block\t|\tStatus\n");
    printf("------------------------------\n");
    for (int block = 0; block < totalBlocks; block++) {
        printf("%d\t|\t%s\n", block, (blocks[block] ? "Allocated" : "Free"));
    }
    printf("------------------------------\n");
}
int main() {
    int totalBlocks, startBlock, numBlocks;
    int blocks[MAX_BLOCKS] = {0};  // Array to represent block allocation status
    // Prompt the user to enter the total number of blocks
    printf("Enter the total number of blocks: ");
    scanf("%d", &totalBlocks);
    // Prompt the user to enter file details
    printf("Enter the starting block: ");
    scanf("%d", &startBlock);
    printf("Enter the number of blocks: ");
    scanf("%d", &numBlocks);
    // Allocate the file in contiguous blocks
    allocateFile(blocks, startBlock, numBlocks);
    // Display the file allocation status
    displayFileAllocation(blocks, totalBlocks);
    return 0;
}
