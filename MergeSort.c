#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int operacoes = 0;
void merge(int arr[], int inicio, int meio, int fim)
{
    int i, j, k;
    operacoes++;
    int n1 = meio - inicio + 1;
    operacoes++;
    int n2 = fim - meio;
    operacoes++;
    int B[n1], C[n2];
    operacoes += 2;
    for (i = 0; i < n1; i++)
    {
        B[i] = arr[inicio + i];
        10000 Elementos 25000 Elementos 500000 Elementos 100000 Elementos 200000 Elementos 0 0.005 0.01 0.015 0.02 0.025 0.03 0.035 0.04 0.045 Melhor Caso
            Caso Medio
                Pior Caso
                    operacoes++;
    }
    for (j = 0; j < n2; j++)
    {
        C[j] = arr[meio + 1 + j];
        operacoes++;
    }
    i = 0;
    j = 0;
    k = inicio;
    operacoes += 3;
    while (i < n1 && j < n2)
    {
        if (B[i] <= C[j])
        {
            arr[k] = B[i];
            operacoes++;
            i++;
            operacoes++;
        }
        else
        {
            arr[k] = C[j];
            operacoes++;
            j++;
            operacoes++;
        }
        k++;
        operacoes++;
    }
    while (i < n1)
    {
        arr[k] = B[i];
        operacoes++;
        i++;
        operacoes++;
        k++;
        operacoes++;
    }
    while (j < n2)
    {
        arr[k] = C[j];
        operacoes++;
        j++;
        operacoes++;
        k++;
        operacoes++;
    }
}
void mergeSort(int arr[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;
        operacoes++;
        mergeSort(arr, inicio, meio);
        operacoes++;
        mergeSort(arr, meio + 1, fim);
        operacoes++;
        merge(arr, inicio, meio, fim);
        operacoes++;
    }
}
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main()
{
    int tamanho = 200000;
    operacoes++;
    int vetor[tamanho];
    operacoes++;
    int caso; // 1 Melhor - 2 Medio - 3 Pior
    caso = 3;
    if (caso == 1)
    {
        for (int k = 0; k < tamanho; k++)
        {
            vetor[k] = k;
            operacoes++;
        }
    }
    else if (caso == 2)
    {
        srand(0);
        operacoes++;
        int z;
        operacoes++;
        for (z = 0; z < tamanho; z++)
        {
            vetor[z] = rand();
            operacoes++;
        }
    }
    else if (caso == 3)
    {
        int t = 0;
        operacoes++;
        for (int k = tamanho; k > 0; k--)
        {
            vetor[t] = k;
            operacoes++;
            t++;
            operacoes++;
        }
    }
    // printArray(vetor,tamanho);
    clock_t begin = clock();
    operacoes++;
    mergeSort(vetor, 0, tamanho);
    operacoes++;
    clock_t end = clock();
    operacoes++;
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    operacoes++;
    printf("\n");
    operacoes++;
    // printArray(vetor, tamanho);
    printf("Tempo: %f", time_spent);
    operacoes++;
    printf("\nOperacoes: %i", operacoes);
    operacoes++;
}
