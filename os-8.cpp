#include <stdio.h>

int main() {
    int n, i, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rem[n], wt[n], tat[n], completion[n];
    for (i = 0; i < n; i++) {
        printf("Enter burst time for P%d: ", i+1);
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
        wt[i] = 0;
        tat[i] = 0;
        completion[i] = 0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    int t = 0;            // current time
    int done;             // flag to check if all are done

    while (1) {
        done = 1;
        for (i = 0; i < n; i++) {
            if (rem[i] > 0) {
                done = 0; // there is a pending process
                if (rem[i] > quantum) {
                    t += quantum;
                    rem[i] -= quantum;
                } else {
                    t += rem[i];
                    completion[i] = t;
                    rem[i] = 0;
                }
            }
        }
        if (done) break;
    }

    float sum_wt = 0, sum_tat = 0;
    printf("\nProcess\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        tat[i] = completion[i];            // arrival assumed 0 ? TAT = completion - 0
        wt[i] = completion[i] - bt[i];     // WT = completion - BT - arrival(0)
        if (wt[i] < 0) wt[i] = 0;          // safety
        sum_wt += wt[i];
        sum_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", sum_wt / n);
    printf("Average Turnaround Time = %.2f\n", sum_tat / n);

    return 0;
}

