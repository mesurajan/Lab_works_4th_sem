//FCFS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to hold the process details
struct Process {
    int id;     // Process ID
    int bt;     // Burst Time
    int at;     // Arrival Time
    int ct;     // Completion Time
    int tat;    // Turnaround Time
    int wt;     // Waiting Time
    int rt;     // Response Time
};

// Function to display process details in tabular form
void displayTable(vector<Process>& processes) {
    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n";
    cout << "----------------------------------------------------\n";
    for (const auto& p : processes) {
        cout << "P" << p.id << "\t" 
             << p.at << "\t" 
             << p.bt << "\t" 
             << p.ct << "\t" 
             << p.tat << "\t" 
             << p.wt << "\t" 
             << p.rt << "\n";
    }
}

// Function to calculate CT, TAT, WT, and RT
void calculateTimes(vector<Process>& processes) {
    int currentTime = 0;
    
    // Sort processes based on arrival time
    sort(processes.begin(), processes.end(), [](Process& a, Process& b) {
        return a.at < b.at;
    });

    for (auto& p : processes) {
        // If CPU is idle, set currentTime to the next process's arrival time
        currentTime = max(currentTime, p.at);
        
        // Response Time = Current Time - Arrival Time (before the process starts)
        p.rt = currentTime - p.at;
        
        // Completion time = current time + burst time
        p.ct = currentTime + p.bt;
        
        // Turnaround time = completion time - arrival time
        p.tat = p.ct - p.at;
        
        // Waiting time = turnaround time - burst time
        p.wt = p.tat - p.bt;
        
        // Update current time
        currentTime = p.ct;
    }
}

int main() {
    int n;
    
    // Input number of processes
    cout << "Enter the number of processes: ";
    cin >> n;
    
    vector<Process> processes(n);
    
    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "Enter Arrival Time and Burst Time for Process " << i + 1 << ":\n";
        cout << "Arrival Time (AT): ";
        cin >> processes[i].at;
        cout << "Burst Time (BT): ";
        cin >> processes[i].bt;
    }
    
    // Calculate times
    calculateTimes(processes);
    
    // Display process details
    displayTable(processes);
    
    return 0;
}
