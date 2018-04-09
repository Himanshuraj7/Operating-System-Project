#include<stdio.h>
#include<stdlib.h> 
 
int main() 
{ 
      int i, limit, total = 0, x, counter = 0, time_quantum,j; 
      int wait_time = 0, turnaround_time = 0,pos,z,p[10],prio[10], arrival_time[10], burst_time[10], temp[10],b; 
      float average_wait_time, average_turnaround_time;
      printf("\nEnter Total Number of Processes:\t");
      scanf("%d", &limit); 
      if(limit<=0){
        goto process_boundry;
      }
      x = limit; 
      for(i = 0; i < limit; i++) 
      {
          p[i]=i+1;
          prio[i]=0;
            printf("\nEnter Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &arrival_time[i]);
      if(arrival_time[i]<0){
        goto arrival_boundry;
       }
            printf("Burst Time:\t");
            scanf("%d", &burst_time[i]); 
      if(burst_time[i]<=0){
        goto burst_boundry;
      }
            temp[i] = burst_time[i];
      } 
      printf("\nEnter Time Quantum:\t"); 
      scanf("%d", &time_quantum);
      if(time_quantum<=0){
        goto time_boundry;
      } 
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\t Priority\n");
      for(total = 0, i = 0; x != 0;) 
      { 

                for(z=0;z<limit;z++)
                {
                  int temp1;
                  pos=z;
                  for(j=z+1;j<limit;j++)
                  {
                      if(prio[j]<prio[pos])
                        pos=j;
                  }
             
                  temp1=prio[z];
                  prio[z]=prio[pos];
                  prio[pos]=temp1;
             
                  temp1=burst_time[z];
                  burst_time[z]=burst_time[pos];
                  burst_time[pos]=temp1;
                  
                  temp1=arrival_time[z];
                  arrival_time[z]=arrival_time[pos];
                  arrival_time[pos]=temp1;

                  temp1=p[z];
                  p[z]=p[pos];
                  p[pos]=temp1;

                  temp1=temp[z];
                  temp[z]=temp[pos];
                  temp[pos]=temp1;
                }
            
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
      for(b=0;b<limit;b++)
            {
                  if(b==i)
                  prio[b]+=1;
                  else
                  prio[b]+=2;
            }
            if(temp[i] == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d\t\t\t %d", p[i], burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i],prio[i]);
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

exit(0);
      process_boundry:
        printf("not a valid process number");
              printf("\n");
exit(0);
      arrival_boundry:
        printf("not a valid arrival time");
              printf("\n");
exit(0);
      burst_boundry:
        printf("not a valid burst time");
              printf("\n");
exit(0);
      time_boundry:
        printf("not a valid time quantum");
              printf("\n"); 
}