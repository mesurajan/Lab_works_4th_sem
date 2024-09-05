//SJF
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to hold process details
struct Process {
    int id;     // Process ID
    int bt;     // Burst Time
    int at;     // Arrival Time
    int ct;     // Completion Time
    int tat;    // Turnaround Time
    int wt;     // Waiting Time
    int rt;     // Response Time
    bool completed;  // Whether the process is completed
};

// Function to display process details in tabular form
void displayTable(vector<Process>& processes) {
    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n";
    cout << "-----------------------------------------------------------\n";
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

// Function to calculate CT, TAT, WT, and RT using SJF (non-preemptive)
void calculateTimes(vector<Process>& processes) {
    int n = processes.size();
    int currentTime = 0, completedProcesses = 0;

    while (completedProcesses < n) {
        // Find the process with the shortest burst time that has arrived and is not completed
        int shortestJobIndex = -1;
        for (int i = 0; i < n; i++) {
            if (!processes[i].completed && processes[i].at <= currentTime) {
                if (shortestJobIndex == -1 || processes[i].bt < processes[shortestJobIndex].bt) {
                    shortestJobIndex = i;
                }
            }
        }

        if (shortestJobIndex != -1) {
            Process& p = processes[shortestJobIndex];

            // Response Time = Current Time - Arrival Time (for the first time the process is executed)
            p.rt = currentTime - p.at;

            // Completion Time = Current Time + Burst Time
            p.ct = currentTime + p.bt;

            // Turnaround Time = Completion Time - Arrival Time
            p.tat = p.ct - p.at;

            // Waiting Time = Turnaround Time - Burst Time
            p.wt = p.tat - p.bt;

            // Mark the process as completed
            p.completed = true;
            completedProcesses++;

            // Move the current time forward
            currentTime = p.ct;
        } else {
            // If no process has arrived yet, move the current time forward
            currentTime++;
        }
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
        processes[i].completed = false; // Initially, no process is completed
    }

    // Calculate times using SJF (non-preemptive)
    calculateTimes(processes);

    // Display process details
    displayTable(processes);

    return 0;
}
