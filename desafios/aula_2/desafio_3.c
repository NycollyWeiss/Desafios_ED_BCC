ListaLigada insereOrdenado(ListaLigada lista, int valorInserir) {

    Celula atual = lista->inicio;
    Celula novoNo = novaCelula(valorInserir);

    // Caso o valor seja o primeiro
    if (lista->inicio == NULL || valorInserir < lista->inicio->info) {
        llInsereNoInicio(lista, valorInserir);
        return lista;
    }

    // Caso o valor seja o último
    if (valorInserir > lista->fim->info) {
        llInsereNoFim(lista, valorInserir);
        return lista;
    }

    // Restante da lista
    while (atual != NULL) {

        if (valorInserir < atual->prox->info) {

            novoNo->prox = atual->prox;
            atual->prox = novoNo;

            return lista;
        }

        atual = atual->prox;
    }

    return lista;
}

int quantidadeValores;
int valorDigitado;
int novoValor;

printf("Vamos criar uma lista! Digite quantos valores quer inserir nela: ");
scanf("%d", &quantidadeValores);

ListaLigada lista = novaLista();

for (int i = 1; i <= quantidadeValores; i++) {

    printf("Digite um numero: ");
    scanf("%d", &valorDigitado);

    llInsereNoFim(lista, valorDigitado);
}

printf("\nLista original: ");
llPrint(lista);

printf("\nSoma da lista: ");
somaLista(lista);

printf("\nLista Ordenada: ");
bubbleSort(lista);
llPrint(lista);

printf("\nDigite um numero para inserir na lista: ");
scanf("%d", &novoValor);

insereOrdenado(lista, novoValor);

llPrint(lista);