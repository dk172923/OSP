#include<stdio.h>
int main()
{
	int i, j, arr[100], pt[20], val, pgno, offset, phymem, fs, nf;
	printf("Memory Management paging\n");
	printf("Enter the size of physical memory: ");
	scanf("%d", &phymem);
	for(i=20,j=0;i<phymem+20;i++,j++)
		arr[i]=j;
	printf("\nEnter size of frame/page: ");
	scanf("%d",&fs);
	nf=phymem/fs;
	printf("No. of frame available: %d\n",nf);
	printf("\nEnter the page table ");
	for(i=0;i<nf;i++)
	{
		scanf("%d",&pt[i]);
	}
	printf("\nEnter the page no: ");
	scanf("%d",&pgno); 
	printf("\nEnter the offset: ");
	scanf("%d",&offset);
	val=(fs*pt[pgno])+offset;
	printf("The physical address is: %d\n",arr[val]);
}

