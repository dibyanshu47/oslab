#include <stdio.h>
#include <conio.h>
void main() {
	int ch, n = 5, b = 0, p = 0, c = 0;
	clrscr();
	printf("\nProducer Consumer");
	do {
		printf("\nMenu");
		printf("\n1. Produce an item");
		printf("\n2. Consume an item");
		printf("\n3. Add item to the buffer");
		printf("\n4. Display status");
		printf("\n5. Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1:
				p += 1;
				printf("\nItem produced");
				break;
			case 2:
				if(b != 0) {
					c += 1;
					b -= 1;
					printf("\nItem consumed");
				} else {
					printf("\nBuffer empty please wait");
				}
				break;
			case 3:
				if(b < n) {
					if(p != 0) {
						b += 1;
						printf("\nItem added to buffer");
					} else {
						printf("\nNo items to add");
					}
				} else {
					printf("\nBuffer full please wait");
				}
				break;
			case 4:
				printf("\nNumber of items produced: %d", p);
				printf("\nNumber of items consumed: %d", c);
				printf("\nNumber of items in buffer: %d", b);
				break;
			case 5:
				exit(0);
		}
	} while(ch < 6);
	getch();
}