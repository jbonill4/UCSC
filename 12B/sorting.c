# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>    
# include <getopt.h>

#define MASK 0x00ffffff

int minIndex(int a[], int beggining, int end)
{
 	int i;
	int theMostSmall=beggining;
	for (i=beggining; i<end; i+=1)
	{
		if(a[i]< a[theMostSmall])
	 	{
	 		theMostSmall = i;
	 	}
	}
	return theMostSmall;
}

void minSort(int a[], int length)
{
 	int i,theMostSmall;
 	int temp = 0;
	for (i = 0; i<length-1; i++)
	{
		theMostSmall = minIndex(a,i,length);
		if( theMostSmall != i) 
		{
		 	temp = a[theMostSmall];
		 	a[theMostSmall] = a[i];
		 	a[i] = temp;
		}
	}
}

void bubbleSort(int arr[], int length)
{
        //very useful variables
        int temp;
        int count = 1;
        int track = 0;
        int i;
        
        //loop continues until no mo bubble ups
        while(count)
        {
                for(i =0;i<length-1;i++)
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

int partition(int array[],int min,int max)
{
    int temp;
    int pivot = array[max];//pivot smh
    int i =  min-1;//THE WALL
    int pivLoc;
    //for loop that changes depending on the endpoints :/
    for (int j=min; j<=max-1; j++)
    {
        if (array[j] <= pivot)//smaller than the pivot?
        {
            i++;//movin the wall babyy
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;       
        }
    }

    pivLoc = (i+1);//movin the pivot boyz
    temp = array[i+1];
    array[i+1] = array[max];
    array[max] = temp;

    return pivLoc;
}
void quickSort(int array[], int min, int max)
{
    if  (min<max)
    {
        //partition doing its magic
        int curPivot = partition(array, min, max);
        //left side
        quickSort(array, min, curPivot-1);
        //right side
        quickSort(array, curPivot+1, max);
    }
    //too much
}

void merge(int leftIndex, int midIndex, int rightIndex,int x[])
{
    int a;
    int b;
    int c =leftIndex;
    int leftNum =1+midIndex - leftIndex;
    int rightNum =rightIndex - midIndex;
    int leftArray[leftNum];
    int rightArray[rightNum];
    //printf("%d\n",leftNum );
    //printf("%d\n", rightNum);
    //printf("%d\n", );
    //printf("%d\n", );
    //fill the puppies in
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
      //printf("%d\n", );
    //printf("%d\n",a );
    //printf("%d\n", b);
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
    //printf("%d\n",a );
    //printf("%d\n", b);
    //fill the rest of these puppies in
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


void print(int ar[],int length)
{
	int count = 6;

		for(int i = 0; i < length;i++)
		{
			//count++;
			printf(" %10d ",ar[i]);
			if(i%count == 0 && i !=0)
			{
				printf("\n");
				//count = -1;	
			}		
		}
		printf("\n");
}

void copy(int x[], int y[], int length)
{
	for(int i = 0;i<length;i++)
	{
		x[i] = y[i];
	}
}

void runThisB(int arr[],int tseed, int tprint,int array[])
{
	//int arrSize = 100;
	//int seed = 8222022;
	srand(tseed);
	int i,n;
	n = sizeof(&arr)/sizeof(arr[0]);
	int arrCOPY[n];
	
	//fill in array
	for(i = 0; i<n;i++)
	{
		arr[i] = (rand() & MASK);
		arrCOPY[i] = arr[i];
	}

	if(array[0])
	{
		printf("Min Sort\n");
		printf("%d  elements \n",n);
		minSort(arr,n);
		print(arr,tprint);
		copy(arr,arrCOPY,n);//reset array


		printf("Bubble Sort\n");
		printf("%d  elements \n",n);
		bubbleSort(arr,n);
		print(arr,n);
		copy(arr,arrCOPY,n);//reset array


		printf("Insertion Sort\n");
		printf("%d  elements \n",n);
		insertionSort(arr,n);
		print(arr,tprint);
		copy(arr,arrCOPY,n);//reset array

		printf("Quick Sort\n");
		printf("%d  elements \n",n);
		quickSort(arr,0,n);
		print(arr,tprint);
		copy(arr,arrCOPY,n);//reset array

		printf("Merge Sort\n");
		printf("%d  elements \n",n);
		mergeSort(arr,0,n);
		print(arr,tprint);
		copy(arr,arrCOPY,n);//reset array

	}
	if(array[1])
	{
		printf("Min Sort\n");
		printf("%d  elements \n",n);
		minSort(arr,n);
		print(arr,tprint);
		copy(arr,arrCOPY,n);//reset array
	}
	if(array[2])
	{
		printf("Bubble Sort\n");
		printf("%d  elements \n",n);
		bubbleSort(arr,n);
		print(arr,n);
		copy(arr,arrCOPY,n);//reset array
	}
	if(array[3])
	{
		printf("Insertion Sort\n");
		printf("%d  elements \n",n);
		insertionSort(arr,n);
		print(arr,tprint);
		copy(arr,arrCOPY,n);//reset array
	}
	if(array[4])
	{
		printf("Quick Sort\n");
		printf("%d  elements \n",n);
		quickSort(arr,0,n);
		print(arr,tprint);
		copy(arr,arrCOPY,n);//reset array
	}
	if(array[5])
	{
		printf("Merge Sort\n");
		printf("%d  elements \n",n);
		mergeSort(arr,0,n);
		print(arr,tprint);
		copy(arr,arrCOPY,n);//reset array
	}

}



int main(int argc, char *argv[])
{
	int option;
	int maxNumber;
	int realArray[100];
	int array[8];
	//int printNum = 100;
	int seed = 8062022;
	int arrSize = 100;

	while ((option = getopt(argc, argv, "Ambiqp:r:n")) != -1)
	{
		switch(option)
		{
			case 'A':
			{
				array[0] = 1;
				break;
			}
			case 'm':
			{
				array[1] = 1;
				break;
			}
			case 'b':
			{
				array[2] = 1;
				break;
			}
			case 'i':
			{
				array[3] = 1;
				break;
			}
			case 'q':
			{
				array[4] = 1;
				break;
			}
			case 'p':
			{
				maxNumber = atoi(optarg);
				array[5] = 1;
				break;
			}
			case 'r':
			{
				seed = atoi(optarg);
				array[6] = 1;
				break;
			}
			case 'n':
			{
				arrSize = atoi(optarg);
				array[7] = 1;
				break;
			}
		}
	}
	if(arrSize != 0)
	{
		int realArray[arrSize];
		for(int i = 0; i<arrSize;i++)
		{
			realArray[i] = 0;
		}
	}
	else
	{
		int realArray[100];
		for(int i = 0; i<100;i++)
		{
			realArray[i] = 0;
		}
	}
	runThisB(realArray,seed,maxNumber,array);


}



