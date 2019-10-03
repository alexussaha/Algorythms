#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Усов Александр


void fillArray(int* arr, int len) {
  int i;
  for (i = 0; i < len; i++) {
	arr[i] = rand() % 100;
  }
}

void printArray(int* arr, int len) {
  int i;
  for (i = 0; i < len; i++) {
	printf("%d ", arr[i]);
  }
  printf("\n");
}



  

void swap(int *a, int *b) {
  
  int t = *a;
  *a = *b;
  *b = t;
}
//Задание 1
void bubbleSort1(int* arr, int len) {
  int i;
  int j;
  int k = 0;
  for (i = 0; i < len; i++) {
	for (j = 0; j < len - 1; j++) {
	  if (arr[j] > arr[j + 1])
		swap(&arr[j], &arr[j + 1]);
		k++;
	}
  }
  printf("\nk = %d\n", k);
}




void bubbleSort2(int* arr, int len) {
  int i;
  int j;
  int k = 0;
  for (i = 0; i < len; i++) {
	for (j = 0; j < len - i; j++) {
	  if (arr[j] > arr[j + 1])
		swap(&arr[j], &arr[j + 1]);
		k++;
	}
  }
  printf("\nk = %d\n", k);
}


//Задание 2
void shekerSort(int *arr, int len)
{
  int l = 0, r = len - 1; 
  int f = 1;
  int i;
  while ((l < r) && f > 0)
  {
    f = 0;
    for(i = l; i<r; i++)  
    {
      if (arr[i]>arr[i + 1]) 
      {            
        swap(&arr[i], &arr[i+1]);
        
        f = 1;     
      }
    }
    r--;
    for ( i = r; i>l; i--)  
    {
      if (arr[i - 1]>arr[i]) 
      {           
        swap(&arr[i], &arr[i-1]);
        f = 1;    
      }
    }
    
    l++; 
  }
}
//задание 3
void pigeonholeSort(int mi, int ma, int * a)
{
 
    int size, count = 0, i;
    int *current;
    current = a;
    size = ma - mi + 1;
    int holes[size];
    for (i = 0; i < size; i++)
    {
        holes[i] = 0;
    }
    for (i = 0; i < size; i++, current++)
    {
        holes[*current-mi] += 1;
    }
    for (count = 0, current = &a[0]; count < size; count++)
    {
        while ((holes[count]--)> 0)
        {
            *current++ = count + mi;
        }
    }
}

int main(int argc, const char** argv) {
  srand(time(NULL));
  int SIZE = 33;
  int arr[SIZE];
  int i, min, max;
  fillArray(arr, SIZE);
  printArray(arr, SIZE);
  bubbleSort1(arr, SIZE); 
  printArray(arr, SIZE);
  fillArray(arr, SIZE);
  printArray(arr, SIZE);
  bubbleSort2(arr, SIZE); 
  printArray(arr, SIZE);
  fillArray(arr, SIZE);
  printArray(arr, SIZE);
  shekerSort(arr, SIZE); 
  printArray(arr, SIZE);
  fillArray(arr, SIZE);
  printArray(arr, SIZE);
  min = arr[0];
  max = arr[0];
  for (i = 1; i < SIZE; i++) {
      if (arr[i] < min) {
         min = arr[i];
      }
      if (arr[i] > max) {
         max = arr[i];
      }
   }
  pigeonholeSort(min, max, arr); 
  printArray(arr, SIZE);
  
  return 0;
}