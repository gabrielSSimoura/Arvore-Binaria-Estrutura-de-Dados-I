#define _GNU_SOURCE
#include "arv.h"
#include <string.h>

#define INIC -1234

struct arvore
{
    char info;
    int numero;
    struct arvore *esquerda;
    struct arvore *direita;
};

//Cria uma árvore vazia;
Arvore *inicializaArvore(void)
{
    return NULL;
}

Arvore *criaArvore(void)
{
    Arvore *arvore = (Arvore *)malloc(sizeof(Arvore));

    arvore->info = '\0';
    arvore->numero = INIC;
    arvore->esquerda = arvore->direita = NULL;

    return arvore;
}

//Verifica se o elemento é um operador
static int verificaOperador(char elemento)
{

    if (elemento == '*' || elemento == '+' || elemento == '-' || elemento == '/')
        return 1;

    return 0;
}

//Verifica se o elemento é um numero
static int verificaNumero(char elemento)
{
    if (elemento >= '0' && elemento <= '9')
    {
        return 1;
    }
    return 0;
}

//Retorna numero (caso exista) da arvore;
int retornaNumero(Arvore *arvore)
{
    return arvore->numero;
}

//Retorna operador (caso exista) da arvore;
char retornaOperador(Arvore *arvore)
{
    return arvore->info;
}

//Retorna o status da árvore, se está vazia ou não
int vaziaArvore(Arvore *arvore)
{
    if (arvore == NULL)
    {
        return 1;
    }

    return 0;
}

//Imprime árvore
void imprimeArvore(Arvore *arvore)
{

    if (!vaziaArvore(arvore))
    {
        imprimeArvore(arvore->esquerda);

        if (retornaNumero(arvore) != INIC)
        {
            printf(" %d", retornaNumero(arvore));
        }
        else if (verificaOperador(arvore->info))
        {
            printf(" %c", retornaOperador(arvore));
        }

        imprimeArvore(arvore->direita);
    }
}

//Libera o espaço de memória ocupado pela árvore
Arvore *liberaArvore(Arvore *arvore)
{
    if (!vaziaArvore(arvore))
    {
        liberaArvore(arvore->esquerda);
        liberaArvore(arvore->direita);
        free(arvore);
    }
    return NULL;
}

Arvore *insereNumeroArvore(Arvore *arvore, int numero)
{
    arvore->numero = numero;
    return arvore;
}

Arvore *insereOperadorArvore(Arvore *arvore, char operador)
{
    arvore->info = operador;
    return arvore;
}

//-----------------------------------------------------------------//

Arvore *constroiArvore(Arvore *arvore, char *expressao, int *posicao)
{
    int ehNumero = 0;

    //Se for o parenteses
    if (*(expressao + *posicao) == '(')
    {
        // Se for o parenteses do número, ex: (100), ou se o número for negativo, ex: (-100)
        if ((verificaNumero(*(expressao + *posicao + 2) == 1) && *(expressao + *posicao + 1) == '-'))
        {
            ehNumero = 1;
            *posicao = *posicao + 1;
        }

        //Se for inicio da expressão
        else if (*(expressao + *posicao) == '(')
        {
            *posicao = *posicao + 1;
            if (vaziaArvore(arvore->esquerda))
            {
                arvore->esquerda = criaArvore();
            }

            arvore->esquerda = constroiArvore(arvore->esquerda, expressao, posicao);
        }
    }

    //Se for o final da expressão
    if (*(expressao + *posicao) == ')')
    {
        *posicao = *posicao + 1;
        return arvore;
    }

    //Se for número, ou se for sinal negativo do número;
    if (verificaNumero(*(expressao + *posicao)) || ehNumero)
    {
        int num = 0, ehNegativo = 0;
        int c = '\0';

        //Se for negativo;
        if (*(expressao + *posicao) == '-')
        {
            *posicao = *posicao + 1;
            ehNegativo = 1;
        }

        while (verificaNumero(*(expressao + *posicao)))
        {
            num = num * 10;

            c = *(expressao + *posicao);
            num = num + (c - '0');

            *posicao = *posicao + 1;
        }

        if (ehNegativo)
        {
            num = num * -1;
        }

        arvore = insereNumeroArvore(arvore, num);
        *posicao = *posicao + 1;

        ehNumero = 0;
        ehNegativo = 0;
        return arvore;
    }

    //Se for operador;
    else if (verificaOperador(*(expressao + *posicao)))
    {
        arvore = insereOperadorArvore(arvore, *(expressao + *posicao));
        *posicao = *posicao + 1;

        if (vaziaArvore(arvore->direita))
        {
            arvore->direita = criaArvore();
        }
        arvore->direita = constroiArvore(arvore->direita, expressao, posicao);
    }

    return arvore;
}

float calculaEquacao(Arvore *arvore)
{
    float valorEsquerda = 0.0, valorDireita = 0.0;

    if (vaziaArvore(arvore))
    {
        return 0;
    }

    //Se for um número;
    if (vaziaArvore(arvore->esquerda) && vaziaArvore(arvore->direita))
    {
        return arvore->numero;
    }

    //Calcular à esquerda
    valorEsquerda = calculaEquacao(arvore->esquerda);

    //Calcular à direita
    valorDireita = calculaEquacao(arvore->direita);

    //Se for operador;
    //Verificar o operador
    if (arvore->info == '+')
    {
        valorEsquerda = valorEsquerda + valorDireita;
        return valorEsquerda;
    }
    else if (arvore->info == '-')
    {
        valorEsquerda = valorEsquerda - valorDireita;
        return valorEsquerda;
    }
    else if (arvore->info == '*')
    {
        valorEsquerda = valorEsquerda * valorDireita;
        return valorEsquerda;
    }
    else if (arvore->info == '/')
    {
        valorEsquerda = valorEsquerda / valorDireita;
        return valorEsquerda;
    }

    return valorEsquerda;
}
