#include <bits/stdc++.h> 
  
using namespace std; 
  
struct process { 
    int processno; 
    int AT; 
    int BT; 
  
    
    int BTbackup; 
    int WT; 
    int TAT; 
    int CT; 
}; 
  
struct process p[3]; 
  
int totaltime = 0; 
int prefinaltotal = 0; 
  
//sort() 
bool compare(process p1, process p2) 
{ 
    
    return p1.AT < p2.AT; 
} 
  
//largest Arrival Time 
int findlargest(int at) 
{ 
    int max = 0, i; 
    for (i = 0; i < 3; i++) { 
        if (p[i].AT <= at) { 
            if (p[i].BT > p[max].BT) 
                max = i; 
        } 
    } 
    return max; 
} 
// completion time of each process 
int findCT() 
{ 
  
    int index; 
    int flag = 0; 
    int i = p[0].AT; 
    while (1) { 
        if (i <= 4) { 
            index = findlargest(i); 
        } 
  
        else
            index = findlargest(4); 
        cout << "Process executing at time " << totaltime << " is: P" << index + 1 << "\t"; 
  
        p[index].BT -= 1; 
        totaltime += 1; 
        i++; 
  		
        if (p[index].BT == 0) { 
            p[index].CT = totaltime; 
            cout <<endl<< " Process " << p[index].processno  
                 << " is completed at " << totaltime<<endl; 
        } 
        cout << endl; 
  
        // loop termination condition 
        if (totaltime == prefinaltotal) 
            break; 
    } 
} 
  
int main() 
{ 
  
    int i; 
  
    // initializing the process number 
    for (i = 0; i < 3; i++) { 
        if(i==0)
		{
		p[i].processno = 2132 ; 
    	}
    	else if(i==1)
    	{
    		p[i].processno = 2102 ; 
		}
		else
		{
			p[i].processno = 2453 ; 
		}
	} 
  
    //As all the Students arriving at the same time so we Arrival time for all be 0  "; 
    for (i = 0; i < 3; i++) 
    { 
        p[i].AT = 0; 
    } 
  
    // Burst time of 3 process 
    for (i = 0; i < 3; i++) { 
        if(i==2)
	{
	p[i].BT=8;
	p[i].BTbackup = p[i].BT; 
        prefinaltotal += p[i].BT; 
	}
	else
	{
	p[i].BT = 2 * (i + 1); 
        p[i].BTbackup = p[i].BT; 
        prefinaltotal += p[i].BT; 
        }
} 
  
    // displaying the process before executing 
    cout << "PNo\tAT\tBT\n"; 
  
    for (i = 0; i < 3; i++) { 
        cout << p[i].processno << "\t"; 
        cout << p[i].AT << "\t"; 
        cout << p[i].BT << "\t"; 
        cout << endl; 
    } 
    cout << endl; 
  
    // soritng process according to Arrival Time 
    sort(p, p + 4, compare); 
  
    //initial time when execution starts 
    totaltime += p[0].AT; 
  
    // calculating to terminate loop 
    prefinaltotal += p[0].AT; 
    findCT(); 
    int totalWT = 0; 
    int totalTAT = 0; 
    for (i = 0; i < 3; i++) { 
        //as TAT = CT - AT 
        p[i].TAT = p[i].CT - p[i].AT; 
        p[i].WT = p[i].TAT - p[i].BTbackup; 

        totalWT += p[i].WT;  
        totalTAT += p[i].TAT; 
    } 
  
    cout << "After execution of all processes ... \n"; 

    cout << "PNo\tAT\tBT\tCT\tTAT\tWT\n"; 
  
    for (i = 0; i < 3; i++) { 
        cout << p[i].processno << "\t"; 
        cout << p[i].AT << "\t"; 
        cout << p[i].BTbackup << "\t"; 
        cout << p[i].CT << "\t"; 
        cout << p[i].TAT << "\t"; 
        cout << p[i].WT << "\t"; 
        cout << endl; 
    } 
  
    cout << endl; 
    
    cout << "Average TAT = " << totalTAT / 3.0 << endl; 
    cout << "Average WT = " << totalWT / 3.0 << endl; 
    return 0; 
}
