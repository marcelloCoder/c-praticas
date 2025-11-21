typedef struct NO* ArvoreAVL;

int insereArvoreAVL(ArvoreAVL *raiz, int valor);

int removeArvoreAVL(ArvoreAVL *raiz, int valor);

struct NO* procuraMenor(struct NO* atual);
