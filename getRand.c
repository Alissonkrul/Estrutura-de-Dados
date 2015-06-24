#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define MAX 18

int main()
{
    int vetor[MAX], tmp[MAX];

    getArrayRand(&vetor);
    printArray(&vetor);

    printf("\n\n\n");

    copyArray(&vetor, &tmp);
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

int random(int min, int max)
{
    return rand()%(max-min+1) + min;
}
