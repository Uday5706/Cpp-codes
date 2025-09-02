#include <bits/stdc++.h>
using namespace std;

int tat(vector<vector<int>> processes, int i){
    return processes[i][2]-processes[i][0];
}

int wt(vector<vector<int>> processes, int i){
    return tat(processes,i)-processes[i][1];
}

int main() {
    vector<vector<int>> processes;
    int n;
    cout<<"Enter Number of processes to Push: ";
    cin>>n;
    for (int i=0;i<n;i++){///make it dynmanic input
        int at, bt;
        cout<<"Enter arrival time for process "<<i+1<<": ";
        cin>>at;
        cout<<"Enter burst time for process "<<i+1<<": ";
        cin>>bt;
        processes.push_back({at, bt});
    }
    sort(processes.begin(), processes.end()); // processes sorted on arrival time
    int t=0;
    for (auto& process:processes){
        if (process[0]>t) t=process[0];
        t+=process[1];
        process.push_back(t); // Completion time
    }

    // Print table header
    cout << left << setw(10) << "Process"
         << setw(15) << "Arrival Time"
         << setw(12) << "Burst Time"
         << setw(17) << "Completion Time"
         << setw(15) << "TAT"
         << setw(15) << "WT" << endl;
    cout << string(84, '-') << endl;

    // Print process details
    for (int i = 0; i < processes.size(); ++i) {
        int arrival = processes[i][0];
        int burst = processes[i][1];
        int completion = processes[i][2];
        int turnaround = tat(processes, i);
        int waiting = wt(processes, i);
        cout << left << setw(10) << i+1
             << setw(15) << arrival
             << setw(12) << burst
             << setw(17) << completion
             << setw(15) << turnaround
             << setw(15) << waiting << endl;
    }
    return 0;
}
//Implement SJF scheduling algorithm (shortest job first)