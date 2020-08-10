/*
    Jason Bonilla 2016
    This is bubblesort, will average O(n^2). not very effecient
*/
# include <stdio.h>
# include <stdint.h>

void bubbleSort(int arr[], int length)
{
    int temp;
    int count = 1;
    int track = 0;
    int i;

    //loop continues until no more bubble ups
    while(count)
    {
        for(i = 0; i<length-1; i++)
        {
            if(arr[i] > arr[i+1])
            {
                track++;
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        if(track == 0)
        {
            count = 0;
        }
            track = 0;
    }
}
//main to test bubble algorithm
int main(void)
{
    int i,j,k;
    k = 10;
    int x[10] = {10,9,8,7,3,5,4,3,2,1};
    int n = sizeof(x)/sizeof(x[0]);
    for(j = 0; j< n; j++)
    {
        printf("Element[%d] = %d\n", j, x[j] );
    }
    bubbleSort(x, k);
    printf("\n");
    for(i = 0; i< n; i++)
    {
        printf("Element[%d] = %d \n", i, x[i] );
    }
    return 0;
}