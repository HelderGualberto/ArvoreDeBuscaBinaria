#include <stdio.h>
#include <stdlib.h>
#include "abb.h"
#include "pilha.h"
void reset(no* raiz){
    if(raiz == NULL)
        return;
    reset(raiz->fesq);
    raiz->visitado = 0;
    reset(raiz->fdir);
}

void pre_ordem(no* raiz){
    no* temp = raiz;
    pilha* p = alocar_pilha();
    inserir_pilha(p,temp);

    while(p->topo != NULL){
        if(temp->visitado == 0)
            printf("%d ",temp->valor);

        temp->visitado = 1;

        if(temp->fesq != NULL && temp->fesq->visitado == 0){
            inserir_pilha(p,temp->fesq);
            temp = topo(p);
        }
        else{


            if(temp->fdir != NULL && temp->fdir->visitado == 0){
                inserir_pilha(p,temp->fdir);
                temp = topo(p);
            }
            else{
                remover_pilha(p);
                if(p->topo != NULL)
                    temp = topo(p);
            }
        }
    }
    destruir_pilha(p);
    reset(raiz);
}

void pos_ordem(no* raiz){
    no* temp = raiz;
    pilha* p = alocar_pilha();
    inserir_pilha(p,temp);

    while(p->topo != NULL){

        if(temp->fesq != NULL && temp->fesq->visitado == 0){
            inserir_pilha(p,temp->fesq);
            temp = topo(p);
        }
        else{

            temp->visitado = 1;

            if(temp->fdir != NULL && temp->fdir->visitado == 0){
                inserir_pilha(p,temp->fdir);
                temp = topo(p);
            }
            else{
                printf("%d ",temp->valor);
                remover_pilha(p);
                if(p->topo != NULL)
                    temp = topo(p);
            }
        }
    }
    destruir_pilha(p);
    reset(raiz);
}

void in_ordem(no* raiz){
    no* temp = raiz;
    pilha* p = alocar_pilha();
    inserir_pilha(p,temp);

    while(p->topo != NULL){

        if(temp->fesq != NULL && temp->fesq->visitado == 0){
            inserir_pilha(p,temp->fesq);
            temp = topo(p);
        }
        else{
            if(temp->visitado == 0)
                printf("%d ",temp->valor);

            temp->visitado = 1;

            if(temp->fdir != NULL && temp->fdir->visitado == 0){
                inserir_pilha(p,temp->fdir);
                temp = topo(p);
            }
            else{
                remover_pilha(p);
                if(p->topo != NULL)
                    temp = topo(p);
            }
        }
    }
    destruir_pilha(p);
    reset(raiz);
}

void pre_ordem_recursivo(no* raiz){
    if(raiz == NULL)
        return;

    printf("%d ",raiz->valor);
    pre_ordem_recursivo(raiz->fesq);
    pre_ordem_recursivo(raiz->fdir);
}

void pos_ordem_recursivo(no* raiz){
    if(raiz == NULL)
        return;
    pos_ordem_recursivo(raiz->fesq);
    pos_ordem_recursivo(raiz->fdir);
    printf("%d ",raiz->valor);
}

void in_ordem_recursivo(no* raiz){
    if(raiz == NULL)
        return;
    in_ordem_recursivo(raiz->fesq);
    printf("%d ",raiz->valor);
    in_ordem_recursivo(raiz->fdir);
}

no* minimo(no* raiz){
    if(raiz->fesq == NULL)
        return raiz;
    return minimo(raiz->fesq);
}

no* maximo(no* raiz){
    if(raiz->fdir == NULL)
        return raiz;
    return maximo(raiz->fdir);
}

no* sucessor(no* n){
    no* temp = n;
    if(temp->fdir != NULL){
        temp = temp->fdir;
        return minimo(temp);
    }

    while(temp->pai != NULL){
        if(temp == temp->pai->fesq){
            return temp->pai;
        }
        temp = temp->pai;
    }
    return NULL;
}

void imprimir(no* raiz){

    if(raiz == NULL)
        return;
    imprimir(raiz->fesq);
    printf("%d ",raiz->valor);
    imprimir(raiz->fdir);

}

void imprimir_arvore(no* raiz){
    imprimir(raiz);
    printf("\n");
}

void inserir_arvore(arvore* a,int valor){
    no* temp = a->raiz;
    no* novo = malloc(sizeof(no));
    novo->fesq = NULL;
    novo->fdir = NULL;
    novo->valor = valor;
    novo->visitado = 0;

    while(temp != NULL){
        if(temp->fesq != NULL && temp->valor >= valor){
            temp = temp->fesq;
        }
        else if(temp->fdir != NULL && temp->valor <= valor)
            temp = temp->fdir;

        else
            break;
    }

    if(temp == NULL){
        novo->pai = NULL;
        a->raiz = novo;
    }
    else{
        if(temp->valor > valor){
            temp->fesq = novo;
            novo->pai = temp;
            return;
        }
        else{
            temp->fdir = novo;
            novo->pai = temp;
            return;
        }
    }
}

void copiar2(no* i,no* j){
    int temp;
    temp = i->valor;
    i->valor = j->valor;
    j->valor = temp;
}

void remover_arvore(arvore* a, int valor){
    no* temp = a->raiz;

    while(temp != NULL){
        if(temp->fesq != NULL && temp->valor > valor){
            temp = temp->fesq;
        }
        else if(temp->fdir != NULL && temp->valor < valor){
            temp = temp->fdir;
        }
        else
            break;
    }

    if(a->raiz == NULL){
        printf("Arvore vazia!");
        return;
    }
    if(temp->valor != valor){
        printf("valor nao encontrado");
        return;
    }

    if(temp->fesq != NULL && temp->fdir != NULL){
        copiar2(temp,sucessor(temp));
        temp = sucessor(temp);
    }

    if(temp->fdir != NULL){

        if(temp->pai != NULL && temp->pai->fesq == temp){
            temp->fdir->pai = temp->pai;
            temp->pai->fesq = temp->fdir;
            free(temp);
            return;
        }
        else if(temp->pai != NULL && temp->pai->fdir == temp){
            temp->fdir->pai = temp->pai;
            temp->pai->fdir = temp->fdir;
            free(temp);
            return;
        }
        else{
            temp->fdir->pai = NULL;
            a->raiz = temp->fdir;
            free(temp);
            return;
        }
    }

    if(temp->fesq != NULL){
        if(temp->pai != NULL && temp->pai->fesq == temp){
            temp->fesq->pai = temp->pai;
            temp->pai->fesq = temp->fesq;
            free(temp);
            return;
        }
        else if(temp->pai != NULL && temp->pai->fdir == temp){
            temp->fesq->pai = temp->pai;
            temp->pai->fdir = temp->fesq;
            free(temp);
            return;
        }
        else{
            temp->fesq->pai = NULL;
            a->raiz = temp->fesq;
            free(temp);
            return;
        }
    }

    if(temp->pai != NULL && temp->pai->fesq == temp){
        temp->pai->fesq = NULL;
        free(temp);
        return;
    }
    else if(temp->pai != NULL && temp->pai->fdir == temp){
        temp->pai->fdir = NULL;
        free(temp);
        return;
    }
    else{
        a->raiz = NULL;
        free(temp);
    }

}

arvore* alocar_arvore(){
    arvore* a = malloc(sizeof(arvore));
    a->raiz = NULL;
    return a;
}

void destruir_arvore(no* raiz){

    if(raiz == NULL)
        return;
    destruir_arvore(raiz->fesq);

    destruir_arvore(raiz->fdir);

    free(raiz);
}
