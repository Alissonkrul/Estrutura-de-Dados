#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
#define MAX 300

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
printf("\n______________________________________________________");
printf("\nMetodo: %s",tabela.nome);
printf("\nNumero de Trocas: %d",tabela.numeroTrocas);
printf("\nNumero de Comparacoes: %d",tabela.numeroComparacoes);
printf("\nTempo Total: %lf seg",tabela.tempoTotal);

printf("\nNumero de comparacoes melhor caso: %d",tabela.comparacoesMelhorCaso);
printf("\nNumero de trocas Melhor Caso: %d",tabela.trocasMelhorCaso);
printf("\nTempo melhor caso: %lf seg",tabela.tempoMelhorCaso);

printf("\nNumero de comparacoes Pior caso: %d",tabela. comparacoesPiorCaso);
printf("\nNumero de trocas Pior caso: %d",tabela.trocasPiorCaso);
printf("\nTempo pior caso : %lf seg",tabela.tempoPiorCaso);
printf("\n________________________________________________________\n");
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


struct Resultado bubbleSort(int *vetor)
{
  int swap = 0;
  int end = MAX - 1;
  int i;
  clock_t tInicial, tFinal;
  double tempo;
  int aux;

  struct Resultado resultado;

  resultado.comparacoes = 0;
  resultado.trocas = 0;
  tInicial = clock();

  while(end > 0 || swap == 1)
  {
      swap = 0;

      for (i = 0; i < end; i++)
      {
          resultado.comparacoes++;  // Numero de comparações ++

          if(vetor[i] > vetor[i+1])
          {
              resultado.trocas++;   // Numero de trocas ++

              aux = vetor[i];
              vetor[i] = vetor[i+1];
              vetor[i+1] = aux;

              swap = 1;
          }
      }
      end--;
  }
  tFinal = clock(); // tempo fina
  resultado.tempo = ( (double) (tFinal - tInicial) ) / CLOCKS_PER_SEC; ;
  return resultado;
}


int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct Resultado resultado;
    struct Tabela tabelaBubble;
    //int vetor[] = {7,3,2,1,5,6,4,8,9,10};
    int vetor[MAX];
    int vetorShell[MAX];
    int vetorBubble[MAX];
    int vetorLuke[MAX];
    getArrayRand(&vetor);
    copyArray(&vetor, vetorBubble);
    copyArray(&vetor, vetorShell);
    copyArray(&vetor, vetorLuke);


//-------------------------------------- Buble ---------------------------------------------//
        tabelaBubble.nome = "Bubble";
    // Normal Buble
        resultado = bubbleSort(vetorBubble);
        tabelaBubble.numeroComparacoes = resultado.comparacoes ;
        tabelaBubble.tempoTotal = resultado.tempo;
        tabelaBubble.numeroTrocas = resultado.trocas;

    // Melhor Buble
        resultado = bubbleSort(vetorBubble);
        tabelaBubble.comparacoesMelhorCaso = resultado.comparacoes ;
        tabelaBubble.tempoMelhorCaso = resultado.tempo;
        tabelaBubble.trocasMelhorCaso = resultado.trocas;

    //Inverter array
        invertArray(&vetorBubble);
    // Pior Buble
        resultado = bubbleSort(vetorBubble);
        tabelaBubble.comparacoesPiorCaso = resultado.comparacoes ;
        tabelaBubble.tempoPiorCaso = resultado.tempo;
        tabelaBubble.trocasPiorCaso = resultado.trocas;
        imprimeResultado(tabelaBubble);
//-------------------------------------- Buble ---------------------------------------------//

return 0;
}


