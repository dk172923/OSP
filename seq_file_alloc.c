#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100

int main() {
    char file_name[50];
    int num_blocks;
    FILE *file;

    printf("Enter the file name: ");
    scanf("%s", file_name);

    printf("Enter the number of blocks to allocate: ");
    scanf("%d", &num_blocks);

    file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Error creating file.\n");
        return 1;
    }

    for (int i = 1; i <= num_blocks; i++) {
        fprintf(file, "Block %d\n", i);
    }

    fclose(file);
    printf("File '%s' created with %d blocks allocated.\n", file_name, num_blocks);

    return 0;
}

