#ifndef ARVORE_H_
#define ARVORE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore Arvore;

/*Cria uma árvore NULL;
 *inputs: (void);
 *outputs: (Arvore*) NULL;
 *pré-condição: ;
 *pós-condição: (Arvore*) de retorno existente;
*/
Arvore *inicializaArvore(void);

/*Inicializa uma àrvore;
 *inputs: (void);
 *outputs: (Arvore*) devidamente inicializado e alocado;
 *pré-condição: ;
 *pós-condição: (Arvore*) de retorno existente;
*/
Arvore *criaArvore(void);

/*Imprime árvore;
 *inputs: (Arvore*);
 *outputs: (void);
 *pré-condição: (Arvore*) existente;
 *pós-condição: ;
*/
void imprimeArvore(Arvore *arvore);

/*Retorna o status da árvore, se está vazia ou não;
 *inputs: (Arvore*);
 *outputs: (int);
 *pré-condição: (Arvore*) existente;
 *pós-condição: int alocado;
*/
int vaziaArvore(Arvore *arvore);

/*Retorna (caso exista) operador da arvore;
 *inputs: (Arvore*);
 *outputs: (char);
 *pré-condição: (Arvore*) existente;
 *pós-condição: char alocado;
*/
char retornaOperador(Arvore *arvore);

/*Retorna (caso exista) número da arvore;
 *inputs: (Arvore*);
 *outputs: (int);
 *pré-condição: (Arvore*) existente;
 *pós-condição: int alocado;
*/
int retornaNumero(Arvore *arvore);

/*Libera o espaço de memória ocupado pela árvore;
 *inputs: (Arvore*);
 *outputs: (Arvore*);
 *pré-condição: (Arvore*) existente;
 *pós-condição: (Arvore*) mddificada;
*/
Arvore *liberaArvore(Arvore *arvore);

/*Insere determinado numero em uma determinada arvore;
 *inputs: (Arvore*), (int numero);
 *outputs: (Arvore*);
 *pré-condição: (Arvore*) existente, numero como inteiro;
 *pós-condição: (Arvore*) mddificada, numero inserido;
*/
Arvore *insereNumeroArvore(Arvore *arvore, int numero);

/*Insere determinado operador em uma determinada arvore;
 *inputs: (Arvore*), (char operador);
 *outputs: (Arvore*);
 *pré-condição: (Arvore*) existente, operador como char;
 *pós-condição: (Arvore*) mddificada, operador inserido;
*/
Arvore *insereOperadorArvore(Arvore *arvore, char operador);

/*Constroi a arvore a partir da equação lida, recursivamente;
 *inputs: (Arvore*), (char *expressão), (int *posição);
 *outputs: (Arvore*);
 *pré-condição: (Arvore*) existente, expressão existente, posição existente;
 *pós-condição: (Arvore*) mddificada, devidamente criada;
*/
Arvore *constroiArvore(Arvore *arvore, char *expressao, int *posicao);

/*Calcula o valor da equação da arvore recebida;
 *inputs: (Arvore*);
 *outputs: (float);
 *pré-condição: (Arvore*) existente;
 *pós-condição: float de retorno existente;
*/
float calculaEquacao(Arvore *arvore);

#endif /*ARVORE_H_*/
