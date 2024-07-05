#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int nprocesses = 0, nresources = 0;
vector<int> seq;

typedef struct {
    int id;
    vector<int> Max;        // 2D array Max[i,1] = k, means pi need max k instances of resource 1
    vector<int> Allocation; // 2D array Allocation[i,1] = k, means pi has k instances of resource 1
    vector<int> Need;       // 2D array Need[i,1] = k, means pi need k instances of resource 1 to start exec
    bool status;
} process;

bool IsSafe(vector<process>& processes, vector<int> available) {
    int finished = nprocesses;
    int j = 0;
    seq.clear();
    while (finished != 0) {
        int counter = finished;
        for (auto& p : processes) {
            if (p.status == false) {
                for (j = 0; j < nresources; j++)
                    if (p.Need[j] > available[j]) break;
                if (j == nresources) {
                    finished--;
                    p.status = true;
                    for (int k = 0; k < nresources; k++)
                        available[k] += p.Allocation[k];
                    seq.push_back(p.id);
                }
            }
        }
        if (counter == finished) {
            return false;
        }
    }
    return true;
}

bool Request(vector<process>& processes, vector<int> available, int p, vector<int> req) {
    int j = 0;
    for (j = 0; j < nresources; j++)
        if (req[j] > available[j] || req[j] > processes[p].Need[j]) break;
    if (j != nresources) return false;

    for (j = 0; j < nresources; j++) {
        processes[p].Allocation[j] += req[j];
        processes[p].Need[j] -= req[j];
        available[j] -= req[j];
    }

    // Print Need Matrix
    cout << "\n\tNeed Matrix";
    for (int j = -1; j < nprocesses; j++) {
        cout << endl;
        if (j == -1) {
            cout << "  \t";
            for (int i = 0; i < nresources; i++) {
                cout << "R" << i << "\t";
            }
            continue;
        }
        cout << "P" << j << "\t";
        for (int i = 0; i < nresources; i++)
            cout << processes[j].Need[i] << "\t";
    }
    cout << endl << endl;

    // Reset status flags for safety check
    for (auto& p : processes) {
        p.status = false;
    }
    return IsSafe(processes, available);
}

void deadlock(vector<process>& processes, vector<int>& available) {
    cout << "Handling deadlock by terminating the process consuming the most resources...\n";

    while (!IsSafe(processes, available)) {
        int maxResourceProcess = -1;
        int maxResources = -1;

        // Find the process consuming the most resources
        for (int i = 0; i < nprocesses; ++i) {
            int sumAllocations = 0;
            for (int k = 0; k < nresources; ++k) {
                sumAllocations += processes[i].Allocation[k];
            }
            if (sumAllocations > maxResources) {
                maxResources = sumAllocations;
                maxResourceProcess = i;
            }
        }

        if (maxResourceProcess != -1) {
            cout << "Process P" << maxResourceProcess << " terminated.\n";
            for (int k = 0; k < nresources; ++k) {
                available[k] += processes[maxResourceProcess].Allocation[k];
            }
            processes.erase(processes.begin() + maxResourceProcess);
            nprocesses--;

            // Reset status flags for safety check after termination
            for (auto& p : processes) {
                p.status = false;
            }
        }
        else {
            cout << "No process found with allocated resources. Unable to recover from deadlock.\n";
            break;
        }
    }
    cout << "Yes, Safe state <";
    for (int i = 0; i < seq.size(); i++) {
        cout << "P" << seq[i];
        if (i != seq.size() - 1) cout << ",";
        else cout << ">";
    }
    cout << ">\n";
}


int all() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    int choice;
    int p;
    char sysexit;
    do {
        cout << "Enter num of processes : ";
        cin >> nprocesses;
        cout << "\nEnter num of resources : ";
        cin >> nresources;
        cout << endl;

        seq.clear();
        vector<int> available(nresources);
        vector<process> processes(nprocesses);
        vector<int> req(nresources, 0);

        // Get Allocation Matrix
        for (int i = 0; i < nprocesses; i++) {
            processes[i].Max.resize(nresources);
            processes[i].Allocation.resize(nresources);
            processes[i].Need.resize(nresources);
            processes[i].id = i;
            processes[i].status = false;

            cout << "Enter Allocation array for P" << i << " : ";
            for (int j = 0; j < nresources; j++) {
                cin >> processes[i].Allocation[j];
            }
        }
        cout << endl;

        // Get Max Matrix
        for (int i = 0; i < nprocesses; i++) {
            cout << "Enter Max array for P" << i << " : ";
            for (int j = 0; j < nresources; j++) {
                cin >> processes[i].Max[j];
                processes[i].Need[j] = processes[i].Max[j] - processes[i].Allocation[j];
            }
        }

        // Get Available Matrix
        cout << "\nEnter Available array  " << endl;
        for (int j = 0; j < nresources; j++)
            cin >> available[j];

        // Print Need Matrix
        cout << "\n\tNeed Matrix";
        for (int j = -1; j < nprocesses; j++) {
            cout << endl;
            if (j == -1) {
                cout << "  \t";
                for (int i = 0; i < nresources; i++) {
                    cout << "R" << i << "\t";
                }
                continue;
            }
            cout << "P" << j << "\t";
            for (int i = 0; i < nresources; i++)
                cout << processes[j].Need[i] << "\t";
        }
        cout << endl;

        cout << "\nDo you want to check safety? (1-yes 2-no)\n";
        cout << "your choice : ";
        cin >> choice;
        if (choice == 1) {
            // Reset status flags for safety check
            for (auto& p : processes) {
                p.status = false;
            }
            if (IsSafe(processes, available)) {
                cout << "Yes, Safe state <";
                for (int i = 0; i < seq.size(); i++) {
                    cout << "P" << seq[i];
                    if (i != seq.size() - 1) cout << ",";
                    else cout << ">";
                }
                cout << "\n";
            }
            else {
                cout << "No, Deadlock\n";
            }
        }
        cout << endl;

        req.clear();
        req.resize(nresources, 0);
        cout << "\nDo you want to make a request? (1-yes 2-no)\n";
        cout << "your choice : ";
        cin >> choice;
        if (choice == 1) {
            cout << "enter index of process: ";
            cin >> p;
            cout << "enter request of process " << p << " : ";
            for (int i = 0; i < nresources; i++)
                cin >> req[i];
            if (Request(processes, available, p, req)) {
                cout << "Yes, Safe state <";
                cout << "P" << p << "req,";
                for (int i = 0; i < seq.size(); i++) {
                    cout << "P" << seq[i];
                    if (i != seq.size() - 1) cout << ",";
                    else cout << ">";
                }
                cout << "\n";
            }
            else {
                cout << "Deadlock present\n";
                deadlock(processes, available);
            }
        }

        cout << "\n\nDo you want to test again? (y/n)\n";
        cin >> sysexit;
    } while (sysexit == 'y' || sysexit == 'Y');

    return 0;
}
