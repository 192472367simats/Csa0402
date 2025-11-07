#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, seek = 0;
    int request[50];

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request sequence:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nOrder of servicing requests:\n");
    printf("%d", head);

    for(i = 0; i < n; i++) {
        seek += abs(request[i] - head);
        head = request[i];
        printf(" -> %d", head);
    }

    printf("\n\nTotal Seek Time = %d\n", seek);
    return 0;
}

