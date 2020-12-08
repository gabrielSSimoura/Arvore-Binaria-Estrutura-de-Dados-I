#ifndef ARVORE_H_
#define ARVORE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore Arvore;

//Cria uma árvore NULL;
Arvore *inicializaArvore(void);

Arvore *criaArvore(void);

//Imprime árvore
void imprimeArvore(Arvore *arvore);

//Retorna o status da árvore, se está vazia ou não
int vaziaArvore(Arvore *arvore);

// //Verifica se o elemento é um operador
// int verificaOperador(char elemento);

//Retorna operador (caso exista) da arvore;
char retornaOperador(Arvore *arvore);

//Retorna numero (caso exista) da arvore;
int retornaNumero(Arvore *arvore);

// //Retorna info convertida de char para inteiro;
// int retornaNumeroConvertidoInt(char *numero);

//Libera o espaço de memória ocupado pela árvore
Arvore *liberaArvore(Arvore *arvore);

Arvore *insereNumeroArvore(Arvore *arvore, int numero);

Arvore *insereOperadorArvore(Arvore *arvore, char operador);

Arvore *constroiArvore(Arvore *arvore, char *expressao, int *posicao);

//---------------------------------------------------------------------------------------------//

float calculaEquacao(Arvore *arvore);

#endif /*ARVORE_H_*/
