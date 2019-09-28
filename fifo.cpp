//implementation of first come first serve algorithm using cpp
/*here pid means program ids,bt means burst time,at means arrival time,
  tat means turn around time,ct means completion time,wt means waiting 
  time,rt means response time.
*/
/*logic used
  ct[i]=bt[i]+ct[i-1];
  tat[i]=ct[i]-at[i];
  wt[i]=tat[i]-bt[i];
  rt[i]=ct[i-1];
*/
//this logic statisfy every condition.
#include<iostream>
using namespace std;
int main()
{
    int n,i;
    cout<<"enter no of processes"<<endl;
    cin>>n;
    int sum1=0,sum2=0;//for calculation total wt and tat .
    float awt=0.0,atat=0.0;//for storing avg wt and tat.
    int pid[n],at[n],bt[n],tat[n],ct[n],wt[n],rt[n];
    cout<<"enter program id's"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>pid[i];
    }
    cout<<"enter arrival times"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>at[i];
    }
    cout<<"enter burst times"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>bt[i];
    }
    int j;
    //sorting pid's,bt,at based on arival time.
    for(i=0;i<n;i++)
    {
        int t;
        for(j=i+1;j<n;j++)
        {
            if(at[i]>at[j])
            {
                t=at[i];at[i]=at[j];at[j]=t;
                t=bt[i];bt[i]=bt[j];bt[j]=t;
                t=pid[i];pid[i]=pid[j];pid[j]=t;
            }
        }
    }
    //calculation of ct
    for(i=0;i<n;i++)
    {
        if(i==0)
            ct[0]=bt[0]+at[0];
        else
        {
            if((at[i]-at[i-1]>1)&&(ct[i-1]<at[i]))
                ct[i]=bt[i]+at[i] ;
            else
                ct[i]=ct[i-1]+bt[i];
        }
    }
    //calculation wt ,tat, rt
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        sum1=sum1+tat[i];
        wt[i]=tat[i]-bt[i];
        sum2=sum2+wt[i];
        if(i==0)
            rt[0]=at[0];
        else
        {
            if((at[i]-at[i-1]>1)&&(ct[i-1]<at[i]))
                rt[i]=at[i];
            else
            {
                rt[i]=ct[i-1];
            }
            
        }
    }
    awt=(float)sum2/n;
    atat=(float)sum1/n;
    //displaying all values
    cout<<"pid \t at \t bt \t ct \t tat \t wt \t rt \n";
    for(i=0;i<n;i++)
    {
        cout<<pid[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t";
        cout<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<"\t";
        cout<<rt[i]<<"\n";
    }
    cout<<endl;
    cout<<"the average waiting time is "<<awt<<endl;
    cout<<"the average turnaround time is"<<atat<<endl;
}