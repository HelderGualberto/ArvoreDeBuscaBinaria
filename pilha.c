#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

pilha* alocar_pilha(){
    pilha* p = malloc(sizeof(pilha));
    p->topo = NULL;
    return p;
}

int elementos_pilha(pilha* p){
    node* temp = p->topo;
    int i = 0;
    while(temp!=NULL){
        i++;
        temp = temp->prox;
    }
    return i;
}

void imprimir_pilha(pilha* p){
    node* temp = p->topo;

    while(temp!=NULL){
        printf("%d ",temp->folha->valor);
        temp = temp->prox;
    }
    printf("\n");
}

void inserir_pilha(pilha* p,no* folha){
    node* novo = malloc(sizeof(node));
    novo->folha = folha;

    if(p->topo == NULL){
        p->topo = novo;
        p->topo->prox = NULL;
        return;
    }

    novo->prox = p->topo;
    p->topo = novo;
    return;
}

no* topo(pilha* p){
    return p->topo->folha;
}

int remover_pilha(pilha* p){
    if(p->topo == NULL){
        return -1;
    }
    node* temp = p->topo;
    p->topo = p->topo->prox;
    free(temp);
    return 1;
}

void destruir_pilha(pilha* p){
    while(remover_pilha(p) != -1);
    free(p);
}


