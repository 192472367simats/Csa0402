#include <stdio.h>

int findLRU(int time[], int n) {
    int i, min = time[0], pos = 0;
    for(i = 1; i < n; ++i){
        if(time[i] < min){
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int frames, pages, i, j, counter = 0, faults = 0, pos;
    int page[50], frame[10], time[10];

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

    for(i = 0; i < pages; i++){
        int flag = 0;

        for(j = 0; j < frames; j++){
            if(frame[j] == page[i]){
                counter++;
                time[j] = counter;
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            for(j = 0; j < frames; j++){
                if(frame[j] == -1){
                    counter++;
                    faults++;
                    frame[j] = page[i];
                    time[j] = counter;
                    flag = 1;
                    break;
                }
            }
        }

        if(flag == 0){
            pos = findLRU(time, frames);
            counter++;
            frame[pos] = page[i];
            time[pos] = counter;
            faults++;
        }

        printf("%d\t", page[i]);
        for(j = 0; j < frames; j++){
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

