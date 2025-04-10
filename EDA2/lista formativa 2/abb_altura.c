#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

int altura(no *r) {
    if (r == NULL) {
        return 0;
    }

    int altura_esq = altura(r->esq);
    int altura_dir = altura(r->dir);

    if (altura_esq > altura_dir) {
        return altura_esq + 1;
    } else {
        return altura_dir + 1;
    }
}
