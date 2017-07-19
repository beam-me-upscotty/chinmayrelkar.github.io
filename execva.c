/* execve.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void printarray(int arr[],int size)
{
	int i;
	printf("\n");
	for( i=0;i<size;i++)
	printf("[%d]",arr[i]);
	printf("\n");
}

void acceptarray(int arr[],int n)
{
	int i;
	printf("\nenter array elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
}

void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
void bubblesort(int arr[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	
		for(j=0;j<n-1-i;j++)
		
			if(arr[j]>arr[j+1])
			swap(&arr[j],&arr[j+1]);
		
}

int main(int argc, char *argv[])
{
           	
	int arr[20] = { 5,10,8,3,4,11,1};
        bubblesort(arr,7);
		
        char *newargv[] = { "pvg", "hello", "world", NULL };
        char *newenviron[] = { NULL };
        int i;
        for(i = 0 ;i <7; i++)
        {
	   char *x = (char* ) malloc(10);
	   sprintf(x,"%d",arr[i]);
	   newargv[i] = x;
	   fprintf(stderr,"%s\n",newargv[i]);
        }
	newargv[i] = NULL;
		
        if (argc != 2) 
        {
             fprintf(stderr, "Usage: %s <file-to-exec>\n", argv[0]);
             exit(EXIT_FAILURE);
        }

        // newargv[0] = argv[1];

         execve(argv[1], newargv, newenviron);
         perror("execve");   /* execve() returns only on error */
         exit(EXIT_FAILURE);
}

