//implementation of FCFS IN C++ SCHEDULING (FIRST COME FIRST SERVE)
#include <iostream>

using namespace std;
void findWaitingTime(int processes[], int n, int bt[], int wt[]);
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]);
void findAverageTime(int processes[], int n, int bt[]);


//DRIVER CODE
int main()
{
	int num;
	cout<<"Enter how many process: ";
	cin>>num;
	//process id's
    int processes[num];
    int burst_time[num]; 
    int n = sizeof processes / sizeof processes[0];
    
    
    for(int i = 0; i < n; i++ )
	{
        cout<<"Enter processes: ";
        cin>>processes[i];
	}
	cout<<endl;	
	for(int i = 0; i < n; i++ )
	{
        cout<<"Enter Burst Time: ";
        cin>>burst_time[i];
	}
    
    
    //Burst time of all processes
    findAverageTime(processes, n,  burst_time);
    return 0;

}

void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
	//wait time for first process
	
	wt[0] = 0;
	
	//calculate waiting time
	
	for(int i = 1; i < n; i++) wt[i] = bt[i-1] + wt[i-1];
	
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
	//calculating turn around time by adding
	//bt and wt
	
	for(int i = 0; i < n; i++) tat[i] = bt[i] + wt[i];
}

void findAverageTime(int processes[], int n, int bt[])
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;
	
	//FUNCTION TO FIND WAITING TIME TO ALL PROCESS
	findWaitingTime(processes, n, bt, wt);
	//FUCTION TO FIND TURN AROUND TIME
	findTurnAroundTime(processes, n, bt, wt,tat);
	//DISPLAY PROCESS ALONG WITH ALL DETAILS
	cout<<"Process "<<"Burst Time "<<"Waiting Time "<<"Turn Around Time "<<endl;
	//Calculate total waiting time and TAT
	for(int i = 0; i < n; i++)
	{
	 	total_wt = total_wt + wt[i];
	 	total_tat = total_tat + tat[i];
	 	cout<<"  "<<processes[i]<<"\t\t"<<bt[i]<<"\t  "<<wt[i]<<"\t\t"<<tat[i]<<"\n";
	}
	
		cout<<"\nAverage waiting time = "<<(float)total_wt / (float)n;
		cout<<"\nAverage turn around time = "<<(float)total_tat / (float)n;	
}
