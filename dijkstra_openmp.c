#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <omp.h>

#define V 6

int grafo[V][V] = {
		{0, 4, 0, 0, 0, 0},
		{4, 0, 8, 0, 0, 0},
		{0, 8, 0, 7, 0, 4},
		{0, 0, 7, 0, 9, 14},
		{0, 0, 0, 9, 0, 10},
		{0, 0, 4, 14, 10, 0}};

int distancias[V];
int visitados[V];

int encontrarVerticeMaisProximo()
{
	int distanciaMinima = INT_MAX;
	int verticeMaisProximo;

	int i;

  //#pragma omp parallel for
	for (i = 0; i < V; i++)
	{
		if (!visitados[i] && distancias[i] <= distanciaMinima)
		{
      //#pragma omp critical  // muito perto do "for" a fun‡ao volta a ser sequencial
			{
				distanciaMinima = distancias[i];
				verticeMaisProximo = i;
			}
		}
	}

	return verticeMaisProximo;
}

void dijkstra(int verticeInicial)
{
	int i;

	for (i = 0; i < V; i++)
	{
		distancias[i] = INT_MAX;
		visitados[i] = 0;
	}

	distancias[verticeInicial] = 0;

  #pragma omp parallel num_threads(1)
	{
		int verticeAtual;

		for (i = 0; i < V - 1; i++)
		{
      #pragma omp single
			{
				verticeAtual = encontrarVerticeMaisProximo();
				visitados[verticeAtual] = 1;
			}

      #pragma omp for
			for (int j = 0; j < V; j++)
			{
				//printf("j: %d\nvertice: %d\n",j,verticeAtual);
				//!erro
				if (!visitados[j] && grafo[verticeAtual][j] != 0 && distancias[verticeAtual] != INT_MAX)
				{
					int novaDistancia = distancias[verticeAtual] + grafo[verticeAtual][j];
					if (novaDistancia < distancias[j])
					{
            #pragma omp critical
						{
							distancias[j] = novaDistancia;
						}
					}
				}
			}
		}
	}
}

int main()
{
	int verticeInicial = 0;
	clock_t inicio = clock();

	dijkstra(verticeInicial);

	printf("V‚rtice\tDistƒncia M¡nima\n");
	for (int i = 0; i < V; i++)
	{
		printf("%d\t%d\n", i, distancias[i]);
	}

	clock_t fim = clock();

	double tempoExecucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
	printf("Tempo de execu‡Æo: %f segundos\n", tempoExecucao);

	return 0;
}
