#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include "abb.h"

typedef struct ele{
    struct ele* prox;
    no* folha;
}node;

typedef struct{
    node* topo;
}pilha;

pilha* alocar_pilha();
void destruir_pilha(pilha*);
void inserir_pilha(pilha*,no* folha);
int remover_pilha(pilha*);
void imprimir_pilha(pilha*);
no* topo(pilha* p);
int elementos_pilha(pilha* p);

#endif // PILHA_H_INCLUDED
