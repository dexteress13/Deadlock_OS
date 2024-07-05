Deadlock Detection & Recovery Tool in C++

Objectives:
The main objective of this project is to develop a tool with GUI that can:

•	Detect deadlock situations in a system.
•	Utilize Banker's Algorithm to determine if a system is in a safe state.
•	Recover from deadlock situations by releasing resources.

Related Topic/Chapter in theory class:
-Deadlock Management
-Banker’s Algorithm
-Deadlock Recovery

Hardware/Software required:
Hardware: PC
Software Tool: Visual Studio

Implementation Details:
Banker's Algorithm:
Banker's Algorithm is used to ensure a system remains in a safe state by analyzing resource allocation requests. It checks whether granting a request will lead to deadlock or not.

Graphical User Interface (GUI):
The tool incorporates a GUI to enhance user interaction and visualization. The GUI provides the following features:
•	Display of process information, resource allocation, and current system state.
•	Buttons for initiating deadlock detection, resource request simulation, and recovery procedures.
•	Real-time updates of system status and deadlock incidents.

Features:
Process and Resource Management: Users can input the number of processes and resources, along with their allocation and maximum requirements.
Deadlock Detection: The tool periodically scans the system to detect potential deadlock situations by analyzing the resource allocation graph.
Resource Request Simulation: Users can simulate resource requests by processes and observe the impact on system safety.
Deadlock Recovery: In the event of a deadlock, the tool automatically initiates recovery procedures by terminating processes to release resources.
