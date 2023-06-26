#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Nome do arquivo para armazenar o valor de saída
    char outputFileName[] = "saida.txt";
    // Abrir o arquivo para escrita
    FILE *outputFile = fopen(outputFileName, "a");
    if (outputFile == NULL)
    {
        printf("Erro ao abrir o arquivo de saída.\n");
        return 1;
    }

    // Definir o script em C
    char srcipt[50] = "./dijkstra_openmp";

    for (int i; i < 100; i++)
    {

        char command[200];
        sprintf(command, "export OMP_NUM_THREADS=%d; %s", 4, srcipt);

        //printf("%s", command);

        // Executar o script em C e redirecionar a saída para o arquivo
        FILE *cmd = popen(command, "r");
        if (cmd == NULL)
        {
            printf("Erro ao executar o script.\n");
            return 1;
        }

        // Ler o valor de saída do script e gravar no arquivo
        char outputValue[100];
        fgets(outputValue, sizeof(outputValue), cmd);
        fprintf(outputFile, "%s", outputValue);

        pclose(cmd);
    }

    // Fechar o arquivo e o comando
    fclose(outputFile);

    printf("Valor de saída armazenado em %s.\n", outputFileName);

    return 0;
}