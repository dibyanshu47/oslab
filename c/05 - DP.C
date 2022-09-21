#include <stdio.h>
#include <conio.h>
#define LEFT (i + 4) % 5
#define RIGHT (i + 1) % 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
int state[5];
void put_forks(int);
void test(int);
void take_forks(int);
void philosopher(int i) {
	if(state[i] == THINKING) {
		take_forks(i);
		if(state[i] == EATING) {
			printf("\nEating in progress...");
		}
		put_forks(i);
	}
}
void take_forks(int i) {
	state[i] = HUNGRY;
	test(i);
}
void put_forks(int i) {
	state[i] = THINKING;
	printf("\nPhilosopher %d completed its work", i);
	test(LEFT);
	test(RIGHT);
}
void test(int i) {
	if(state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
		printf("\nPhilosopher %d can eat", i);
		state[i] = EATING;
	}
}
void main() {
	int i;
	clrscr();
	for(i = 0; i < 5; i++)
		state[i] = 0;
	printf("\n\t\t\t Dining Philosopher Problem");
	printf("\n\t\t....");
	for(i = 0; i < 5; i++) {
		printf("\nThe philosopher %d falls hungry\n", i);
		philosopher(i);
	}
	getch();
}