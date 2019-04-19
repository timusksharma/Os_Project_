//C++ program for Calculating average waiting time and average turn around time. 
#include<stdio.h>
int n;
struct process
{

int p_no;

int arr_t,burst_t,ct,wait_t,taround_time,p;

int flag;
 }pro_lst[100];
 void Sorting()
 {
struct process p;

int i, j;

for(i=0;i<n-1;i++)

{

for(j=i+1;j<n;j++)

{

if(pro_lst[i].arr_t > pro_lst[j].arr_t)

{

p = pro_lst[i];

pro_lst[i] = pro_lst[j];

pro_lst[j] = p;

}

}

}
 }
 int main()
 {

int i,t=0,b_t=0,peak;

int a[10];

float wait_time = 0, taround_time = 0, avg_w_t=0, avg_t_time=0;

printf("Enter the no of Processes \n ");

scanf("%d",&n);

for(i = 0; i < n; i++)

{

pro_lst[i].p_no = i+1;

printf("\nEnter Details For P%d process:-\n", pro_lst[i].p_no);
printf("Enter Arrival Time: ");
scanf("%d", &pro_lst[i].arr_t );
printf("Enter Burst Time: ");
scanf("%d", &pro_lst[i].burst_t);
pro_lst[i].flag = 0;
b_t = b_t + pro_lst[i].burst_t;
}
Sorting();
for(int i=0;i<n;i++)
{
a[i]=pro_lst[i].burst_t;
}
pro_lst[9].burst_t = 9999;
for(t = pro_lst[0].arr_t; t <= b_t+1;)
{
peak = 9;
for(i=0;i<n;i++)
{
if(pro_lst[i].arr_t <= t && pro_lst[i].burst_t < pro_lst[peak].burst_t && pro_lst[i].flag != 1)
{
peak = i;
}
if(pro_lst[peak].burst_t==0 && pro_lst[i].flag != 1)
{
pro_lst[i].flag = 1;
pro_lst[peak].ct=t;pro_lst[peak].burst_t=9999;
printf("P%d Completes in %d\n",pro_lst[i].p_no,pro_lst[peak].ct);
}
}
t++;
(pro_lst[peak].burst_t)--;
}
for(i=0;i<n;i++)
{
pro_lst[i].taround_time=(pro_lst[i].ct)-(pro_lst[i].arr_t);
avg_t_time=avg_t_time+pro_lst[i].taround_time;
pro_lst[i].wait_t=((pro_lst[i].taround_time)-a[i]);
avg_w_t=avg_w_t+pro_lst[i].wait_t;
}
printf("PNO\tAT\tCT\tTA\tWTt\n");
for(i=0;i<n;i++)
{
printf("P%d\t%d\t%d\t%d\t%d\n",pro_lst[i].p_no,pro_lst[i].arr_t,pro_lst[i].ct,pro_lst[i].taround_time
,pro_lst[i].wait_t);
 }
printf("Average Turn ound Time: %f\t\n\n",avg_t_time);
printf("Average Waiting Time :\t %f\t\n",avg_w_t);
}
