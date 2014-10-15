#include <stdio.h>
#include <stdlib.h>
#include "abb.h"
#include "pilha.h"
/** Developed by Helder Rodrigues
    Reports: helder.garjunior@outlook.com
**/


int main()
{
    arvore* a = alocar_arvore();

    inserir_arvore(a,5);
    inserir_arvore(a,9);
    inserir_arvore(a,3);
    inserir_arvore(a,2);
    inserir_arvore(a,4);
    inserir_arvore(a,6);
    inserir_arvore(a,7);
    inserir_arvore(a,8);
    inserir_arvore(a,1);

    pos_ordem(a->raiz);
    printf("\n");
    in_ordem(a->raiz);
    printf("\n");
    pre_ordem(a->raiz);
    printf("\n");
    return 0;
}
