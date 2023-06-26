# Algoritmo de Dijkstra: Sequencial, OpenMP e OpenMPI

<p align="center">
  <img src="https://ascom.ufpa.br/images/Brasao/UFPA.png" width=100px/>
</p>

## Integrantes do Trabalho
- Felipe Rafael dos Santos Barbosa - PPGCC
- Gabriel de Souza da Silva - FACOMP

## Resumo

## Como Executar
1. Faça um clone do repositório, e siga para a pasta raiz.

Execute um dos seguintes códigos de acordo a preferência da análise dos resultados:

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
gcc dijkstra_openmpi.c -o openmpi.o && mpirun -np X ./openmpi.o # X é o número de processos a serem executados.
```

## Links
<a href="https://www.overleaf.com/read/cyfxhtzwmkjs" 
target="_blank">
  <p> &#x1F4C3; OverLeaf</p>
</a>