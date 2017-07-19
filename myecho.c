/* myecho.c */

           #include <stdio.h>
           #include <stdlib.h>

void printarray(int arr[],int size)
{
	int i;
	printf("\n");
	for( i=0;i<size;i++)
	printf("[%d]",arr[i]);
	printf("\n");
}
int bs(int a[],int n, int s)
{
	int x=n/2;
	int start = 0, end = n;
	while(a[x]!=s && !(start>=end)){
		if(s>a[x])
			start = x+1;
		else 
			end =x-1;
		x=(start+end)/2;
	}
	if(a[x]==s )
		printf(" found");
	else
	printf("not found");;
}


          int main(int argc, char *argv[])
           {
               int j;
               int arr[7];
               for (j = 0; j < argc; j++){
                   printf("argv[%d]: %s\n", j, argv[j]);
                   arr[j] = *argv[j]-48;
                   
		}
		scanf("%d",&j);
		bs(arr,7,j);
		
               exit(EXIT_SUCCESS);
           }
	
	
	        
