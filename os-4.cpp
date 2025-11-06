#include<stdio.h>

int main(){
    int bt[20], p[20], wt[20], tat[20], i, j, n, pos, temp;
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter burst time for each process:\n");
    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
        p[i] = i+1;   // Process numbering
    }

    // Sorting based on burst time
    for(i=0;i<n;i++){
        pos = i;
        for(j=i+1;j<n;j++){
            if(bt[j] < bt[pos])
                pos = j;
        }
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wt[0] = 0;
    for(i=1;i<n;i++){
        wt[i] = 0;
        for(j=0;j<i;j++)
            wt[i] += bt[j];
        awt += wt[i];
    }

    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++){
        tat[i] = bt[i] + wt[i];
        atat += tat[i];
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", awt/n);
    printf("Average Turnaround Time = %.2f\n", atat/n);

    return 0;
}

