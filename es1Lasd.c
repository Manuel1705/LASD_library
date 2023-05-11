#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo
{
    int value;
} nodo;
typedef struct nodoList
{
    nodo *nodo;
    struct nodoList *next;
} nodoList;

typedef struct grafo
{
    int nNodi;
    nodoList *nodi;
} grafo;

typedef struct arco
{
    int weight;
    nodo *pointer;
    struct arco *next;
} arco;

// restituisce un nuovo nodo
nodo *newNodo(int value)
{
    nodo *tmp = (nodo *)malloc(sizeof(nodo));
    tmp->value = value;
    return tmp;
}
// aggiunge un arco da nodo1 a nodo 2
// void addArco(int weight, nodo *nodo1, nodo *nodo2)
// {
//     if (weight <= 0)
//     {
//         printf("Il peso dell'arco deve essere positivo");
//         return;
//     }
//     if (nodo1 != NULL && nodo2 != NULL)
//     {
//         arco *tmp = nodo1->adj;
//         if (tmp != NULL)
//         {
//             if (tmp->pointer == nodo2)
//             {
//                 printf("L'arco è già presente");
//                 return;
//             }
//             while (tmp->next != NULL)
//                 if (tmp->pointer == nodo2)
//                 {
//                     printf("L'arco è già presente");
//                     return;
//                 }
//                 else
//                 {
//                     tmp = tmp->next;
//                 }
//             tmp->next = (arco *)malloc(sizeof(arco));
//             tmp = tmp->next;
//             tmp->pointer = nodo2;
//             tmp->weight = weight;
//             tmp->next = NULL;
//             return;
//         }
//         tmp = (arco *)malloc(sizeof(arco));
//         tmp->pointer = nodo2;
//         tmp->weight = weight;
//         tmp->next = NULL;
//     }
// }
void addNodo(grafo *g, int value)
{
    if (g != NULL)
    {
        nodo *tmp = (nodo *)malloc(sizeof(nodo));
        tmp->value = value;
        nodoList *tmpList = (nodoList *)malloc(sizeof(nodoList));
        tmpList->next = g->nodi;
        g->nodi = tmpList;
        tmpList->nodo = tmp;
    }
}
void stampaGrafo(grafo *g)
{
    printf("\nGrafo: ");
    nodoList *tmp = g->nodi;
    while (tmp != NULL)
    {
        printf("%d ", tmp->nodo->value);
        tmp = tmp->next;
    }
}
int main()
{
    srand(time(NULL));
    grafo *g = (grafo *)malloc(sizeof(grafo));
    g->nNodi = 0;
    printf("Inserici numero nodi: ");
    int nNodi;
    scanf("%d", &nNodi);
    for (int i = 0; i < nNodi; i++)
    {
        int value;
        printf("\nInserici il valore del %d nodo: ", i + 1);
        scanf("%d", &value);
        addNodo(g, value);
    }
    stampaGrafo(g);
}
