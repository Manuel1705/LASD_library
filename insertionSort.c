#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void insertionSort (int array[] , int dim)
{
    srand(time(NULL));

    int temp,
            next,
            current;

    for (next = 1; next < dim; next++)
    {
        temp = array[next];
        current = next-1;

        while (current >= 0 && array[current] > temp)
        {
            array[current+1] = array[current];
            current = current-1;
        }
        array[current+1] = temp;
    }
}

int main() {

    int  array[MAX];
    int  dim, i;

    do {
        printf("\n Enter the array dimension (max %d): ", MAX);
        scanf("%d", &dim);
    } while (dim > MAX);

    for ( i=0; i < dim; i++)
        array[i] = rand() % 100; //from 0 to 99

    printf("\nOriginal Array:\n\n");

    for (i=0; i < dim; i++)
        printf("\t%d", array[i]);

    insertionSort(array,dim);

    printf("\n\nSorted Array with Insertion Sort:\n\n");

    for (i=0; i < dim; i++)
        printf("\t%d",array[i]);

    printf("\n");
}
