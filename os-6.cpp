#include<stdio.h>

int main(){
    int i, n, bt[10], rem[10], quant, wt=0, tat=0, time=0;
    float awt=0, atat=0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for(i=0;i<n;i++){
        scanf("%d", &bt[i]);
        rem[i] = bt[i];  // copy burst time to remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quant);

    printf("\nProcess\tBT\tWT\tTAT\n");

    while(1){
        int done = 1;
        for(i=0;i<n;i++){
            if(rem[i] > 0){
                done = 0;
                if(rem[i] > quant){
                    time += quant;
                    rem[i] -= quant;
                }
                else{
                    time += rem[i];
                    wt = time - bt[i];
                    tat = time;
                    rem[i] = 0;
                    printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt, tat);
                    awt += wt;
                    atat += tat;
                }
            }
        }
        if(done == 1)
            break;
    }

    printf("\nAverage Waiting Time = %.2f", awt/n);
    printf("\nAverage Turnaround Time = %.2f\n", atat/n);

    return 0;
}

