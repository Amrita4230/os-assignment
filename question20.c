#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<stdbool.h>
int st[3][4]={0};
void *teacher();
void *st1();
void *st2();
void *st3();
pthread_mutex_t lock;
int res1,res2;
int r1,r2;

int main()
{	

	pthread_mutex_init(&lock,NULL);\
st[1][1]=1;
	st[2][2]=2;st[3][3]=1;
	pthread_t t_thread;
	pthread_t s_thread;
printf("list of resources:");
printf(" enter your values assign with resources: \n 1 for pen resource  \n 2 for  paper \n 3 for question_paper");
	while(1)
{
if(st[1][4]==1 && st[2][4]==1 && st[3][4]==1){break;}
pthread_create(&t_thread, NULL, teacher, NULL);
pthread_join(t_thread,NULL);
	    
if((res1==1 && res2==2 || res2==1 && res1==2 ) && st[3][4]==0)
{
	pthread_create(&s_thread, NULL, st3, NULL);
	pthread_join(s_thread,NULL);
}
else if((res1==1 && res2==3 || res2==1 && res1==3 ) && st[2][4]==0)
{
pthread_create(&s_thread, NULL, st2, NULL);
	pthread_join(s_thread,NULL);
}
else if((res1==2 && res2==3 || res2==2 && res1==3 ) && st[1][4]==0)
{
	pthread_create(&s_thread, NULL, st1, NULL);
pthread_join(s_thread,NULL);
}
else
{
	printf("\n\t try again this choice can't be made'.\n");
}
}
printf("\n\t----Done---\n");
}


void *teacher()
{
pthread_mutex_lock(&lock);
	printf("\nFirst Resource :-\t");
	scanf("%d",&res1);
	printf("Second Resource:-\t");
	scanf("%d",&res2);
	pthread_mutex_unlock(&lock);
}

void *st2()
{	
	pthread_mutex_lock(&lock);
	printf("\nyour choices= 'pen', 'question_paper'\n");
	st[2][4]=1;
	printf("\n\tStudent 2 has Completed the assignment. \n");
	pthread_mutex_unlock(&lock);
}

void *st3()
{	
	pthread_mutex_lock(&lock);
	printf("\nyour choices= 'pen', 'paper'\n");
	st[3][4]=1;
	printf("\n\tStudent 3 has Completed the assignment.\n");
	pthread_mutex_unlock(&lock);
}

void *st1()
{	
	pthread_mutex_lock(&lock);
	printf("\nyour choices = 'paper', 'question_paper'\n");
	st[1][4]=1;
	printf("\n\tStudent 1 has Completed the assignment.\n");	
	pthread_mutex_unlock(&lock);
}




