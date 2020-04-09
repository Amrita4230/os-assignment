#include<stdio.h>
 void allocatepriority(int *pid,int n) //function defination
 {int i;
	printf("1 second =1000ms\n if response time is <1000 milisecond then process is interactive otherwise non interactive");
	printf("\n\nPROCESS ID \t RESPONSE-TIME(IN MS) \t\tPROCESS TYPE \t\tPRIORITY : ");
		for(i=0;i<n;i++)
	{
		printf("\nP(%d)\t\t %d\tms \t",i,pid[i]);
		if(pid[i]<1000)
		{
			printf("\t\tInteractive\t\thigh");
		}
		else
{    printf("\t\tnon-Interactive\t\tlow");  }
}
}	
int main()
{
	int j,n;
	printf("Enter total no. of process ");
    scanf("%d",&n);
	int responsetime[n];
	printf("Enter the values:\n");
	for(j=0;j<n;j++)
	{
		printf("Response time of Process id p(%d) (in milliseconds): ",j);
		scanf("%d",&responsetime[j]);	
	}
	allocatepriority(responsetime,n); //function calling
}
