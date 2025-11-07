#include <stdio.h>

int findOptimal(int page[], int frame[], int index, int pages, int frames) {
    int i, j, pos = -1, farthest = index;
    
    for(i = 0; i < frames; i++) {
        int found = 0;
        for(j = index; j < pages; j++) {
            if(frame[i] == page[j]) {
                found = 1;
                if(j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        if(found == 0)
            return i; 
    }
    return (pos == -1) ? 0 : pos;
}

int main() {
    int frames, pages, i, j, pos, faults = 0;
    int page[50], frame[10];

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter page reference string:\n");
    for(i = 0; i < pages; i++)
        scanf("%d", &page[i]);

    for(i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\n");

    for(i = 0; i < pages; i++) {
        int flag = 0;

        for(j = 0; j < frames; j++) {
            if(frame[j] == page[i]) {
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            pos = findOptimal(page, frame, i + 1, pages, frames);
            frame[pos] = page[i];
            faults++;
        }

        printf("%d\t", page[i]);
        for(j = 0; j < frames; j++) {
            if(frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}

