#include<stdio.h>
void main()
{
	char a[10];
	int i, ib, cib[10];
	printf("Enter the file name: "); 
	scanf("%s",a);
	printf("Index block: ");
	scanf("%d",&ib);
	for(i=1;i<=5;i++)
	{
		printf("Enter the child of index block %d: ",i); 
		scanf("%d",&cib[i]);
	}
	printf("\nThe list of files\t Index block\n"); 
	printf("%s\t\t\t %d", a, ib);
	printf("\nThe above file utilization index block of child blocks following\t"); 
	printf("\n");


	for(i=1;i<=5;i++)
	{
		printf("%d\t\t", cib[i]);
	}
	printf("\n");
}

