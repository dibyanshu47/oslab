#include <stdio.h>
#include <conio.h>
void main() {
	int bod, np, sb[20], sp[20], z[20], f[20], s = 0, i, j;
	clrscr();
	printf("\nEnter the number of blocks of division of memory: ");
	scanf("%d", &bod);
	printf("\nEnter the size of each block: ");
	for (i = 0; i < bod; i++) {
		scanf("%d", &sb[i]);
		z[i] = sb[i];
		f[i] = 0;
	}
	printf("\nEnter the number process: ");
	scanf("%d", &np);
	printf("\nEnter the size of each process: ");
	for (i = 0; i < np; i++) {
		scanf("%d", &sp[i]);
	}
	for (i = 0; i < np; i++) {
		for (j = 0; j < bod; j++) {
			if (sb[j] >= sp[i] && f[j] == 0) {
				printf("\nProcess %d is allocated to block %d", i, j);
				f[j] = 1;
				z[j] = sb[j] - sp[i];
				s++;
				goto l1;
			}
		}
		printf("\nProcess %d cannot be allocated", i);
l1:
	printf("");
	}
	printf("\nRemaining space left in each block");
	for (i = 0; i < bod; i++) {
		printf("\nBlock %d: %d", i, z[i]);
	}
	for (i = 0; i < bod; i++) {
		if (f[i] == 0) {
			printf("\nBlock %d is unallocated", i);
		}
	}
	if (s == bod) {
		printf("\nNo block is left unallocated");
	}
	getch();
}