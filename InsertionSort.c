#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int operacoes = 0;
void insertionSort(int vector[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int chave = vector[i];
        operacoes++;
        int j = i - 1;
        operacoes++;
        while (chave < vector[j] && j >= 0)
        {
            vector[j + 1] = vector[j];
            operacoes++;
            --j;
            operacoes++;
        }
        vector[j + 1] = chave;
        operacoes++;
    }
}
int main()
{
    int tamanho = 50;
    int vetor[tamanho];
    clock_t begin = clock();
    insertionSort(vetor, tamanho);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo: %f", time_spent);
    printf("\nOperacoes: %i", operacoes);
}
