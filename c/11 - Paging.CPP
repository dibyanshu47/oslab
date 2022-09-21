#include<iostream>
using namespace std;
struct paging
{
	int frameNumber, valid;
};
int main()
{
	int noOfPages = 0, baseAddress = 0, noOfFrames = 0, sizeOfMM = 0, sizeOfLM = 0, FrameSize = 0, physicalAddress = 0, disp = 0, pageNo = 0, logicalAddress = 0, i;
	paging pageTable[10], frameTable[10];
	// clrscr();
	cout << "Program for Paging techniques - Fixed Size partition";
	cout << "\n\nEnter the base address of physical memory:";
	cin >> baseAddress;
	cout << "\nEnter the size of Main Memory:";
	cin >> sizeOfMM;
	cout << "\nEnter the size of Main Memory Frame:";
	cin >> FrameSize;
	noOfFrames = sizeOfMM / FrameSize;
	cout << "\nTotal no. of frames in Main Memory is " << noOfFrames;
	cout << "\n Enter the size of Logical Memory:";
	cin >> sizeOfLM;
	noOfPages = sizeOfLM / FrameSize;
	cout << "\n Total no. of pages in Logical Memory is " << noOfPages;
	cout << "\n Enter the frame values in Page Table\n";
	for (int i = 0; i < noOfPages; i++)
	{
		while (1)
		{
			cout << "\n Page " << i << " is stored in frame number:";
			cin >> pageTable[i].frameNumber;
			pageTable[pageTable[i].frameNumber].valid = 1;
			frameTable[pageTable[i].frameNumber].valid = i;
			break;
		}
	}
	cout << "\n \t PAGE TABLE";
	cout << "\nIndex|\t\tFrame Number|\tValid_Bit|\n\n";
	for (i = 0; i < noOfPages; i++)
	{
		cout << i << "\t\t" << pageTable[i].frameNumber << "\t\t" << pageTable[pageTable[i].frameNumber].valid << "\t\n";
	}

	for (i = 0; i < noOfPages; i++)
	{
		cout << "Enter the logical addresss for mapping process:";
		cin >> logicalAddress;
		pageNo = logicalAddress / FrameSize;
		disp = logicalAddress % FrameSize;
		physicalAddress =  baseAddress + ((pageTable[pageNo].frameNumber - 1) * FrameSize) + disp;
		cout << "Physical Address value is " << physicalAddress << "\n";
	}
	return 0;
}
