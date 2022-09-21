#include <stdio.h>
#include <conio.h>
void main() {
	int nop, wt[10], twt, tat[10], ttat, p[10], bt[10], i, j, t;
	float awt, atat;
	clrscr();
	awt = 0.0;
	atat = 0.0;
	printf("Enter the number of process: ");
	scanf("%d", &nop);
	for(i = 0; i < nop; i++) {
		printf("Enter the burst time for process %d: ", i);
		scanf("%d", &bt[i]);
	}
	for(i = 0; i < nop; i++) {
		printf("Enter the priority for process %d: ", i);
		scanf("%d", &p[i]);
	}
	for(i = 0; i < nop - 1; i++) {
		for(j = 0; j < nop - i - 1; j++) {
			if(p[j] > p[j + 1]) {
				t = p[j];
				p[j] = p[j + 1];
				p[j + 1] = t;
				t = bt[j];
				bt[j] = bt[j + 1];
				bt[j + 1] = t;
			}
		}
	}
	wt[0] = 0;
	tat[0] = bt[0];
	twt = wt[0];
	ttat = tat[0];
	for(i = 1; i < nop; i++) {
		wt[i] = wt[i - 1] + bt[i - 1];
		tat[i] = wt[i] + bt[i];
		twt += wt[i];
		ttat += tat[i];
	}
	awt = (float)twt / nop;
	atat = (float)ttat / nop;
	printf("\nProcess\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
	for(i = 0; i < nop; i++) {
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, p[i], bt[i], wt[i], tat[i]);
	}
	printf("\nTotal Waiting Time: %d\n", twt);
	printf("\nTotal Turnaround Time: %d\n", ttat);
	printf("\nAverage Waiting Time: %f\n", awt);
	printf("\nAverage Turnaround Time: %f\n", atat);
	getch();
}