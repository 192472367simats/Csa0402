#include <stdio.h>
#include <stdlib.h>

int main() {
    int request[50], n, head, size, i, j, temp, index, seek = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request sequence:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter total disk size: ");
    scanf("%d", &size);

    request[n] = head;
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

    // Move right
    for(i = index+1; i < n; i++) {
        seek += abs(request[i] - head);
        head = request[i];
        printf(" -> %d", head);
    }

    // Jump to start (0)
    seek += abs((size-1) - head);
    head = 0;
    printf(" -> %d", head);

    // Continue servicing remaining left side
    for(i = 0; i <= index-1; i++) {
        seek += abs(request[i] - head);
        head = request[i];
        printf(" -> %d", head);
    }

    printf("\n\nTotal Seek Time = %d\n", seek);
    return 0;
}

