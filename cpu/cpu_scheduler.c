#include <stdio.h>
#include <stdlib.h>

int main()
{//start main

printf("******* CPU SCHEDULER PROGRAM ********\n");
printf("******* @author: Kerri McMahon ********\n");


int running =0;
int a;

while(running !=9)

{//start while
printf("Pick an algorithm. press 1 for FCFS, 2 for SJF, 3 for RR -- Press 9 to quit\n");
scanf("%d", &a);

void fcfs();
void sjf();
void rr();


if (a==9)
{
exit(0);
}

if(a==1)
{
fcfs();

}
 if (a == 2)
{
sjf();
}
if (a == 3)
{
rr();
}
} //end while


return 0;


}//end main


void fcfs()
{//atart fcfs
printf("********** FIRST COME FIRST SERVE **********\n");
float burst_time[30], waiting_time[30], turnaround_time[30];
        float average_waiting_time = 0.0, average_turnaround_time = 0.0;
        int count, j, total_process;
        printf("Enter The Number of Processes To Execute:\t");
        scanf("%d", &total_process);
        printf("\nEnter The Burst Time of Processes:\n\n");
        for(count = 0; count < total_process; count++)
        {
                printf("Process [%d]:", count + 1);
                scanf("%f", &burst_time[count]);
        }
        waiting_time[0] = 0;   
        for(count = 1; count < total_process; count++)
        {
                waiting_time[count] = 0;
                for(j = 0; j < count; j++)
                {
                        waiting_time[count] = waiting_time[count] + burst_time[j];
                }
        }
        printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
        for(count = 0; count < total_process; count++)
        {
                turnaround_time[count] = burst_time[count] + waiting_time[count];
                average_waiting_time = average_waiting_time + waiting_time[count];
                average_turnaround_time = average_turnaround_time + turnaround_time[count];
                printf("\nProcess [%d]\t\t%.2f\t\t%.2f\t\t%.2f", count + 1, burst_time[count], waiting_time[count], turnaround_time[count]);
        }
        printf("\n");
        average_waiting_time = average_waiting_time / count;
        average_turnaround_time = average_turnaround_time / count;
        printf("\nAverage Waiting Time = %f", average_waiting_time);
        printf("\nAverage Turnaround Time = %f", average_turnaround_time);
        printf("\n");

}//end fcfs



void sjf()
{//start sjf
printf("********** SHORTEST JOB FIRST **********\n");
int temp, i, j, limit, sum = 0, position;
      float average_wait_time, average_turnaround_time;
      int burst_time[20], process[20], waiting_time[20], turnaround_time[20];
      printf("\nEnter Total Number of Processes:\t");
      scanf("%d", &limit); 
      for(i = 0; i < limit; i++)
      {
            printf("Enter Burst Time For Process[%d]:\t", i + 1);
            scanf("%d", &burst_time[i]);
            process[i] = i + 1;
      }
      for(i = 0; i < limit; i++)
      {
            position = i;
            for(j = i + 1; j < limit; j++)
            {
                  if(burst_time[j] < burst_time[position])
                  {
                        position = j;
                  }
            }
            temp = burst_time[i];
            burst_time[i] = burst_time[position];
            burst_time[position] = temp;
            temp = process[i];
            process[i] = process[position];
            process[position] = temp;
      } 
      waiting_time[0] = 0;
      for(i = 1; i < limit; i++)
      {
            waiting_time[i] = 0;
            for(j = 0; j < i; j++)
            {
                  waiting_time[i] = waiting_time[i] + burst_time[j];
            } 
            sum = sum + waiting_time[i];
      }
      average_wait_time = (float)sum / limit;
      sum = 0;
      printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
      for(i = 0; i < limit; i++)
      {
            turnaround_time[i] = burst_time[i] + waiting_time[i];
            sum = sum + turnaround_time[i];
            printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\n", process[i], burst_time[i], waiting_time[i], turnaround_time[i]);
      }
      average_turnaround_time = (float)sum / limit;
      printf("\nAverage Waiting Time:\t%f\n", average_wait_time);
      printf("\nAverage Turnaround Time:\t%f\n", average_turnaround_time);

}//end sjf



void rr()
{
printf("********** ROUND ROBIN **********\n");




int i, limit, total = 0, x, counter = 0, time_quantum; 
      int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10]; 
      float average_wait_time, average_turnaround_time;
      printf("\nEnter Total Number of Processes:\t"); 
      scanf("%d", &limit); 
      x = limit; 
      for(i = 0; i < limit; i++) 
      {
            printf("\nEnter Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &arrival_time[i]);
            printf("Burst Time:\t");
            scanf("%d", &burst_time[i]); 
            temp[i] = burst_time[i];
      } 
      printf("\nEnter Time Quantum:\t"); 
      scanf("%d", &time_quantum); 
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;) 
      { 
            if(temp[i] <= time_quantum && temp[i] > 0) 
            { 
                  total = total + temp[i]; 
                  temp[i] = 0; 
                  counter = 1; 
            } 
            else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - time_quantum; 
                  total = total + time_quantum; 
            } 
            if(temp[i] == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
                  wait_time = wait_time + total - arrival_time[i] - burst_time[i]; 
                  turnaround_time = turnaround_time + total - arrival_time[i]; 
                  counter = 0; 
            } 
            if(i == limit - 1) 
            {
                  i = 0; 
            }
            else if(arrival_time[i + 1] <= total) 
            {
                  i++;
            }
            else 
            {
                  i = 0;
            }
      } 
      average_wait_time = wait_time * 1.0 / limit;
      average_turnaround_time = turnaround_time * 1.0 / limit;
      printf("\n\nAverage Waiting Time:\t%f", average_wait_time); 
      printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time); 
      



}//end rr
