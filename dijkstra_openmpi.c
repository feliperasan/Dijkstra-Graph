// teste gabriel

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <mpi.h>

#define V 25

// Grafo representado por uma Matriz de Adjac�ncia ponderada(com arestas valoradas).
int grafo[V][V] = {
    {0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {10, 0, 8, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 0, 0, 9, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 5, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 9, 0, 0, 8, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 10, 0, 8, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 12, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 12, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 6, 0, 8, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

int distancias[V];
int visitados[V];

int encontrarVerticeMaisProximo(int verticeInicial, int ultimoVertice)
{
  int distanciaMinima = INT_MAX;
  int verticeMaisProximo;

  for (int i = verticeInicial; i < ultimoVertice; i++)
  {
    if (!visitados[i] && distancias[i] <= distanciaMinima)
    {
      distanciaMinima = distancias[i];
      verticeMaisProximo = i;
    }
  }
  return verticeMaisProximo;
}

void dijkstra(int verticeInicial, int ultimoVertice)
{
  int verticeAtual;

  for (int i = 0; i < V; i++)
  {
    distancias[i] = INT_MAX;
    visitados[i] = 0;
  }

  distancias[verticeInicial] = 0;

  for (int i = 0; i < V - 1; i++)
  {
    verticeAtual = encontrarVerticeMaisProximo(verticeInicial, ultimoVertice);
    visitados[verticeAtual] = 1;

    for (int j = 0; j < V; j++)
    {
      if (!visitados[j] && grafo[verticeAtual][j] != 0 && distancias[verticeAtual] != INT_MAX)
      {
        int novaDistancia = distancias[verticeAtual] + grafo[verticeAtual][j];
        if (novaDistancia < distancias[j])
          distancias[j] = novaDistancia;
      }
    }
  }
}

int main(int argc, char *argv[])
{
  int numeroDeProcessos, rank;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numeroDeProcessos);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  int verticesPorProcessos = V / numeroDeProcessos;
  int verticeInicial = rank * verticesPorProcessos;
  int ultimoVertice = (rank == numeroDeProcessos - 1) ? V : (rank + 1) * verticesPorProcessos;

  double inicio = MPI_Wtime();

  dijkstra(verticeInicial, ultimoVertice);

  MPI_Allreduce(MPI_IN_PLACE, distancias, V, MPI_INT, MPI_MIN, MPI_COMM_WORLD);

  double fim = MPI_Wtime();
  double execucao = fim - inicio;

  if (rank == 0)
  {
    printf("Vertice\tDistancia Minima\n");
    for (int i = 0; i < V; i++)
    {
      printf("%d\t%d\n", i, distancias[i]);
    }

    printf("Tempo de execucao: %f segundos\n", execucao);
  }

  MPI_Finalize();

  return 0;
}