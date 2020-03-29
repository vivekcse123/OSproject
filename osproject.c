//preority sheduler
#include<stdio.h>
int main()
{
	int brust_time[50],waiting_time[50],priority[50],turn_around_time[50],p[50],i,j,n,temp,pos,total=0,AWT,ATT;
	printf("Enter total number of process;\n");
	scanf("%d",&n);
	printf("Enter brust time nad perority;\n");
	for(i=0; i<n; i++)
	{
		printf("\np[%d]\n",i+1);
		printf("Brust time:");
		scanf("%d",&brust_time[i]);
		printf("priority:");
		scanf("%d",&priority);
		p[i]=i+1;
	}
	for(i=0; i<n; i++)
	{
		pos=i;
		for(j=0; j<n; j++)
		{
			if(priority[j]<priority[pos])
			pos=j;
		}
		temp=priority[i];
		priority[i]=priority[pos];
		priority[pos]=temp;
		
		temp=brust_time[i];
		brust_time[i]=brust_time[pos];
		brust_time[pos]=temp;
		
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;
	}
	waiting_time[0]=0;
	for(i=1; i<n; i++)
	{
		waiting_time[i]=0;
		for(j=0; j<i; j++)
		waiting_time[i]+=brust_time[j];
		total=waiting_time[i];
		}
		AWT=total/n;
		total=0;
		printf("\nProcess\t Brust_time\t Waiting_time\tTurn_round_time");
		for(i=0; i<n; i++)
		{
			turn_around_time[i]=brust_time[i]+waiting_time[i];
			total=turn_around_time[i];
			printf("\np[%d]\t\t %d \t\t %d\t\t%d",p[i],brust_time[i],waiting_time[i],turn_around_time[i]);
			
		}
		ATT=total/n;
		printf("\nAverage waiting_time:%d",AWT);
		printf("\nAverage turn_around_time:%d",ATT);
}
