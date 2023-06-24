#include <stdio.h>
#include <limits.h>
#include <omp.h>

#define V 6 // Número de vértices no grafo

int minDistance(int dist[], int sptSet[])
{
    int min = INT_MAX, min_index;

    #pragma omp parallel for
    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == 0 && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(int dist[])
{
    printf("Vértice \t Distância da origem\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];     // Vetor de distâncias mínimas
    int sptSet[V]; // Conjunto de vértices já processados

    // Inicializa todas as distâncias como infinito e sptSet[] como falso
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    // A distância do vértice de origem para ele mesmo é sempre 0
    dist[src] = 0;

    // Encontra o caminho mais curto para todos os vértices
    for (int count = 0; count < V - 1; count++)
    {
        // Seleciona o vértice de distância mínima do conjunto de vértices ainda não processados
        int u = minDistance(dist, sptSet);

        // Marca o vértice selecionado como processado
        sptSet[u] = 1;

        // Atualiza o valor das distâncias dos vértices adjacentes ao vértice selecionado
        #pragma omp parallel for
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Imprime o vetor de distâncias
    printSolution(dist);
}

int main()
{
    int graph[V][V] = {
		{0, 4, 0, 0, 0, 0},
		{4, 0, 8, 0, 0, 0},
		{0, 8, 0, 7, 0, 4},
		{0, 0, 7, 0, 9, 14},
		{0, 0, 0, 9, 0, 10},
		{0, 0, 4, 14, 10, 0}};

    dijkstra(graph, 0); // Encontra o caminho mais curto a partir do vértice 0

    return 0;
}