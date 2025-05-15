#include <iostream>
#include <queue>
using namespace std;

struct Process {
    int id;
    int burstTime;
    int remainingTime;
};

void roundRobinScheduling(Process processes[], int n, int timeQuantum) {
    queue<int> readyQueue;
    int time = 0;
    int completedProcesses = 0;

    for (int i = 0; i < n; i++) {
        readyQueue.push(i);
    }

    while (completedProcesses < n) {
        int i = readyQueue.front();
        readyQueue.pop();

        if (processes[i].remainingTime > 0) {
            if (processes[i].remainingTime > timeQuantum) {
                time += timeQuantum;
                processes[i].remainingTime -= timeQuantum;
                readyQueue.push(i);
            } else {
                time += processes[i].remainingTime;
                processes[i].remainingTime = 0;
                completedProcesses++;
                cout << "Process P" << processes[i].id << " completed at time " << time << endl;
            }
        }
    }
}

int main() {
    int n = 5;
    Process processes[] = {{1, 5, 5}, {2, 3, 3}, {3, 1, 1}, {4, 2, 2}, {5, 3, 3}};
    int timeQuantum = 2;

    cout << "Round Robin Scheduling:" << endl;
    roundRobinScheduling(processes, n, timeQuantum);

    return 0;
}
