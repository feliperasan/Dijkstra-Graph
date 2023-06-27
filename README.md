# Algoritmo de Dijkstra: Sequencial, OpenMP e OpenMPI

<p align="center">
  <img src="https://ascom.ufpa.br/images/Brasao/UFPA.png" width=100px/>
</p>

## Integrantes do Trabalho
- Felipe Rafael dos Santos Barbosa - PPGCC
- Gabriel de Souza da Silva - FACOMP

## Resumo

Este artigo aborda a implementação sequencial, paralela e distribuída do algoritmo de Dijkstra em grafos. O objetivo é comparar o desempenho e a eficiência das implementações, utilizando 
linguagem C, OpenMP e OpenMPI. São apresentados conceitos básicos sobre grafos e uma descrição detalhada do algoritmo. O algoritmo de Dijkstra é utilizado para calcular o caminho de custo 
mínimo entre vértices em um grafo. O artigo também discute a programação paralela com OpenMP e a distribuição do algoritmo com MPI, além de apresentar resultados comparativos das implementações.

## Como Executar
1. Faça um clone do repositório, e siga para a pasta raiz.

2. Execute um dos seguintes códigos de acordo com a preferência de análise dos resultados:

**Sequencial:**
``` bash
# Execute
gcc dijkstra_sequencial.c -o sequencial.o && ./sequencial.o
```
**OpenMP:**
``` bash
# Execute
gcc -fopenmp dijkstra_openmp.c -o openmp.o && ./openmp.o
```
**OpenMPI:**
``` bash
# Execute
mpicc dijkstra_openmpi.c -o openmpi.o && mpirun -np X ./openmpi.o # X é o número de processos a serem executados.
```

## Links
<a href="https://www.overleaf.com/read/cyfxhtzwmkjs" 
target="_blank" style="text-decoration: none;">
  &#x1F4C3; OverLeaf
</a>
