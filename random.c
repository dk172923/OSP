#include <stdio.h>
struct Record {
    int id;
    char name[50];
};
int main() {
    FILE *file;
    struct Record record;
    // Open the file in binary mode for read and write operations
    file = fopen("records.bin", "rb+");
    if (file == NULL) {
        printf("File does not exist. Creating a new file...\n");
        file = fopen("records.bin", "wb+");
        // Create and write some initial records to the file
        struct Record records[3] = {
            {1, "John Doe"},
            {2, "Jane Smith"},
            {3, "Alice Johnson"}
        };
        fwrite(records, sizeof(struct Record), 3, file);
    }
    // Move the file pointer to the second record
    fseek(file, sizeof(struct Record), SEEK_SET);
    // Read the second record from the file
    fread(&record, sizeof(struct Record), 1, file);
    printf("Current record: ID=%d, Name=%s\n", record.id, record.name);
    // Update the second record
    record.id = 4;
    sprintf(record.name, "Bob Anderson");
    // Move the file pointer back to the second record
    fseek(file, sizeof(struct Record), SEEK_SET);
    // Write the updated record back to the file
    fwrite(&record, sizeof(struct Record), 1, file);
    // Move the file pointer to the beginning
    fseek(file, 0, SEEK_SET);
    // Read all the records from the file and print them
    printf("\nAll records:\n");
    while (fread(&record, sizeof(struct Record), 1, file) == 1) {
        printf("ID=%d, Name=%s\n", record.id, record.name);
    }
    // Close the file
    fclose(file);
    return 0;
}
