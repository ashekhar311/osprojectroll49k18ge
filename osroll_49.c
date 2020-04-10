#include<stdio.h>

int main()
{
    int bt[10],p[10],n,temp,i,j,wt[10],sum=0,at[10];
    float avg;
    printf("Enter total no of proces:");
    scanf("%d",&n);
    printf("\n Enter burst time for each process:-");
    for(i=0;i<n;i++)
    {
        printf("\nBurst time of process P%d:",i);
        scanf("%d",&bt[i]);
        p[i]=i;
    }
   printf("enter the arrival time for each process:-");
   for(i=0;i<n;i++)
   {
     printf("\narrival time of process P%d:",i);
        scanf("%d",&at[i]);
        p[i]=i;
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if((bt[i]>bt[j]) && (at[i]>at[j]))
            {
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
    }
    for(i=0;i<n;i++)
    {
        sum+=wt[i];
    }
    avg=(float)sum/n;
    printf("\n Waiting time for each process:-");
    for(i=0;i<n;i++)
    {
        printf("\n Waiting time for process P%d is %d sec.",p[i],wt[i]);

    }
    printf("\n Average waiting time is %f sec.",avg);
    int tat[10];
   printf("turnaround time for the processes:");
   for(i=0;i<n;i++)
   {
    tat[i]=wt[i]-at[i];
    printf("\nturnaround time of process P%d:",i);
       printf("%d",tat[i]);
        p[i]=i;
   }
    return 0;
}





