#include<stdio.h>
#include<conio.h>
int np, nr, r[10], safe[10], ava[10], aval[10], f[10], i, j, flag, z, index;
int m[10][10], need[10][10], all[10][10];
void resourse()
{
	printf("\nEnter the no. of resourses: ");
	scanf("%d", &nr);
	printf("\nEnter the resources instances \n");
	for (i = 0; i < nr; i++)
		scanf("%d", &r[i]);
}
void alloc()
{
	printf("\nEnter the no of process: ");
	scanf("%d", &np);
	for (i = 0; i < np; i++)
	{
		f[i] = 0;
		for (j = 0; j < nr; j++)
		{
			printf("\n Resourse %d for %d  ", j + 1, i + 1);
			scanf("%d", &all[i][j]);
		}
	}
}
void maxreq()
{
	printf("\nEnter the maximum request for each process \n");
	for (i = 0; i < np; i++)
		for (j = 0; j < nr; j++)
			scanf("%d", &m[i][j]);
	printf("\nThe Available Matrix\n");
	printf("----------------------\n");
	for (i = 0; i < nr; i++)
	{
		z = 0;
		for (j = 0; j < np; j++)
			z += all[j][i];
		ava[i] = r[i] - z;
		printf("%d\t", ava[i]);
		aval[i] = ava[i];
	}
}
void needcal()
{
	printf("\n");
	printf("\nThe Need Matrix \n");
	printf("-------------------\n");
	for (i = 0; i < np; i++)
	{
		printf("\n");
		for (j = 0; j < nr; j++)
		{
			need[i][j] = m[i][j] - all[i][j];
			printf("%d\t", need[i][j]);
		}
	}
	printf("\n\n");
}
void out()
{
	printf("The safe sequensce is\n");
	for (i = 0; i < np; i++)
		printf("p[%d]\t", safe[i]);
	printf("\n\n");
}
void safety()
{
	flag = 0; i = 0; j = 0; z = 0; index = 0;
	while (1)
	{
		if (z++ > 2 * np)
		{
			printf("\n no safe sequence");
			exit(0);
		}
		for (j = 0; j < nr; j++)
		{
			if (need[i][j] <= ava[j] && f[i] != 1)
			{
				flag = 0;
			}
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			f[i] = 1;
			safe[index] = i;
			for (j = 0; j < nr; j++)
				ava[j] += all[i][j];
			index++;
			if (index >= np)
				return;
		}
		i++;
		if (i >= np)
			i = 0;
	}
}
void main()
{
	clrscr();
	resourse();
	alloc();
	maxreq();
	needcal();
	safety();
	out();
	for (i = 0; i < np; i++)
	{f[i] = 0; safe[i] = 0;}
}
