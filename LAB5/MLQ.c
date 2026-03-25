#include <stdio.h>
#define MAX 100

int main() {
    int n;
    int PID[MAX], AT[MAX], BT[MAX], TYPE[MAX];
    int CT[MAX], TAT[MAX], WT[MAX];
    int completed[MAX] = {0};
    float awt=0.0,atat=0.0;
    int time = 0, done = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        printf("PID AT BT TYPE: ");
        scanf("%d %d %d %d", &PID[i], &AT[i], &BT[i], &TYPE[i]);
    }

    while (done < n) {
        int idx = -1;

        for (int i = 0; i < n; i++) {
            if (!completed[i] && TYPE[i] == 0 && AT[i] <= time) {
                if (idx == -1 || AT[i] < AT[idx])
                    idx = i;
            }
        }


        if (idx == -1) {
            for (int i = 0; i < n; i++) {
                if (!completed[i] && TYPE[i] == 1 && AT[i] <= time) {
                    if (idx == -1 || AT[i] < AT[idx])
                        idx = i;
                }
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        time += BT[idx];
        CT[idx] = time;
        TAT[idx] = CT[idx] - AT[idx];
        WT[idx] = TAT[idx] - BT[idx];
        awt += WT[idx];
        atat += TAT[idx];
        completed[idx] = 1;
        done++;
    }

    printf("\nPID\tAT\tBT\tTYPE\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               PID[i], AT[i], BT[i], TYPE[i],
               CT[i], TAT[i], WT[i]);
    }
    printf("\nAverage waiting time is %f\n",awt/n);
    printf("Average Turn Around Time time is %f",atat/n);
    return 0;
}
