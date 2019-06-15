#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

void swapSelection( int * lhs, int * rhs );
void selection_sort (int *a, int n);
void insertion_sort(int *a, int n);
void merge(int *theArray, int first, int mid, int last);
void merge_sort (int *theArray, int first, int last);
void swapQuick(int *x,int *y);
int choose_pivot(int i,int j );
void quicksort(int *list,int m,int n);
//void display(int *list,const int n);

void swapQuick(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int choose_pivot(int i,int j )
{
    return((i+j) /2);
}

void quicksort(int *list,int m,int n)
{
    int key,i,j,k;
    if( m < n)
    {
        k = choose_pivot(m,n);
        swapQuick(&list[m],&list[k]);
        key = list[m];
        i = m+1;
        j = n;
        while(i <= j)
        {
            while((i <= n) && (list[i] <= key))
                i++;
            while((j >= m) && (list[j] > key))
                j--;
            if( i < j)
                swapQuick(&list[i],&list[j]);
        }
        /* swap two elements */
        swapQuick(&list[m],&list[j]);
 
        /* recursively sort the lesser list */
        quicksort(list,m,j-1);
        quicksort(list,j+1,n);
    }
}

//void display(int *list,const int n)
//{
//    int i;
//    for(i=0; i<n; i++)
//        printf("%d\t",list[i]);
//}

void swapSelection(int * lhs, int * rhs )
{
	int tmp = *lhs;
	*lhs = *rhs;
	*rhs = tmp;
}

void selection_sort (int *a, int n)
{
	int i;
    for (i = 0; i < n-1; i++) 
	{
		int min = i;
		int j;
		for (j = i+1; j < n; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}				
		}					
		swapSelection(&a[i], &a[min]);
	}
}

void insertion_sort(int *a, int n)
{
	int i;
    for (i = 1; i < n; i++)
	{ 
		int tmp = a[i];
		int j;
		for (j=i; j>0 && tmp < a[j-1]; j--)
		a[j] = a[j-1];
		a[j] = tmp;
	}    
}

void merge(int *theArray, int first, int mid, int last)
{
    int tempArray[last + 1];  // temporary array
	int first1 = first;  // beginning of first subarray
	int last1 = mid;  // end of first subarray
	int first2 = mid + 1; // beginning of second subarray
	int last2 = last; // end of second subarray
	int index = first1; // next available location in tempArray
	for ( ; (first1 <= last1) && (first2 <= last2); ++index) 
	{
		if (theArray[first1] < theArray[first2]) 
		{  
			tempArray[index] = theArray[first1];
			++first1;
		}
		else 
		{  
			tempArray[index] = theArray[first2];
			++first2;
		}
	}
	
	// finish off the first subarray, if necessary
	for (; first1 <= last1; ++first1, ++index)
		tempArray[index] = theArray[first1];
	
	// finish off the second subarray, if necessary
	for (; first2 <= last2; ++first2, ++index)
		tempArray[index] = theArray[first2];
		
	// copy the result back into the original array
	for (index = first; index <= last; ++index)
		theArray[index] = tempArray[index];
}

void merge_sort (int *theArray, int first, int last) 
{
	if (first < last) 
	{
		int mid = (first + last)/2;  // index of midpoint
		merge_sort(theArray, first, mid);
		merge_sort(theArray, mid+1, last);
	
		// merge the two halves
		merge(theArray, first, mid, last);
	}
}

int main (int argc, char **argv)
{
	int size;
    int choice;
    
	printf("Kac tane sayi olacak? 10000 icin 1, 100000 icin 2: ");
	scanf("%d", &size);
	printf("Siralama turunu seçiniz. Selection Sort icin 1, Insertion Sort icin 2, Merge Sort icin 3, Quick Sort için 4: ");
	scanf("%d", &choice);    
	
	//size degiskeni olmasi gereken degeri aldi.
	if(size == 1)
		size = 10000;
	else if(size == 2)
		size = 100000;
	
    srand(time(NULL));
    int * a = (int *)malloc(sizeof(int)*size);
    
    //size degiskeni kadar random sayi olusturuldu. 
    int i;
    for(i=0;i<size;i++)
        a[i] = rand()%1000;
    		
    int n = size;
    struct timeval stop, start;
    gettimeofday(&start, NULL);

    if(choice == 1){
        printf("Selection sort is selected\n");
        selection_sort(a, size);       		  
    }
    if(choice == 2){
        printf("Insertion sort is selected\n");
        insertion_sort(a, size);        
    }
    if(choice == 3){
        printf("Merge sort is selected\n");
        merge_sort(a, 0, size-1);
    }
    if(choice == 4){
        printf("Quick sort is selected\n");
        quicksort(a, 0, size-1);     		
    }      
   
    gettimeofday(&stop, NULL);
    
    float elapsed = (stop.tv_sec - start.tv_sec) * 1000.0f + (stop.tv_usec - start.tv_usec) / 1000.0f;
    printf("Code executed in %f milliseconds.\n", elapsed);

//  display(a, size);
	
    return 0;
}


