#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
#define MAX 30000

struct Tabela{

char *nome;
double tempoMedio;
double tempoTotal;
long int numeroTrocas;
long int numeroComparacoes;
long int comparacoesMelhorCaso;
long int trocasMelhorCaso;
long int comparacoesPiorCaso;
double tempoMelhorCaso;
long int trocasPiorCaso;
double tempoPiorCaso;

};

struct Resultado{
int comparacoes;
int trocas;
float tempo;
};

void imprimeResultado(struct Tabela tabela)
{
printf("\n______________________________________________________\n");
printf("\n\tMetodo: %s",tabela.nome);
printf("\n\n\tNumero de Comparacoes: %d",tabela.numeroComparacoes);
printf("\n\tNumero de Trocas     : %d",tabela.numeroTrocas);
printf("\n\tTempo: %1f seg",tabela.tempoTotal);

printf("\n\n\n                     MELHOR CASO                    \n");

printf("\n\tNumero de comparacoes: %d",tabela.comparacoesMelhorCaso);
printf("\n\tNumero de trocas     : %d",tabela.trocasMelhorCaso);
printf("\n\tTempo: %1f seg",tabela.tempoMelhorCaso);

printf("\n\n\n                       PIOR CASO                    \n");

printf("\n\tNumero de comparacoes: %d",tabela. comparacoesPiorCaso);
printf("\n\tNumero de trocas     : %d",tabela.trocasPiorCaso);
printf("\n\tTempo: %1f seg",tabela.tempoPiorCaso );
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


void bubbleSort(int *vetor, struct Resultado *resultado)
{
  int swap = 1;
  int end = MAX - 1;
  int i;
  int aux;

  while(end > 0 && swap == 1)
  {
      swap = 0;

      for (i = 0; i < end; i++)
      {
          resultado->comparacoes++;  // Numero de comparações ++

          if(vetor[i] > vetor[i+1])
          {
              resultado->trocas++;   // Numero de trocas ++

              aux = vetor[i];
              vetor[i] = vetor[i+1];
              vetor[i+1] = aux;

              swap = 1;
          }
      }
      end--;
  }

}

void shellSort(int *vetor, struct Resultado *resultado)
{
   int i = (MAX - 1) / 2;
   int chave, k, aux;

   while(i != 0)
   {
      do
      {
         chave = 1;
         for(k = 0; k < MAX - i; ++k)
         {
            resultado->comparacoes++;  // Numero de comparações ++

            if(vetor[k] > vetor[k + i])
            {
                resultado->trocas++;   // Numero de trocas ++

                aux = vetor[k];
                vetor[k] = vetor[k + i];
                vetor[k + i] = aux;
                chave = 0;
            }

         }
      }while(chave == 0);
      i = i / 2;
   }
}

void quickSort(int *vetor, int left, int right, struct Resultado *resultado)
{
    int i, j, x, y;

    i = left;
    j = right;
    x = vetor[(left + right) / 2];

    while(i <= j) {
        while(vetor[i] < x && i < right) {
            i++;
        }
        while(vetor[j] > x && j > left) {
            j--;
        }

        resultado->comparacoes++;

        if(i <= j) {

            resultado->trocas++;

            y = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = y;
            i++;
            j--;
        }
    }

    if(j > left) {
        quickSort(vetor, left, j, resultado);
    }
    if(i < right) {
        quickSort(vetor, i, right, resultado);
    }
}

struct Resultado callOrderMethod(int *vetor, int op){

  struct Resultado resultado;

  resultado.comparacoes = 0;
  resultado.trocas = 0;

  clock_t tInicial, tFinal;

  tInicial = clock();
  switch(op)
  {
        case 0:
            bubbleSort(vetor, &resultado);
            break;

        case 1:
            shellSort(vetor, &resultado);
            break;

        case 2:
            quickSort(vetor, 0 , MAX, &resultado);
            break;
  }

  tFinal = clock(); // tempo fina
  resultado.tempo = ( (double) (tFinal - tInicial) ) / CLOCKS_PER_SEC;
  return resultado;
};

void preencheTabela(struct Tabela *tabela, char *nome, struct Resultado resultado, int caso)
{
    tabela->nome = nome;
    switch(caso)
    {
        case 0:
            tabela->numeroComparacoes = resultado.comparacoes ;
            tabela->tempoTotal = resultado.tempo;
            tabela->numeroTrocas = resultado.trocas;
            break;
        case 1:
            tabela->comparacoesMelhorCaso = resultado.comparacoes ;
            tabela->tempoMelhorCaso = resultado.tempo;
            tabela->trocasMelhorCaso = resultado.trocas;
            break;
        case 2:
            tabela->comparacoesPiorCaso = resultado.comparacoes ;
            tabela->tempoPiorCaso = resultado.tempo;
            tabela->trocasPiorCaso = resultado.trocas;
            break;
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct Resultado resultado;
    struct Tabela tabela;
    //int vetor[] = {7,3,2,1,5,6,4,8,9,10};
    int vetor[MAX];
    int vetorShell[MAX];
    int vetorBubble[MAX];
    int vetorQuick[MAX];
    getArrayRand(&vetor);
    copyArray(&vetor, vetorBubble);
    copyArray(&vetor, vetorShell);
    copyArray(&vetor, vetorQuick);

    resultado = callOrderMethod(&vetorBubble, 0); //chama o método bubble;
    preencheTabela(&tabela, "BubbleSort", resultado, 0); // preenche a tabela no caso normal;

    resultado = callOrderMethod(&vetorBubble, 0); //chama o método bubble;
    preencheTabela(&tabela, "BubbleSort", resultado, 1); // preenche a tabela no melhor caso;

    invertArray(&vetorBubble);

    resultado = callOrderMethod(&vetorBubble, 0); //chama o método bubble;
    preencheTabela(&tabela, "BubbleSort", resultado, 2); // preenche a tabela no pior caso;

    imprimeResultado(tabela);



    //*

    resultado = callOrderMethod(&vetorShell, 1); //chama o método bubble;
    preencheTabela(&tabela, "ShellSort", resultado, 0); // preenche a tabela no caso normal;

    resultado = callOrderMethod(&vetorShell, 1); //chama o método bubble;
    preencheTabela(&tabela, "ShellSort", resultado, 1); // preenche a tabela no melhor caso;

    invertArray(&vetorShell);
    resultado = callOrderMethod(&vetorShell, 1); //chama o método bubble;
    preencheTabela(&tabela, "ShellSort", resultado, 2); // preenche a tabela no pior caso;

    imprimeResultado(tabela);




    resultado = callOrderMethod(&vetorQuick, 2); //chama o método bubble;
    preencheTabela(&tabela, "QuickSort", resultado, 0); // preenche a tabela no caso normal;

    resultado = callOrderMethod(&vetorQuick, 2); //chama o método bubble;
    preencheTabela(&tabela, "QuickSort", resultado, 1); // preenche a tabela no melhor caso;

    invertArray(&vetorQuick);
    resultado = callOrderMethod(&vetorQuick, 2); //chama o método bubble;
    preencheTabela(&tabela, "QuickSort", resultado, 2); // preenche a tabela no pior caso;

    imprimeResultado(tabela);
    //*/

return 0;
}


