#include<stdio.h>

int main(){
    int n, bt[20], p[20], pr[20], wt[20], tat[20];
    int i, j, pos, temp;
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter burst time and priority for each process:\n");
    for(i=0;i<n;i++){
        scanf("%d %d",&bt[i],&pr[i]);
        p[i] = i+1; // process numbering
    }

    // Sort according to priority (lower = higher priority)
    for(i=0;i<n;i++){
        pos = i;
        for(j=i+1;j<n;j++){
            if(pr[j] < pr[pos])
                pos = j;
        }

        temp = pr[i]; pr[i] = pr[pos]; pr[pos] = temp;
        temp = bt[i]; bt[i] = bt[pos]; bt[pos] = temp;
        temp = p[i]; p[i] = p[pos]; p[pos] = temp;
    }

    wt[0] = 0;
    for(i=1;i<n;i++){
        wt[i] = wt[i-1] + bt[i-1];
        awt += wt[i];
    }

    printf("\nProcess\tBT\tPR\tWT\tTAT\n");
    for(i=0;i<n;i++){
        tat[i] = wt[i] + bt[i];
        atat += tat[i];
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i], bt[i], pr[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", awt/n);
    printf("Average Turnaround Time = %.2f\n", atat/n);

    return 0;
}

