#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define MAX 10

int main()
{
    int vetor[MAX], tmp[MAX];

    getArrayRand(&vetor);
    printArray(&vetor);

    printf("\n\n\n");

    copyArray(&vetor, &tmp);
    printArray(&tmp);


    printf("\n\n\n");

    invertArray(&tmp);
    printArray(&tmp);


}

int getArrayRand(int *vetor)
{
    int i =0;
    for(i; i < MAX ; i++)
        vetor[i] = random(0,999);
}

void printArray( int *vetor)
{
    int i =0;
    for(i; i < MAX ; i++)
        printf("%d, ", vetor[i]);
}

void copyArray( int *from, int *to)
{
    int i =0;
    for(i; i < MAX ; i++)
        to[i] = from[i];
}

void invertArray( int *vetor)
{
    int aux, i=0, range = MAX -1;

    for(i; i < MAX/2; i++)
    {
        aux = vetor[i];
        vetor[i] = vetor[range];
        vetor[range] = aux;

        range--;
    }

}

int random(int min, int max)
{
    return rand()%(max-min+1) + min;
}
