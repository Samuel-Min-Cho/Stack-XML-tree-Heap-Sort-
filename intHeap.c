#include <stdio.h>
#include <math.h>
/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */

static int arr[100];
static int ind = 0;

void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
  int i = 0;
  while (arr[i] != 0)
  {
    i++;
  }
  return i;
}

void heapify(int array[], int size, int i)
{
  if (size == 1)
  {
    printf("Single element in the heap");
  }
  else
  {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;
    if (largest != i)
    {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  }
}

/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add)
{
  arr[ind] = thing2add;
  ind++;
  for (int i = heapSize() / 2 - 1; i >= 0; i--)
  {
    heapify(arr, heapSize(), i);
  }
}

/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */
int heapDelete()
{
  int a = arr[0];
  swap(&arr[0], &arr[heapSize() - 1]);
  arr[heapSize() - 1] = 0;
  for (int i = heapSize() / 2 - 1; i >= 0; i--)
  {
    heapify(arr, heapSize(), i);
  }
  return a; // A dummy return statement
}

void printArray()
{
  for (int i = 0; i < heapSize(); ++i)
    printf("%d ", arr[i]);
}

void tree(int z)
{
  printf("<node ID: %d>", arr[z]);
  // int size = heapSize();
  int right = z * 2 + 1;
  int left = z * 2 + 2;
  if (right < heapSize())
  {
    tree(right);
  }
  if (left < heapSize())
  {
    tree(left);
  }
  printf("</node>");
}