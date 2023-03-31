// Dato un heap H(di interi) rappresentato con vettore statico,
// scrivere una procedura che, in tempo logaritmico,
// presi in input H e un valore numerico v presente in H(con relativo indice di posizione di v nel vettore),
// rimuova v da H, mantenendo la proprietà di heap.
// IMPORTANTE
// ARRAY[0] CONTIENE LA DIMENSIONE DELL'HEAP
// L'algoritmo funziona ma deleteElementHeap può essere ottimizata
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 16
// calcolo figlio sinistro con indice che parte da 1
int left(int parent)
{
    return 2 * parent;
}
// calcolo figlio destro con indice che parte da 1
int right(int parent)
{
    return 2 * parent + 1;
}
// calcolo padre con indice che parte da 1
int parent(int son)
{
    return son / 2;
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

    if (l <= dim && array[max] <= array[l])
        max = l;

    if (r <= dim && array[max] <= array[r])
        max = r;

    if (max != parent)
    {
        swap(array, max, parent);
        heapify(array, dim, max);
    }
}

void buildHeap(int *array, int dim)
{
    for (int i = dim / 2; i > 0; i--)
        heapify(array, dim, i);
}

void printHeap(int *heap, int dim)
{
    printf("\nHeap (dim %d):", dim);
    int nextLevel = 1;
    for (int i = 1; i <= dim; i++)
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
    for (int i = 1; i <= dim; i++)
        if (array[i] == element)
            return i;
    printf("\nThe element is not stored in the array\n");
    return -1;
}
int checkStored(int *array, int dim, int element)
{
    for (int i = 1; i <= dim; i++)
        if (array[i] == element)
            return 1;
    return 0;
}
void repairHeap(int *array, int parent, int dim)
{
}
void deleteElementHeap(int *heap, int dim, int index)
{
    if (index >= 1 && index <= heap[0])
    {
        swap(heap, index, heap[0]);
        heap[0]--;
        buildHeap(heap, heap[0]);
    }
}
int main()
{

    srand(time(NULL));
    int heap[MAX] = {0};

    int dim;
    do
    {
        printf("\nEnter the heap dimention(max: %d): ", MAX - 1);
        scanf("%d", &dim);
    } while (dim > MAX && dim <= 0);

    for (int i = 1; i <= dim; i++)
    {
        int d;
        do
        {
            d = (rand() % 100) + 1;
            heap[i] = d;
        } while (checkStored(heap, heap[0], d));
        heap[0]++;
    }

    buildHeap(heap, heap[0]);
    printHeap(heap, heap[0]);

    int d;
    printf("Enter the element to delete from the heap: ");
    scanf("%d", &d);
    deleteElementHeap(heap, dim, getIndex(heap, dim, d));
    printHeap(heap, heap[0]);
}