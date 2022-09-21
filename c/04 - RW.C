#include <stdio.h>
#include <conio.h>
void main() {
	typedef int semaphore;
	semaphore sread = 0, swrite = 0;
	int ch, r = 0;
	clrscr();
	printf("\nReaders Writers\n");
	do {
		printf("\nMenu");
		printf("\n\t1. Read from file");
		printf("\n\t2. Write to file");
		printf("\n\t3. Exit the reader");
		printf("\n\t4. Exit the writer");
		printf("\n\t5. Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1:
				if(swrite == 0) {
					sread = 1;
					r += 1;
					printf("\nReader %d reads", r);
				} else {
					printf("\nCannot read while writer wrties the file");
				}
				break;
			case 2:
				if(sread == 0 && swrite == 0) {
					swrite = 1;
					printf("\nWriter in progress");
				} else if(swrite == 1) {
					printf("\nWriter writes the file");
				} else if(sread == 1) {
					printf("\nCannot write while reader reads the file");
				} else {
					printf("\nCannot write file");
				}
				break;
			case 3:
				if(r != 0) {
					printf("\nThe reader %d closes the file", r);
					r -= 1;
				} 
				if(r == 0) {
					printf("\nCurrently no reader access the file");
					sread = 0;
				} else if(r == 1) {
					printf("\nOnly one reader is reading the file");
				} else {
					printf("\n%d readers are reading the file", r);
				}
				break;
			case 4:
				if(swrite == 1) {
					printf("\nWriter closes the file");
					swrite = 0;
				} else {
					printf("\nThere is no writer in the file");
				}
				break;
			case 5:
				exit(0);
		}
	} while(ch < 6);
	getch();
}