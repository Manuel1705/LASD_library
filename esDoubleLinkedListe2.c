// Scrivere una funzione ricorsiva che permetta di creare due liste
// puntate e non circolari L1 e L2,
// di interi positivi,
// con caricamento da riga di comando
// Scrivere una funzione ricorsiva per la stampa delle due liste
// Scrivere una funzione ricorsiva che, prese entrambe le due liste L1 e L2
// Ordini L1 in senso crescente
// Rimuova da L1 gli elementi dispari e li inserisca in testa ad L2.

#include <stdio.h>
#include <stdlib.h>
typedef struct DLlist
{
    int value;
    struct DLlist *prev;
    struct DLlist *next;
} DLlist;

DLlist *newDoubleLinkedList(DLlist *prev, DLlist *node, int dim)
{
    node = (DLlist *)malloc(sizeof(DLlist));
    node->prev = prev;
    DLlist *next;

    int d;
    printf("Enter the node value: ");
    scanf("%d", &d);

    node->value = d;

    if (dim > 1)
        node->next = newDoubleLinkedList(node, next, --dim);
    else
        node->next = NULL;

    return node;
}

void printList(DLlist *l)
{

    if (l != NULL)
    {
        printf("%d -> ", l->value);
        printList(l->next);
    }
    else
        printf("NULL\n\n");
}

DLlist *sortDoubleLinkedList(DLlist *l)
{
    if (l != NULL)
    {
        if (l->prev != NULL)
        {
            if (l->value < l->prev->value)
            {
                printf("Scambio %d %d\n", l->prev->value, l->value);

                DLlist *tmp;
                tmp = l->next;

                l->next = l->prev;
                l->prev = l->prev->prev;

                l->next->next = tmp;
                l->next->prev = l;

                if (tmp != NULL)
                    tmp->prev = l->next;
                sortDoubleLinkedList(l);
            }
        }
        sortDoubleLinkedList(l->next);

        // head retrieval
        while (l->prev != NULL)
            l = l->prev;
    }
    return l;
}
int main()
{
    int dim;
    printf("Enter the list dimension: ");
    scanf("%d", &dim);

    DLlist *l = newDoubleLinkedList(NULL, l, dim);
    printList(l);
    l = sortDoubleLinkedList(l);

    printList(l);
    system("PAUSE");
}