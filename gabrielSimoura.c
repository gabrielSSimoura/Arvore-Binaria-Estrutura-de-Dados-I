#define _GNU_SOURCE

#include "arv.h"

/*Preenche uma arvore com a expressao lida;
 *inputs: (Arvore *arvore), (char *expressao);
 *outputs: (Arvore*) devidamente inicializado e alocado;
 *pré-condição: (Arvore*) existente;
 *pós-condição: (Arvore*) de retorno existente;
*/
Arvore *preencherArvore(Arvore *arvore, char *expressao);

/*Calcula a expressao da arvore;
 *inputs: (Arvore *arvore);
 *outputs: float ;
 *pré-condição: (Arvore*) existente;
 *pós-condição: float de retorno existente;
*/
float ResultadoExpressao(Arvore *arvore);

int main(int argc, char const *argv[])
{
    FILE *fileEntrada = fopen("entrada.txt", "r");

    if (fileEntrada == NULL)
    {
        printf("ERRO: O arquivo não foi aberto!\n");
        return 0;
    }

    FILE *fileSaida = fopen("saida.txt", "w");

    if (fileSaida == NULL)
    {
        printf("ERRO: O arquivo de saída não foi aberto!\n");
        return 0;
    }

    float resultado;

    //Ler a expressão, armazenar array;
    char *expressao = (char *)malloc(sizeof(char) * 300);

    //Criando Arvore;
    Arvore *arvore;

    while (fscanf(fileEntrada, "%s", expressao) != EOF)
    {
        resultado = 0.0;
        arvore = inicializaArvore();
        arvore = preencherArvore(arvore, expressao);

        //Calculando e imprimindo resultado da equação;
        resultado = ResultadoExpressao(arvore);
        fprintf(fileSaida, "%.2f\n", resultado);

        //Liberando espaço de memória da arvore;
        arvore = liberaArvore(arvore);
    }

    //Libera espaço de memória utilizado;
    free(expressao);
    fclose(fileEntrada);
    fclose(fileSaida);

    return 0;
}

Arvore *preencherArvore(Arvore *arvore, char *expressao)
{
    int posicao = 0;

    if (vaziaArvore(arvore))
    {
        arvore = criaArvore();
    }

    arvore = constroiArvore(arvore, expressao, &posicao);
    return arvore;
}

float ResultadoExpressao(Arvore *arvore)
{
    float resultado = 0;

    resultado = calculaEquacao(arvore);

    return resultado;
}
