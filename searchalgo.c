#include<stdio.h>
#include<stdlib.h>

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
int linearSearch(struct array *a, int data)
{

  for (int i = 0; i < a->used_size; i++)
  {
    if (a->a[i] == data)
    {
      return i;
    }
  }
  return -1;
}

int ternarySearch(struct array *a, int data, int high, int low){
   
   if (high>=1)
   {
    
   int mid1=low+(high-low)/3;
   int mid2=high+(high-low)/3;

   if (a->a[mid1]==data)
   {
     return mid1;
   }

   if (a->a[mid2]==data)
   {
    return mid2;
   }

   if (a->a[mid1]<data)
   {
      return ternarySearch(a,data,high,mid1+1);
   }
   
   else if (a->a[mid2]<data)
   {
      return ternarySearch(a,data,high,mid2+1);
   }
   
   else
     return ternarySearch(a,data,mid2-1,mid1+1);
   }

   return -1;

}


int binarySearch(struct array *a, int data)
{
  int low = 0;
  int high = a->used_size - 1;
  int mid;

  while (low <= high)
  {

    mid = (high + low) / 2;
    if (a->a[mid] == data)
    {
      return mid;
    }

    if (a->a[mid] < data)
    {
      low = mid + 1;
    }

    else
    {
      high = mid - 1;
    }
  }

  return -1;
}

int main()
{
  struct array array;
  int search, search2;
  createArray(&array, 15, 10);
  displayArray(&array);

   printf("Enter an element to search\n");
  scanf("%d", &search);

  if (linearSearch(&array, search) >= 0)
  {
    printf("Element found at %d position\n", linearSearch(&array, search));
  }

  else
  {
    printf("Element not found\n");
  }

  printf("Enter an element to search using binary search\n");
  scanf("%d", &search2);

  if (binarySearch(&array, search2) >= 0)
  {
    printf("Element found at %d position\n", binarySearch(&array, search2));
  }

  else
    printf("Element not found in the array\n");

  printf("Enter an element to search using ternary search\n");
  int search3;
  scanf("%d",&search3);

  if (ternarySearch(&array,search3,(&array)->used_size-1,0)>=0)
  {
     printf("Element found at %d position\n",ternarySearch(&array,search3,(&array)->used_size-1,0));
  }
  else{
    printf("Element not found in the array\n");
  }
    return 0;
}