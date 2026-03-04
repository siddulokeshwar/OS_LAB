#include<stdio.h>
#include<stdlib.h>

int main(){
    int at[20],bt[20],ct[20],wt[20],tat[20],n;
    float ttat=0.0,twt=0.0,awt,atat;

    printf("\nEnter no of process:");
    scanf("%d",&n);

    printf("Enter processs arrival time and burst time:\n");
    for(int i=0;i<n;i++)scanf("%d\t%d",&at[i],&bt[i]);

    ct[0] = at[0]+bt[0];
    wt[0] = 0;
    tat[0] = bt[0];

    for(int i=1;i<n;i++){
        if(ct[i-1]<at[i]){
            ct[i] = at[i]+bt[i];
            wt[i] = 0;
        }else{
            wt[i] = ct[i-1]-at[i];
            ct[i]= ct[i-1]+bt[i];
        }
        tat[i] = ct[i]-at[i];
    }

    for(int i=0;i<n;i++){
        twt += wt[i];
        ttat += tat[i];
    }
    awt=twt/n;
    atat=ttat/n;
    printf("\nProcess\tAt\tBt\tCt\tWt\tTat\n");
    for(int i=0;i<n;i++)printf("%d\t%d\t%d\t%d\t%d\t%d\n",i,at[i],bt[i],ct[i],wt[i],tat[i]);
    printf("\nAverage waiting time is: %f",awt);
    printf("\nAverage turn around time is: %f\n",atat);

    return 0;
}
