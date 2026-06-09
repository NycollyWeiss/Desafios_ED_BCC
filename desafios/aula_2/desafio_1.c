typedef No * NoLista;
typedef Lista * ListaPtr;

NoLista criarNo(int valor) {
    NoLista novoNo = malloc(sizeof(No));

    novoNo->info = valor;
    novoNo->prox = NULL;

    return novoNo;
}
void calcularSomaLista(ListaPtr lista) {

    NoLista atual = lista->inicio;
    int soma = 0;

    while (atual != NULL) {
        soma += atual->info;
        atual = atual->prox;
    }

    printf("%d\n", soma);
}

int main() {

    int quantidadeValores;
    int valorDigitado;

    printf("Vamos criar uma lista! Digite quantos valores quer inserir nela: ");
    scanf("%d", &quantidadeValores);

    ListaPtr lista = novaLista();

    for (int i = 1; i <= quantidadeValores; i++) {

        printf("Digite um numero: ");
        scanf("%d", &valorDigitado);

        llInsereNoFim(lista, valorDigitado);
    }

    printf("\nLista original: ");
    llPrint(lista);

    printf("\nSoma da lista: ");
    calcularSomaLista(lista);

    return 0;
}