#include <stdio.h>
int main()
{    int n, m, i, j, k;
    printf("Enter number of processes -- ");
    scanf("%d", &n);
    printf("Enter number of resources -- ");
    scanf("%d", &m);
    int allocation[n][m], max[n][m], need[n][m];
    int available[m];
    // Input Allocation and Max
    for(i = 0; i < n; i++)
    {
        printf("\nEnter details for P%d\n", i);
        printf("Enter allocation -- ");
        for(j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
        printf("Enter Max -- ");
        for(j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    // Available Resources
    printf("\nEnter Available Resources -- ");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
    }
    // Calculate Need Matrix
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    // Request Details
    int pid, request[m];
    printf("\nEnter New Request Details -- \n");
    printf("Enter pid -- ");
    scanf("%d", &pid);
    printf("Enter Request for Resources -- ");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &request[i]);
    }
    // Check Request <= Need
    for(i = 0; i < m; i++)
    {
        if(request[i] > need[pid][i])
        {
            printf("Error: Process exceeded maximum claim\n");
            return 0;
        }
    }
    // Check Request <= Available
    for(i = 0; i < m; i++)
    {
        if(request[i] > available[i])
        {
            printf("Resources not available\n");
            return 0;
        }
    }
    // Pretend Allocation
    for(i = 0; i < m; i++)
    {
        available[i] -= request[i];
        allocation[pid][i] += request[i];
        need[pid][i] -= request[i];
    }
    // Safety Algorithm
    int finish[n], safe[n], work[m];
    int count = 0;
    for(i = 0; i < n; i++)
        finish[i] = 0;
    for(i = 0; i < m; i++)
        work[i] = available[i];
    while(count < n)
    {
        int found = 0;
        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int flag = 1;
                for(j = 0; j < m; j++)
                {
                    if(need[i][j] > work[j])
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag)
                {
                    printf("P%d is visited (", i);
                    for(k = 0; k < m; k++)
                    {
                        work[k] += allocation[i][k];
                        printf("%d", work[k]);
                        if(k != m - 1)
                            printf(" ");
                    }
                    printf(")\n");
                    safe[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if(found == 0)
            break;
    }
    // Safe State Check
    if(count == n)
    {
        printf("\nSYSTEM IS IN SAFE STATE\n");
        printf("The Safe Sequence is -- (");
        for(i = 0; i < n; i++)
        {
            printf("P%d", safe[i]);
            if(i != n - 1)
                printf(" ");
        }
        printf(")\n");
    }
    else
    {
        printf("\nSYSTEM IS NOT IN SAFE STATE\n");
    }
    // Display Table
    printf("\nProcess\tAllocation\tMax\t\tNeed\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t", i);
        for(j = 0; j < m; j++)
            printf("%d ", allocation[i][j]);
        printf("\t\t");
        for(j = 0; j < m; j++)
            printf("%d ", max[i][j]);
        printf("\t\t");
        for(j = 0; j < m; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }
    return 0;
}
