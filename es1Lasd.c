#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct edge
{
    int weight;
    int node;
    struct edge *next;
} edge;

typedef struct graph
{
    int size;
    edge **adj;
} graph;
void resetIntVector(int *v, int size)
{
    for (int i = 0; i < size; i++)
        v[i] = 0;
}
void sumWeights(int *weights, graph *g, int node)
{
    if (g->size <= node)
        return;
    edge *e = g->adj[node];
    while (e != NULL)
    {
        weights[e->node] += e->weight;
        e = e->next;
    }
}
void sumWeightsIntersection(int *weights1, int *weights2, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (weights1[i] != 0 && weights2[i] != 0 && ((weights1[i] + weights2[i]) % 2) == 0)
            weights1[i] = weights1[i] + weights2[i];
        else
            weights1[i] = 0;
    }
}
edge *newEdge(int node, int weight)
{
    edge *e = (edge *)malloc(sizeof(edge));
    e->node = node;
    e->weight = weight;
    e->next = NULL;
    return e;
}

graph *newEmptyGraph()
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->size = 0;
    g->adj = NULL;
    return g;
}
graph *newGraph(int size)
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->size = size;
    g->adj = (edge **)malloc(size * sizeof(edge *));
    for (int i = 0; i < size; i++)
        g->adj[i] = NULL;
    return g;
}

void printGraph(graph *g)
{
    if (g == NULL)
    {
        printf("\n\033[1;31mEmpty Graph\n");
        return;
    }

    printf("\n\033[1;31mGraph:\n");
    for (int i = 0; i < g->size; i++)
    {
        edge *e = g->adj[i];
        printf("\033[1;34m%d: ", i);
        while (e)
        {
            printf("\033[1;33m--(\033[1;37m%d\033[1;33m)-->[\033[1;37m%d\033[1;33m]\t", e->weight, e->node);
            e = e->next;
        }
        printf("\n");
    }
}
graph *newRandomGraph(int size)
{
    graph *g = newGraph(size);
    // nodes scrolling
    for (int n = 0; n < size; n++)
    {
        // edges scrolling
        for (int p = 0; p < size; p++)
        {
            // randomly choosing whether to create a border
            if (rand() % 2 == 0)
            {
                edge *e = newEdge(p, rand() % 2 + 1);
                // head insert
                e->next = g->adj[n];
                g->adj[n] = e;
            }
        }
    }
    return g;
}
graph *graphUnion(graph *g1, graph *g2)
{
    int size;
    if (g1->size > g2->size)
        size = g1->size;
    else
        size = g2->size;

    graph *g3 = newGraph(size);
    int *weightSums = (int *)malloc(sizeof(int) * size);

    //  nodes scrolling
    for (int n = 0; n < size; n++)
    {
        resetIntVector(weightSums, size);
        sumWeights(weightSums, g1, n);
        sumWeights(weightSums, g2, n);
        // edges scrolling
        for (int p = 0; p < size; p++)
        {
            // if the edge exists
            if (weightSums[p] != 0)
            {

                edge *e = newEdge(p, weightSums[p]);
                // head insert
                e->next = g3->adj[n];
                g3->adj[n] = e;
            }
        }
    }
    free((void *)weightSums);
    return g3;
}
graph *graphIntersection(graph *g1, graph *g2)
{
    int size;
    if (g1->size > g2->size)
        size = g1->size;
    else
        size = g2->size;

    graph *g3 = newGraph(size);
    int *weightSums1 = (int *)malloc(sizeof(int) * size);
    int *weightSums2 = (int *)malloc(sizeof(int) * size);
    //  nodes scrolling
    for (int n = 0; n < size; n++)
    {
        resetIntVector(weightSums1, size);
        resetIntVector(weightSums2, size);
        sumWeights(weightSums1, g1, n);
        sumWeights(weightSums2, g2, n);
        sumWeightsIntersection(weightSums1, weightSums2, size);
        // edges scrolling
        for (int p = 0; p < size; p++)
        {
            // if the edge exists
            if (weightSums1[p] != 0)
            {

                edge *e = newEdge(p, weightSums1[p]);
                // head insert
                e->next = g3->adj[n];
                g3->adj[n] = e;
            }
        }
    }
    free((void *)weightSums1);
    free((void *)weightSums2);
    return g3;
}
int main()
{
    srand(time(NULL));
    graph *g1 = newRandomGraph(3);
    graph *g2 = newRandomGraph(3);
    printGraph(g1);
    printf("\n");
    printGraph(g2);
    printf("\nUnion");
    graph *g3 = graphUnion(g1, g2);
    printGraph(g3);
    printf("\nIntersection");
    graph *g4 = graphIntersection(g1, g2);
    printGraph(g4);
}
