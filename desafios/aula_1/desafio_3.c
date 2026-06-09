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

//---------------------------DESAFIO AQUI----------------------------------------

struct no * removerValor(struct no * inicioLista, int valorRemover) {

    struct no * ponteiroAtual = inicioLista;

    // CASO O VALOR A SER REMOVIDO SEJA O PRIMEIRO
    if (inicioLista->valor == valorRemover) {

        struct no * novoInicio = inicioLista->proximo;

        return novoInicio;
    }

    // RESTANTE DA LISTA
    while (ponteiroAtual != NULL) {

        if (ponteiroAtual->proximo->valor == valorRemover) {

            struct no * noRemovido = ponteiroAtual->proximo;

            ponteiroAtual->proximo = noRemovido->proximo;

            free(noRemovido);

            return inicioLista;
        }

        ponteiroAtual = ponteiroAtual->proximo;
    }

    return inicioLista;
}

int main() {

    struct no * minhaLista = criarNo(1);

    inserirFim(minhaLista, 2);
    inserirFim(minhaLista, 3);

    int valorRemover;

    printf("Digite um valor da lista que deseja remover: ");
    scanf("%d", &valorRemover);

    minhaLista = removerValor(minhaLista, valorRemover);

    imprimirLista(minhaLista);

    return 0;
}