/* es 1 Data una lista L dinamica singolarmente puntata di valori interi,
raddoppiare(numericamente) tutti i numeri dispari in essa contenuti.Per esempio 1->3->4 diventa 2->6->4
es 2 Data una lista L dinamica singolarmente puntata di valori interi,
duplicare tutti i numeri dispari in essa contenuti
(aggiungendo una copia a destra di ogni valore dispari).
Per esempio 1->2 diventa 1->1->2
es 3 Data una lista L dinamica singolarmente puntata di valori interi,
per ogni coppia consecutiva di numeri dispari uguali,
rimuovere un duplicato(il primo o il secondo della coppia).Es.1->1->1->2 diventa 1->1->2*/
#include <stdio.h>
#include <stdlib.h> // from malloc end rand/srand functions
#include <time.h>   //for time function
#define DIM 10

// list type definition
typedef struct list
{
    int value;
    struct list *next;
} list;

list *tailInsert(list *, int);

// creates a list containing random numbers
list *newList()
{

    list *l = NULL;

    for (int i = 0; i < DIM; i++)
        l = tailInsert(l, (rand() % 100) + 1);

    return l;
}

list *newNode(int value)
{

    list *node = (list *)malloc(sizeof(list));
    node->value = value;
    node->next = NULL;

    return node;
}

list *headInsert(list *l, int value)
{

    // creates the new node
    list *node = newNode(value);
    // inserts it at the head of the list
    node->next = l;

    return node;
}

list *tailInsert(list *l, int value)
{

    if (l == NULL)
        return newNode(value);
    else
        l->next = tailInsert(l->next, value);

    return l;
}

void printList(list *l)
{

    if (l != NULL)
    {
        printf("%d -> ", l->value);
        printList(l->next);
    }
    else
        printf("NULL\n\n");
}

void doubleOddValues(list *l)
{

    if (l != NULL)
    {
        // if the value is odd
        if (l->value % 2 == 1)
            // doubles the value of the node
            l->value *= 2;

        doubleOddValues(l->next);
    }
}

void duplicateOddValues(list *l)
{

    if (l != NULL)
    {
        // if the value is odd
        if (l->value % 2 == 1)
        {
            list *duplicate = newNode(l->value);
            duplicate->next = l->next;
            l->next = duplicate;
            duplicateOddValues(duplicate->next);
        }
        else
            duplicateOddValues(l->next);
    }
}

void removeDuplicatedCouples(list *l)
{
    if (l != NULL && l->next != NULL)
    {
        if (l->value % 2 == 1 && l->value == l->next->value)
        {
            list *temp = l->next;
            l->next = l->next->next;
            free(temp);
        }
        removeDuplicatedCouples(l->next);
    }
}

void freeList(list *l)
{
    if (l != NULL)
    {
        freeList(l->next);
        free(l);
    }
}

int main()
{
    printf("\nList: \n");

    srand(time(NULL));
    list *l = newList();
    printList(l);

    printf("Es 1: \n");
    doubleOddValues(l);
    printList(l);
    freeList(l);

    printf("\nList: \n");
    l = newList();
    printList(l);

    printf("Es 2: \n");
    duplicateOddValues(l);
    printList(l);

    printf("Es 3: \n");
    removeDuplicatedCouples(l);
    printList(l);

    return 0;
}