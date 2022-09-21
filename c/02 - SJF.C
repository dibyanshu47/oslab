#include <stdio.h>
#include <conio.h>
void main() {
	int nop, wt[10], twt, tat[10], ttat, bt[10], i, j, t;
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
	for(i = 0; i < nop - 1; i++) {
		for(j = 0; j < nop - i - 1; j++) {
			if(bt[j] > bt[j + 1]) {
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
	printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
	for(i = 0; i < nop; i++) {
		printf("%d\t\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
	}
	printf("Total Waiting Time: %d\n", twt);
	printf("Total Turnaround Time: %d\n", ttat);
	printf("Average Waiting Time: %f\n", awt);
	printf("Average Turnaround Time: %f\n", atat);
	getch();
}