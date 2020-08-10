/*
    Jason Bonilla 2016
    QuickSort runs in O(n*logn) fairly effecient. However there are
    better sorting algorithms such as MergeSort.

*/
# include <stdio.h>
# include <stdint.h>

int partition(int array[],int min,int max)
{
    int temp;
    int pivot = array[max];
    int i =  min-1;//THE WALL
    int pivLoc;
    //for loop that changes depending on the endpoints
    for (int j=min; j<=max-1; j++)
    {
        if (array[j] <= pivot)//smaller than the pivo?
        {
            i++;//movin the wall babyy
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;       
        }
    }

    pivLoc = (i+1);
    temp = array[i+1];
    array[i+1] = array[max];
    array[max] = temp;

    return pivLoc;
}
 
void quickSort(int array[], int min, int max)
{
    if  (min<max)
    {
        //partition
        int curPivot = partition(array, min, max);
        //left side
        quickSort(array, min, curPivot-1);
        //right side
        quickSort(array, curPivot+1, max);
    }
}

//main to test quickSort
int main(void)
{
        int i,j,k,m;
        k = 9;
        m = 0;
        int x[10] = {10,9,8,7,6,5,4,3,2,1};
        int n = sizeof(x)/sizeof(x[0]);
        for(j = 0; j< n; j++)
        {
            printf("Element[%d] = %d\n", j, x[j] );
        }
        quickSort(x,m,k);
        printf("\n");
        for(i = 0; i< n; i++)
        {
            printf("Element[%d] = %d\n", i, x[i] );
        }
    return 0;
}