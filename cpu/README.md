CPU Scheduler Program - Readme File
@author: Kerri McMahon

Welcome to my CPU Scheduling Simulation Program. Some brief things to note:

- - ASSUMPTIONS - -   
Maximum amount of process that can be considered is 10 for each algorithm.
Random burst time generation maximum is 20.

- In Round Robin Algorithm, I have incorporated consideration for the arrival times into the program. I was not sure if
this was required, so I did it however there is also an option to initialize all arrival times to 0.

- Random burst times initialized by time of day, rand() function in standard C library

- - PURPOSE - -
 
My program consists of:

-int main() function
-Purpose: to control program flow

-void fcfs() function
-Purpose: to perform First Come First Serve Algorithm

-void sjf() function
-Purpose: to perform Shortest Job First Algorithm

-void rr() function
-Purpose: to perform Round Robin Algorithm

-My program does NOT include a header (.h) file, as it was not necessary.





How to use my program:

-Choose which algorithm you would like to simulate
- Press 1 for First Come First Serve
- Press 2 for Shortest Job First
- Press 3 for Round Robin


-If you choose FCFS:
-Press Y or N if you would like randomized burst times
- If N, you will be asked to manually input them

-If you are in SJF:
-Press Y or N if you would like randomized burst times
- If N, you will be asked to manually input them

-If you are in RR:
-Press Y or N if you would like to consider arrival times
-if N, all arrival times will be initialized to 0. If Y, you will be asked to input them manually
-Enter a time quantum

-Press 9 to exit the program after execution





