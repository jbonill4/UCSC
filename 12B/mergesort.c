/*
    Jason Bonilla 2016
    This is mergesort, will average O(n*logn) because of recursion. O(n) space 
    required on arrays. However on linked lists, mergsort requires constant
    space
*/
# include <stdio.h>
# include <stdint.h>

//merges two subarrays 
void merge(int leftIndex, int midIndex, int rightIndex,int x[])
{
    int a;
    int b;
    int c = leftIndex;
    int leftNum = 1 + midIndex - leftIndex;
    int rightNum = rightIndex - midIndex;
    int leftArray[leftNum];
    int rightArray[rightNum];

    for (int j=0; j<rightNum; j++)
    {

       rightArray[j] = x[midIndex + 1+ j];
    }
    for (int i=0; i<leftNum; i++)
    {
         leftArray[i] = x[leftIndex + i];
    }
    a =0;
    b =0;
    while (a<leftNum && b<rightNum)
    {
        if (leftArray[a] <= rightArray[b])
        {
            x[c] =leftArray[a];
            a++;
        }
        else
        {
            x[c] =rightArray[b];
            b++;
        }
        c++;
    }
    while (b<rightNum)
    {
        x[c]=rightArray[b];
        b++;
        c++;
    }
    while (a<leftNum)
    {
        x[c]=leftArray[a];
        a++;
        c++;
    }
}
//mergeSort calls itsef twice, once on each side and lastly calls merge
void mergeSort(int array[],int left,int right)
{
    if (left < right)
    {
        int midIndex = left+(right-left)/2;
        mergeSort(array, left, midIndex);
        mergeSort(array, midIndex+1, right);
        merge(left, midIndex,right,array);
    }
}
//main to test mergesort
int main(void)
{
        int a,b,c,midIndex;
        c = 9;
        midIndex = 0;
        int x[10] = {10,9,8,7,6,5,4,3,2,1};
        int n = sizeof(x)/sizeof(x[0]);
        for(b = 0; b< n; b++)
        {
            printf("Element[%d] = %d\n", b, x[b] );
        }
        mergeSort(x,midIndex,c);
        printf("\n");
        for(a = 0; a< n; a++)
        {
            printf("Element[%d] = %d\n", a, x[a] );
        }
    return 0;
}