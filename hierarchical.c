#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fp;
    char dirname[20];
    char subdirname[20];
    char filename[20];
    char data[100];
    printf("Enter the directory name: ");
    scanf("%s", dirname);
    int status = mkdir(dirname);
    if(status != 0) {
        printf("Error creating directory.\n");
        exit(1);
    }
    printf("Enter the subdirectory name: ");
    scanf("%s", subdirname);
    char subdirpath[40];
    sprintf(subdirpath, "%s/%s", dirname, subdirname);
    status = mkdir(subdirpath);
    if(status != 0) {
        printf("Error creating subdirectory.\n");
        exit(1);
    }
    printf("Enter the filename: ");
    scanf("%s", filename);
    char filepath[60];
    sprintf(filepath, "%s/%s", subdirpath, filename);
    fp = fopen(filepath, "w");
    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    printf("Enter the data to be written to file: ");
    scanf("%s", data);
    fprintf(fp, "%s", data);
    fclose(fp);
    printf("Data written to file successfully.\n");
    return 0;
}
