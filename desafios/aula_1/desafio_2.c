#include<stdio.h>
#include<stdlib.h>

struct no {
    int valor;
    struct no *proximo;
};

struct no * criarNo(int valor) {
    struct no * novoElemento = malloc(sizeof(struct no));
    novoElemento->valor = valor;
    return novoElemento;
}

struct no * inserirInicio(struct no * inicioLista, int valor) {
    struct no * novoElemento = criarNo(valor);

    if (!novoElemento)
        return inicioLista;

    novoElemento->proximo = inicioLista;
    return novoElemento;
}

void inserirFim(struct no * inicioLista, int valor) {
    struct no * novoElemento = criarNo(valor);

    struct no * ponteiroAtual = inicioLista;

    while (ponteiroAtual->proximo != NULL) {
        ponteiroAtual = ponteiroAtual->proximo;
    }

    ponteiroAtual->proximo = novoElemento;
}

void imprimirLista(struct no * inicioLista) {
    struct no * ponteiroAtual = inicioLista;

    while (ponteiroAtual != NULL) {
        printf("%d\n", ponteiroAtual->valor);
        ponteiroAtual = ponteiroAtual->proximo;
    }
}

struct no * removerPrimeiro(struct no * inicioLista) {
    if (inicioLista == NULL)
        return NULL;

    struct no * novoInicio = inicioLista->proximo;
    return novoInicio;
}

struct no * removerUltimo(struct no * inicioLista) {
    if (inicioLista == NULL)
        return NULL;

    struct no * ponteiroAtual = inicioLista;

    while (ponteiroAtual->proximo->proximo != NULL) {
        ponteiroAtual = ponteiroAtual->proximo;
    }

    ponteiroAtual->proximo = NULL;

    return inicioLista;
}

int main() {
    struct no * minhaLista = criarNo(1);

    inserirFim(minhaLista, 2);
    inserirFim(minhaLista, 3);

    minhaLista = removerUltimo(minhaLista);

    imprimirLista(minhaLista);

    return 0;
}