#include<stdio.h>
struct process
{
	int bursttime;
	int waitingtime;
	int turnaroundtime; 
};

int main()
{   int i,n;
float avgwaiting=0,avgturn=0;
	printf("Enter no.of processes:\n");
	scanf("%d",&n);
    struct process p[n];
	printf("Enter burst time:\n");
	for(i=0;i<n;i++){
		scanf("%d",&p[i].bursttime);
	}
	p[0].waitingtime=0;
	for(i=1;i<n;i++){
		p[i].waitingtime=p[i-1].waitingtime+p[i-1].bursttime;
		avgwaiting+=p[i].waitingtime;
	}
	for(i=0;i<n;i++){
		p[i].turnaroundtime=p[i].waitingtime+p[i].bursttime;
		avgturn+=p[i].turnaroundtime;
	}
	avgwaiting/=n;
	avgturn/=n;
	printf("Process \tBursttime\tWaitingtime\tTurnaroundtime\n");
	for(i=0;i<n;i++){
		printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,p[i].bursttime,p[i].waitingtime,p[i].turnaroundtime);
	}
	printf("Average waiting time:%f\n",avgwaiting);
	printf("Average turnaround time:%4f",avgturn);
}
