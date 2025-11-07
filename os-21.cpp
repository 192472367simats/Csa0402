#include <stdio.h>

int main(){
    int b[10], p[10], i, j, nb, np, temp;
    printf("Enter number of blocks: ");
    scanf("%d",&nb);
    printf("Enter the size of each block:\n");
    for(i=0;i<nb;i++) scanf("%d",&b[i]);

    printf("Enter number of processes: ");
    scanf("%d",&np);
    printf("Enter size of each process:\n");
    for(i=0;i<np;i++) scanf("%d",&p[i]);

    for(i=0;i<np;i++){
        int pos = -1;
        for(j=0;j<nb;j++){
            if(b[j] >= p[i]){
                if(pos==-1 || b[j] > b[pos])
                    pos = j;
            }
        }
        if(pos != -1){
            printf("Process %d allocated to block %d\n", i+1, pos+1);
            b[pos] -= p[i];
        } else {
            printf("Process %d must wait\n", i+1);
        }
    }
    return 0;
}

