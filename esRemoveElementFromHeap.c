// Dato un heap H(di interi) rappresentato con vettore statico,
// scrivere una procedura che, in tempo logaritmico,
// presi in input H e un valore numerico v presente in H(con relativo indice di posizione di v nel vettore),
// rimuova v da H, mantenendo la proprietà di heap.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 15

int left(int parent)
{
    return 2 * parent + 1;
}

int right(int parent)
{
    return 2 * parent + 2;
}

int parent(int son)
{
    return (son - 1) / 2;
}
void swap(int *array, int a, int b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void heapify(int *array, int dim, int parent)
{
    int l = left(parent);
    int r = right(parent);
    int max = parent;

    if (l < dim && array[max] <= array[l])
        max = l;

    if (r < dim && array[max] <= array[r])
        max = r;

    if (max != parent)
    {
        swap(array, max, parent);
        heapify(array, dim, max);
    }
}

void buildHeap(int *array, int dim)
{
    for (int i = dim / 2 - 1; i >= 0; i--)
        heapify(array, dim, i);
}

void printHeap(int *heap, int dim)
{
    int nextLevel = 1;
    for (int i = 0; i < dim; i++)
    {
        if (i == nextLevel)
        {
            printf("\n");
            nextLevel = left(nextLevel);
        }
        printf("%d ", heap[i]);
    }
    printf("\n");
}
int getIndex(int *array, int dim, int element)
{
    for (int i = 0; i < dim; i++)
        if (array[i] == element)
            return i;
    printf("The element is not stored in the array");
    return -1;
}
void deleteElementHeap(int *array, int dim, int index)
{
}
int main()
{

    srand(time(NULL));
    int heap[MAX] = {0};

    int dim;
    do
    {
        printf("Enter the heap dimention(max: %d): ", MAX);
        scanf("%d", &dim);
    } while (dim > MAX && dim <= 0);

    for (int i = 0; i < dim; i++)
        heap[i] = (rand() % 100) + 1;

    buildHeap(heap, dim);
    printHeap(heap, dim);

    int d;
    printf("Enter the element to delete from the heap: ");
    scanf("%d", &d);
    int index = getIndex(heap, dim, d);
    deleteElementHeap(heap, dim, index);
}