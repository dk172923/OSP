#include <stdio.h>

#define MAX_FRAMES 3
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

    for (int i = 0; i < MAX_FRAMES; i++) {
        page_frames[i] = -1;
    }

    for (int i = 0; i < num_pages; i++) {
        int page = reference_string[i];
        int page_found = 0;
        int optimal_page_index = -1;

        for (int j = 0; j < MAX_FRAMES; j++) {
            if (page_frames[j] == page) {
                page_found = 1;
                break;
            }
            if (optimal_page_index == -1 || page_frames[optimal_page_index] == -1) {
                optimal_page_index = j;
            } else if (reference_string[i + 1] == page_frames[j]) {
                optimal_page_index = j;
                break;
            }
        }

        if (!page_found) {
            page_frames[optimal_page_index] = page;
            page_faults++;
        }

        printf("Page Frames: ");
        for (int j = 0; j < MAX_FRAMES; j++) {
            printf("%d ", page_frames[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", page_faults);

    return 0;
}

