#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 10

int left(int i) { return 2*i+1; }

int right(int i) { return 2*i+2; }

//int p(int i) { return (i-1)/2; }

void swap(int array[], int i, int j)
{
    int tmp = array[i];
    array[i] = array[j];
    array[j] =tmp;
}


void Heapify(int array[],int dim, int i) {

    int l, r,
            max = i;

    l = left(i);
    r = right(i);

    if (l < dim && array[l] > array[i])
        max = l;

    if (r < dim && array[r] > array[max])
        max = r;

    if (max != i) {
        swap(array, i, max);
        Heapify(array, dim, max);
    }
}
void BuildHeap(int array[], int dim)
{
    for (int i = dim/2; i >= 0; i--)
        Heapify(array, dim, i);
}

void HeapSort(int array[], int dim)
{
    int i;
    BuildHeap(array, dim);
    for (i = dim - 1; i >= 1; i--) {
        swap(array, 0, i);
        Heapify(array, i,0);
    }
}

int main()
{
    srand(time(NULL));

    int array[MAX], dim;

    do {
        printf("\nEnter array size (max %d): ", MAX);
        scanf("%d", &dim);
    } while (dim > MAX);

    int i;
    for (i=0; i < dim; i++)
        array[i] = rand() % 100; //from 0 to 99

    printf("\nOriginal Array:\n\n");

    for (i =0; i < dim ; i++)
        printf("\t%d", array[i]);

    HeapSort(array, dim);

    printf("\n\nSorted Array with Heap Sort:\n\n");

    for (i =0; i < dim ; i++)
        printf("\t%d", array[i]);

    printf("\n");
}