#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fp;
    char dirname[20];
    char filename[20];
    char data[100];
    // get directory name from user
    printf("Enter the directory name: ");
    scanf("%s", dirname);
    // create directory
    int status = mkdir(dirname);
    if(status != 0) {
        printf("Error creating directory.\n");
        exit(1);
    }
    // get filename from user
    printf("Enter the filename: ");
    scanf("%s", filename);
    // construct full file path
    char filepath[40];
    sprintf(filepath, "%s/%s", dirname, filename);
    // open the file for writing
    fp = fopen(filepath, "w");
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
