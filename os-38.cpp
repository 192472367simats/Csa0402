#include <stdio.h>
#include <stdlib.h>

int main() {
    int request[50], n, head, i, j, temp, size, direction;
    int seek = 0, index;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request sequence:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter total disk size: ");
    scanf("%d", &size);

    printf("Enter direction (1 = right, 0 = left): ");
    scanf("%d", &direction);

    request[n] = head;  // include current head in list
    n++;

    // Sort the request list
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if(request[i] > request[j]) {
                temp = request[i];
                request[i] = request[j];
                request[j] = temp;
            }
        }
    }

    // Find head index
    for(i = 0; i < n; i++) {
        if(request[i] == head) {
            index = i;
            break;
        }
    }

    printf("\nSeek Sequence:\n%d", head);

    if(direction == 1) { // move right
        for(i = index+1; i < n; i++) {
            seek += abs(request[i] - head);
            head = request[i];
            printf(" -> %d", head);
        }
        seek += abs((size-1) - head);
        head = size-1;
        printf(" -> %d", head);
        for(i = index-1; i >= 0; i--) {
            seek += abs(request[i] - head);
            head = request[i];
            printf(" -> %d", head);
        }
    }
    else { // move left
        for(i = index-1; i >= 0; i--) {
            seek += abs(request[i] - head);
            head = request[i];
            printf(" -> %d", head);
        }
        seek += abs(head - 0);
        head = 0;
        printf(" -> %d", head);
        for(i = index+1; i < n; i++) {
            seek += abs(request[i] - head);
            head = request[i];
            printf(" -> %d", head);
        }
    }

    printf("\n\nTotal Seek Time = %d\n", seek);
    return 0;
}

