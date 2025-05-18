MiniOS – A Simple Command-Line Operating System 

About the Project

MiniOS is a basic simulation of an operating system designed for learning purposes. It runs in a command-line interface and supports multitasking, memory management, user and kernel modes, and launching external programs. This project demonstrates how operating systems manage tasks and memory using simple logic with multithreading and process control.

It is developed in C++ using POSIX threads (pthreads) and UNIX system calls like fork() and exec().

Features
Task Manager to track running programs

Multithreading with pthread_create

Forking and executing real external programs like a calculator or game

Memory management with basic RAM simulation

Interrupt-based user control (e.g. stop sleep with a keypress)

Support for User Mode and Kernel Mode

Menu-based interface for launching tasks

How It Works
Modes
User Mode: Allows running user programs like a calculator, guessing game, or calendar.

Kernel Mode: Allows running system-level tasks and viewing logs or managing memory.

Task Management
Each task is either a thread or a forked process.

A fixed-size memory array simulates RAM. Tasks are only launched if there’s enough memory.

Tasks are displayed in a queue showing their ID, name, memory usage, and status.

Menu Options
When you run MiniOS, a menu appears with the following options you'll see the Modulues:



Developed the following modules:
1.	Tic Tac Toe
2.	Move File
3.	Create File
4.	Display File Content
5.	Edit File
6.	File Information
7.	Background Song
8.	Current Date and Time
9.	Task Manager
10.	Instagram
11.	Calculator
12.	Guess Game
13.	Rock Paper Scissors
14.	Unit Converter
15.	Sleep
16.	Shutdown

Each option performs a specific task either in a new thread or process. Memory is checked before launching tasks.

Notes
This project is for learning multithreading, memory simulation, and basic OS concepts.

The memory is not real RAM, but a simulated array to understand allocation.

Do not launch too many tasks at once, as the memory limit is enforced manually.

The Task Manager is basic and can be extended to show more details or support suspending tasks.

Future Improvements
Add support for dynamic memory allocation and freeing

Implement priority-based task scheduling

Support file system simulation

Build a GUI version (optional)

Improve error handling and input validation

Developed by Hussain Ashraf, Naina Awan

Semester Project – Operating Systems

BSCS Program – 4th Semester

