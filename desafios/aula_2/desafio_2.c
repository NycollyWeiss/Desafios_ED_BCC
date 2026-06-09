void ordenarLista(ListaPtr lista) {

    int valorTemp;
    bool houveTroca = true;

    while (houveTroca) {

        houveTroca = false;

        NoLista atual = lista->inicio;

        while (atual->prox != NULL) {

            if (atual->valor > atual->prox->valor) {

                valorTemp = atual->valor;
                atual->valor = atual->prox->valor;
                atual->prox->valor = valorTemp;

                houveTroca = true;
            }

            atual = atual->prox;
        }
    }
}

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