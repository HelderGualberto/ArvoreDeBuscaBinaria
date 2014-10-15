#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

typedef struct element{
    struct element *pai;
    struct element *fesq;
    struct element *fdir;
    int valor,visitado;
}no;

typedef struct{
    no *raiz;
}arvore;

void inserir_arvore(arvore*,int valor);
void remover_arvore(arvore*,int valor);
void imprimir_arvore(no* raiz);
void destruir_arvore(no* raiz);
arvore* alocar_arvore();

void pre_ordem(no* raiz);
void pos_ordem(no* raiz);
void in_ordem(no* raiz);

void pre_ordem_recursivo(no* raiz);
void pos_ordem_recursivo(no* raiz);
void in_ordem_recursivo(no* raiz);
#endif // ABB_H_INCLUDED
