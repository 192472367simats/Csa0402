#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], completed[n];
    int wt[n], tat[n];
    for(i=0;i<n;i++){
        printf("Enter arrival time and burst time for P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        completed[i] = 0;
        wt[i] = tat[i] = 0;
    }

    int completed_count = 0;
    int time = 0;

    while (completed_count < n) {
        int idx = -1;
        int min_bt = 1e9;

        // find process with smallest burst time among arrived and not completed
        for (i = 0; i < n; i++) {
            if (!completed[i] && at[i] <= time) {
                if (bt[i] < min_bt) {
                    min_bt = bt[i];
                    idx = i;
                }
                // tie-breaker: earlier arrival or lower pid (optional)
                else if (bt[i] == min_bt) {
                    if (at[i] < at[idx]) idx = i;
                }
            }
        }

        if (idx == -1) {
            // no process has arrived yet, advance time
            time++;
        } else {
            int start = time;
            int finish = start + bt[idx];
            wt[idx] = start - at[idx];
            if (wt[idx] < 0) wt[idx] = 0; // safety
            tat[idx] = finish - at[idx];
            time = finish;
            completed[idx] = 1;
            completed_count++;
        }
    }

    // print results
    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    float sum_wt = 0, sum_tat = 0;
    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);
        sum_wt += wt[i];
        sum_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f\n", sum_wt / n);
    printf("Average Turnaround Time = %.2f\n", sum_tat / n);

    return 0;
}

