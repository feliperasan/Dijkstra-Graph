# Algoritmo de Dijkstra: Sequencial, OpenMP e OpenMPI

## Integrantes do Trabalho
- Felipe Rafael dos Santos Barbosa - PPGCC
- Gabriel de Souza da Silva

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
  <p style="text-decoration: unset; color: white; font-size: 16px;">Ver trabalho na Integra<p>
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/latex/latex-original.svg" width=150px/>
</a>