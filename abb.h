#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

typedef struct element{
    struct element *pai;
    struct element *fesq;
    struct element *fdir;
    int valor;
}no;

typedef struct{
    no *raiz;
}arvore;

void inserir_arvore(arvore*,int valor);
void remover_arvore(arvore*,int valor);
void imprimir_arvore(no* raiz);
void destruir_arvore(no* raiz);
arvore* alocar_arvore();

#endif // ABB_H_INCLUDED
