#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Tabela{
char *nome;
float tempotrocas;
float tempoComparacoes;
float tempoMedio;
float tempoTotal;
int comparacoesMelhorCaso;
int trocasMelhorCaso;
int comparacoesPiorCaso;
float tempoMelhorCaso;
int trocasPiorCaso;
float tempoPiorCaso;
};

void imprimeResultado(struct Tabela tabela)
{
printf("\n______________________________________________________");
printf("\nMetodo: %s",tabela.nome);

printf("\nTempo medio de Trocas: %.3f",tabela.tempotrocas);
printf("\nTempo medio de Comparacoes: %.3f",tabela.tempoComparacoes);
printf("\nTempo medio de ordenacao: %.3f",tabela.tempoMedio);
printf("\nTempo medio Tempo Total: %.3f",tabela.tempoTotal);

printf("\nNumero de comparacoes melhor caso: %d",tabela.comparacoesMelhorCaso);
printf("\nNumero de trocas Melhor Caso: %d",tabela.trocasMelhorCaso);
printf("\nTempo melhor caso: %f",tabela.tempoMelhorCaso);

printf("\nNumero de comparacoes Pior caso: %d",tabela. comparacoesPiorCaso);
printf("\nNumero de trocas Pior caso: %d",tabela.trocasPiorCaso);
printf("\nTempo pior caso : %.3f",tabela.tempoPiorCaso);

printf("\n________________________________________________________\n");
}


int main()
{
    setlocale(LC_ALL, "Portuguese");
    struct Tabela tabela;
    tabela.nome ="Alisson";

    tabela.comparacoesMelhorCaso = 1;
    tabela.trocasMelhorCaso = 1;
    tabela.tempoMelhorCaso = 0.567;

    tabela.comparacoesPiorCaso= 20;
    tabela.trocasPiorCaso = 32;
    tabela.tempoPiorCaso = 0.764;


    tabela.tempoMedio = 0.123;
    tabela.tempoTotal = 0.646;
    tabela.tempotrocas = 0.344;
    tabela.tempoComparacoes =0302;

    imprimeResultado(tabela);
    imprimeResultado(tabela);
    imprimeResultado(tabela);




    printf("Hello, 2 the world!\n");

    int i=0;

    int vetorTest[] = {7,3,2,1,5,6,4,8,9,10};

    for(i=0;i<10;i++)
        printf("%d",vetorTest[i]);


return 0;
}


