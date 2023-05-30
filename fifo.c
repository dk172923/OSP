#include <stdio.h>

#define MAX_FRAMES 5
#define MAX_PAGES 20

int main() {
    int page_frames[MAX_FRAMES];
    int reference_string[MAX_PAGES];
    int num_pages, page_faults = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);

    printf("Enter the page numbers: ");
    for (int i = 0; i < num_pages; i++) {
        scanf("%d", &reference_string[i]);
    }

    // Initialize the page frames to -1 (indicating empty)
    for (int i = 0; i < MAX_FRAMES; i++) {
        page_frames[i] = -1;
    }

    // Perform the FIFO page replacement algorithm
    for (int i = 0; i < num_pages; i++) {
        int page = reference_string[i];
        int page_found = 0;

        // Check if the page is already present in the page frames
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (page_frames[j] == page) {
                page_found = 1;
                break;
            }
        }

        // If the page is not present, replace the oldest page with the new page
        if (!page_found) {
            page_frames[page_faults % MAX_FRAMES] = page;
            page_faults++;
        }

        // Display the page frames after each page request
        printf("Page Frames: ");
        for (int j = 0; j < MAX_FRAMES; j++) {
            printf("%d ", page_frames[j]);
        }
        printf("\n");
    }

    // Display the total number of page faults
    printf("Total Page Faults: %d\n", page_faults);

    return 0;
}

