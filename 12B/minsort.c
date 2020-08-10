/*
    Jason Bonilla 2016
    This is minsort (selection sort), will average O(n^2) not the most 
    efficient algorithm. Finds the smallest value and appends to a list.
*/
# include <stdio.h>
# include <stdint.h>

int minIndex(int a[], int begining, int end)
 {
 	int i;
	int smallest=begining;
	for (i=begining; i<end; i+=1)
	{
		if(a[i]< a[smallest])
	 	{
	 		smallest = i;
	 	}
	}
	return smallest;
 }

void minSort(int a[], int length)
 {
 	int i,smallest;
 	int temp = 0;
	for (i = 0; i<length-1; i++)
	{
		smallest = minIndex(a,i,length);
		if( smallest != i) 
		{
		 	temp = a[smallest];
		 	a[smallest] = a[i];
		 	a[i] = temp;
		}
	}
 }
//main to test minsort
int main(void)
{

		int i,j,k;
		k = 10;
        int x[10] = {10,9,8,7,6,5,4,3,2,1};
        int n = sizeof(x)/sizeof(x[0]);
        for(j = 0; j< n; j++)
        {
        	printf("Element[%d] = %d\n", j, x[j] );
        }
        minSort(x, k);
        printf("\n");
        for(i = 0; i< n; i++)
        {
        	printf("Element[%d] = %d\n", i, x[i] );
        }
		return 0;
	
		
}