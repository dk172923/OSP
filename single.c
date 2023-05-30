#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fp;
    char filename[20];
    char data[100];
    // get filename from user
    printf("Enter the filename: ");
    scanf("%s", filename);
    // open the file for writing
    fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    // get data from user and write it to file
    printf("Enter the data to be written to file: ");
    scanf("%s", data);
    fprintf(fp, "%s", data);
    // close the file
    fclose(fp);
    printf("Data written to file successfully.\n");
    return 0;
}
