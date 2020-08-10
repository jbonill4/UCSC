/*
    Jason Bonilla 2016
    This is insertionsort, will average O(n^2) time. Not very effecient
*/
# include <stdio.h>
# include <stdint.h>

//insertionsort algorithm
void insertionSort(int arr[], int length)
{
    int i,temp;
    int j;
    for(i=1;i< length;i++)
    {
        temp = arr[i];
        j = i-1;
        while(j >=0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1] = temp;
    }
}
//main to test insertionsort algorithm
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
    insertionSort(x, k);
    printf("\n");
    for(i = 0; i< n; i++)
    {
        printf("Element[%d] = %d\n", i, x[i] );
    }
    return 0;
}