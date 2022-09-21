#include<stdio.h>
struct paging
{
	int frameNumber, valid;
};
int main()
{
	int noOfPages = 0, baseAddress = 0, noOfFrames = 0, sizeOfMM = 0, sizeOfLM = 0, FrameSize = 0, physicalAddress = 0, disp = 0, pageNo = 0, logicalAddress = 0, i;
	paging pageTable[10], frameTable[10];
	printf("Program for Paging techniques - Fixed Size partition");
	printf("\n\nEnter the base address of physical memory: ");
	scanf("%d", &baseAddress);
	printf("\nEnter the size of Main Memory: ");
	scanf("%d", &sizeOfMM);
	printf("\nEnter the size of Main Memory Frame: ");
	scanf("%d", &FrameSize);
	noOfFrames = sizeOfMM / FrameSize;
	printf("\nTotal no. of frames in Main Memory is %d", noOfFrames);
	printf("\n Enter the size of Logical Memory: ");
	scanf("%d", &sizeOfLM);
	noOfPages = sizeOfLM / FrameSize;
	printf("\n Total no. of pages in Logical Memory is %d", noOfPages);
	printf("\n Enter the frame values in Page Table\n");
	for (int i = 0; i < noOfPages; i++)
	{
		while (1)
		{
			printf("\n Page %d is stored in frame number:", i);
			scanf("%d", pageTable[i].frameNumber);
			pageTable[pageTable[i].frameNumber].valid = 1;
			frameTable[pageTable[i].frameNumber].valid = i;
			break;
		}
	}
	printf("\n \t PAGE TABLE");
	printf("\nIndex|\t\tFrame Number|\tValid_Bit|\n\n");
	for (i = 0; i < noOfPages; i++)
	{
		printf("%d\t\t%d\t\t%d\n", i, pageTable[i].frameNumber, pageTable[pageTable[i].frameNumber].valid);
	}

	for (i = 0; i < noOfPages; i++)
	{
		printf("Enter the logical addresss for mapping process:");
		scanf("%d", &logicalAddress);
		pageNo = logicalAddress / FrameSize;
		disp = logicalAddress % FrameSize;
		physicalAddress =  baseAddress + ((pageTable[pageNo].frameNumber - 1) * FrameSize) + disp;
		printf("Physical Address value is %d\n", physicalAddress);
	}
	return 0;
}
