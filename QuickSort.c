#include <stdio.h>
#include <time.h>

#define TAM 500000

int contador = 0;

void QuickSort(int X[], int IniVet, int FimVet)
{
    int i, j, pivo, aux;

    i = IniVet;
    j = FimVet;
    contador += 5;

    pivo = X[(IniVet + FimVet) / 2];
    while (i <= j)
    {
        while (X[i] < pivo)
        {
            i++;
            contador += 1;
        }
        while (X[j] > pivo)
        {
            j--;
            contador += 1;
        }
        if (i <= j)
        {
            aux = X[i];
            X[i] = X[j];
            X[j] = aux;
            i++;
            j--;
            contador += 5;
        }
    }

    if (IniVet < j)
    {
        QuickSort(X, IniVet, j);
    }

    if (i < FimVet)
    {
        QuickSort(X, i, FimVet);
    }
}

int main()
{

    int my_array[TAM];
    srand(0);
    int z;
    for (z = 0; z < TAM; z++)
    {
        my_array[z] = rand();
    }

    int vetor_ordenado[TAM];
    for (int p = 0; p < TAM; p++)
    {
        vetor_ordenado[p] = p;
    }

    int vetor_ordenado_traz_pra_frente[TAM];
    int j = 0;
    for (int p = TAM; p > 0; p--)
    {
        vetor_ordenado_traz_pra_frente[j] = p;
        j++;
    }
    clock_t begin = clock();
    
    QuickSort(my_array, 0, TAM - 1);
    
    printf("\n");
    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTempo de execucao foi de: %lf", time_spent);
    printf("\nNumero de interacoes foi de %d", contador);
    return 0;
}
