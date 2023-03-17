#include <stdio.h>
#include <stdlib.h>

struct array
{
    int total_size;
    int used_size;
    int *a;
};

void createArray(struct array *arr, int total, int used)
{
    arr->total_size = total;
    arr->used_size = used;
    arr->a = (int *)malloc((arr->total_size) * sizeof(int));

    printf("Enter the elements one by one\n");
    for (int i = 0; i < arr->used_size; i++)
    {
        scanf("%d", &arr->a[i]);
    }
}

void displayArray(struct array *arr)
{
    for (int i = 0; i < arr->used_size; i++)
    {
        printf("Element %d: %d\n", i, arr->a[i]);
    }
}

void quickswap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


void simplesort(struct array *arr)
{

    for (int i = 0; i < arr->used_size; i++)
    {
        for (int j = i + 1; j < arr->used_size; j++)
        {
            if (arr->a[i] > arr->a[j])
            {
                int temp;
                temp = arr->a[i];
                arr->a[i] = arr->a[j];
                arr->a[j] = temp;
            }
        }
    }
}

void swap(struct array *arr, int x, int y)
{

    int temp;
    temp = arr->a[x];
    arr->a[x] = arr->a[y];
    arr->a[y] = temp;
}

int locationOfSmallest(struct array *arr, int s, int e)
{
    int i = s;
    int j = i;

    while (i <= e)
    {
        if (arr->a[i] < arr->a[j])
        {
            j = i;
        }
        i++;
    }

    return j;
}

void selSort(struct array *arr)
{

    int i = 0;
    while (i < arr->used_size - 1)
    {
        int j = locationOfSmallest(arr, i, arr->used_size - 1);
        swap(arr, i, j);
        i++;
    }
}

int partition(struct array* arr, int low, int high)
{
	int x = arr->a[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{
		if (arr->a[j] <= x)
		{
			i++;
			quickswap(&(arr->a[i]), &(arr->a[j]));
		}
	}
	quickswap(&(arr->a[i + 1]), &(arr->a[high]));
	return (i + 1);
}

void quicksort(struct array* arr, int low, int high)
{

	int ind = high - low + 1;
	int temp[ind];

	int i = -1;

	temp[++i] = low;
	temp[++i] = high;


	while (i >= 0)
	{
		high = temp[i--];
		low = temp[i--];

	
		int pi = partition(arr, low, high);

		if (pi - 1 > low)
		{
			temp[++i] = low;
			temp[++i] = pi - 1;
		}

		if (pi + 1 < high)
		{ 
			temp[++i] = pi + 1;
			temp[++i] = high;
		}
	}
}

int main()
{
    struct array array;
    createArray(&array, 15, 10);
    displayArray(&array);

    simplesort(&array);
    printf("The array after sorting...\n");
    displayArray(&array);

    selSort(&array);
    printf("The array after using selection sort....\n");
    displayArray(&array);

    quicksort(&array,0,array.used_size-1);
    printf("The array after using quick sort....\n");
    displayArray(&array);
    return 0;

}