#define _GNU_SOURCE

#include "arv.h"

Arvore *preencherArvore(Arvore *arvore, char *expressao);
float ResultadoExpressao(Arvore *arvore);

int main(int argc, char const *argv[])
{
    FILE *fileEntrada = fopen(argv[1], "r");

    if (fileEntrada == NULL)
    {
        printf("ERRO: O arquivo não foi aberto!\n");
        return 0;
    }

    //Ler a expressão, armazenar array;
    char *expressao = (char *)malloc(sizeof(char) * 300);
    fscanf(fileEntrada, "%s", expressao);

    //Criando Arvore;
    Arvore *arvore = criaArvore();

    arvore = preencherArvore(arvore, expressao);

    //Calculando e imprimindo resultado da equação;
    printf("%.2f\n", ResultadoExpressao(arvore));

    //Liberando espaço de memória da arvore

    liberaArvore(arvore);
    free(expressao);
    fclose(fileEntrada);

    return 0;
}

Arvore *preencherArvore(Arvore *arvore, char *expressao)
{
    int posicao = 0;

    arvore = constroiArvore(arvore, expressao, &posicao);
    return arvore;
}

float ResultadoExpressao(Arvore *arvore)
{
    float resultado = 0;

    resultado = calculaEquacao(arvore);

    return resultado;
}
