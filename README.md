# philosophers
<h1 align="center">
	📖 Philosophers
</h1>

<p align="center">
	<b><i>Thread's processing, mutex and thread shared data.</i></b><br>
</p>

Philosophers is an individual 42 project about threading. The main learnings from this project are about the use of threads, mutex and thread's shared data. 


##Introduction
In computer science, the dining philosophers problem is an example problem often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them.

It was originally formulated in 1965 by Edsger Dijkstra as a student exam exercise, presented in terms of computers competing for access to tape drive peripherals. Soon after, Tony Hoare gave the problem its present formulation.

## The problem: 
A set of cutlery must be divided among the philosophers at the table. The number of cutlery is always less than the number of philosophers.

Philosophers have three actions: thinking, eating and sleeping. If the philosopher goes too long without eating, he dies and the simulation becomes invalid. 

Thus, each philosopher is a thread and the data set of each thread must be managed in parallel. 

Naturally, this is a computational parallelism project. 

## Installation 🖥
To test the project

```
git clone https://github.com/psydenst/philosophers
```
```
cd philosophers && make
```
Then run ./philo with arguments time_to_die, time_to_eat, time_to_sleep and, as non-required option, number_of_time_each_philosophers_must_eat

Ex: 
```
./philo 4 800 200 200 4
```
```
./philo 30 800 200 200
```
```
./philo 5 410 200 200 4
```



