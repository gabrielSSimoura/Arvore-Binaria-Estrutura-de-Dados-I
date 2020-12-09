#define _GNU_SOURCE
#include "arv.h"
#include <string.h>

#define INIC -1

struct arvore
{
    char info;
    int numero;
    struct arvore *esquerda;
    struct arvore *direita;
};

/*Cria uma árvore NULL;
 *inputs: (void);
 *outputs: (Arvore*) NULL;
 *pré-condição: ;
 *pós-condição: (Arvore*) de retorno existente;
*/
Arvore *inicializaArvore(void)
{
    return NULL;
}

/*Inicializa uma àrvore;
 *inputs: (void);
 *outputs: (Arvore*) devidamente inicializado e alocado;
 *pré-condição: ;
 *pós-condição: (Arvore*) de retorno existente;
*/
Arvore *criaArvore(void)
{
    Arvore *arvore = (Arvore *)malloc(sizeof(Arvore));

    arvore->info = '\0';
    arvore->numero = INIC;
    arvore->esquerda = arvore->direita = NULL;

    return arvore;
}

/*Verifica se o elemento é um operador;
 *inputs: (char);
 *outputs: (int);
 *pré-condição: char existente;
 *pós-condição: int existente;
*/
static int verificaOperador(char elemento)
{

    if (elemento == '*' || elemento == '+' || elemento == '-' || elemento == '/')
        return 1;

    return 0;
}

/*Verifica se o elemento é um numero;
 *inputs: (char);
 *outputs: (int);
 *pré-condição: char existente;
 *pós-condição: int existente;
*/
static int verificaNumero(char elemento)
{
    if (elemento >= '0' && elemento <= '9')
    {
        return 1;
    }
    return 0;
}

/*Retorna (caso exista) número da arvore;
 *inputs: (Arvore*);
 *outputs: (int);
 *pré-condição: (Arvore*) existente;
 *pós-condição: int alocado;
*/
int retornaNumero(Arvore *arvore)
{
    return arvore->numero;
}

/*Retorna (caso exista) operador da arvore;
 *inputs: (Arvore*);
 *outputs: (char);
 *pré-condição: (Arvore*) existente;
 *pós-condição: char alocado;
*/
char retornaOperador(Arvore *arvore)
{
    return arvore->info;
}

/*Retorna o status da árvore, se está vazia ou não;
 *inputs: (Arvore*);
 *outputs: (int);
 *pré-condição: (Arvore*) existente;
 *pós-condição: int alocado;
*/
int vaziaArvore(Arvore *arvore)
{
    if (arvore == NULL)
    {
        return 1;
    }

    return 0;
}

/*Imprime árvore;
 *inputs: (Arvore*);
 *outputs: (void);
 *pré-condição: (Arvore*) existente;
 *pós-condição: ;
*/
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

/*Libera o espaço de memória ocupado pela árvore;
 *inputs: (Arvore*);
 *outputs: (Arvore*);
 *pré-condição: (Arvore*) existente;
 *pós-condição: (Arvore*) mddificada;
*/
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

/*Insere determinado numero em uma determinada arvore;
 *inputs: (Arvore*), (int numero);
 *outputs: (Arvore*);
 *pré-condição: (Arvore*) existente, numero como inteiro;
 *pós-condição: (Arvore*) mddificada, numero inserido;
*/
Arvore *insereNumeroArvore(Arvore *arvore, int numero)
{
    arvore->numero = numero;
    return arvore;
}

/*Insere determinado operador em uma determinada arvore;
 *inputs: (Arvore*), (char operador);
 *outputs: (Arvore*);
 *pré-condição: (Arvore*) existente, operador como char;
 *pós-condição: (Arvore*) mddificada, operador inserido;
*/
Arvore *insereOperadorArvore(Arvore *arvore, char operador)
{
    arvore->info = operador;
    return arvore;
}

/*Constroi a arvore a partir da equação lida, recursivamente;
 *inputs: (Arvore*), (char *expressão), (int *posição);
 *outputs: (Arvore*);
 *pré-condição: (Arvore*) existente, expressão existente, posição existente;
 *pós-condição: (Arvore*) mddificada, devidamente criada;
*/
Arvore *constroiArvore(Arvore *arvore, char *expressao, int *posicao)
{
    int ehNumero = 0;

    //Se for o parenteses
    if (*(expressao + *posicao) == '(')
    {
        // Se for o parenteses do número, ex: (100);
        if ((verificaNumero(*(expressao + *posicao + 1) == 1)))
        {
            ehNumero = 1;
            *posicao = *posicao + 1;
        }

        //Se for inicio da expressão "(":
        else if (*(expressao + *posicao) == '(')
        {
            *posicao = *posicao + 1;

            //Inicializo a arvore pra esquerda, caso for NULL
            if (vaziaArvore(arvore->esquerda))
            {
                arvore->esquerda = criaArvore();
            }

            //Crio a arvore pra esquerda;
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
        ehNumero = 0;
        char *num = NULL;

        //Leio a string do numero até o parenteses ")" dele;
        num = strtok((expressao + *posicao), ")");

        //Insiro o numero na arvore transformando em inteiro;
        arvore = insereNumeroArvore(arvore, atoi(num));

        //Calculo o tamanho do numero lido,
        //Para atualizar a posição deleitura da expressao
        int tamanho = 0;
        tamanho = strlen(num);
        tamanho++;

        *posicao = *posicao + tamanho;

        return arvore;
    }

    //Se for operador;
    else if (verificaOperador(*(expressao + *posicao)))
    {
        arvore = insereOperadorArvore(arvore, *(expressao + *posicao));
        *posicao = *posicao + 1;

        //Inicializo a arvore pra direita, caso for NULL
        if (vaziaArvore(arvore->direita))
        {
            arvore->direita = criaArvore();
        }

        //Crio a arvore para direita;
        arvore->direita = constroiArvore(arvore->direita, expressao, posicao);
    }

    return arvore;
}

/*Calcula o valor da equação da arvore recebida;
 *inputs: (Arvore*);
 *outputs: (float);
 *pré-condição: (Arvore*) existente;
 *pós-condição: float de retorno existente;
*/
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

    //Se for operador, calcula;
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
