
//Implementa a função print_list, que recebe o nó de início da lista e imprime todos os seus valores 

#include<stdio.h>

//⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇
void print_lista(struct no* lista ){
    struct no *atual = lista;
    while(atual-> prox != NULL){
        printf("%d\n", atual-> info );
        atual = atual->prox;
    }
}


struct no {
    int info;         
    struct no * prox;
};

struct no * novoNo(int info) {
    struct no * novo = malloc(sizeof(struct no));
    novo->info = info;
    return novo;
}

struct no * insert_first(struct no * lista, int info) {
    struct no *novo = novoNo(info);
    if (!novo) return lista;   // se falhar, mantém a lista como estava
    novo->prox = lista;        // novo aponta para a antiga cabeça
    return novo;               // novo vira a cabeça
}

void insert_last(struct no * lista, int info) {
    struct no *novo = novoNo(info);
    // Precisamos encontrar o último elemento da lista. Quando encontramos, adicionamos o novo!
    struct no *curr = lista;
    while (curr->prox != NULL) {
        curr = curr->prox;
    }
    curr->prox = novo;
}

struct no * remove_first(struct no * lista) {
    if (lista == NULL) return NULL; // lista vazia

    struct no *novo_inicio = lista->prox;
    return novo_inicio;
}

int main() {
    
    struct no * lista () = novoNo(1);
    insert_last(lista, 2);
    insert_last(lista, 3);
    insert_last(lista, 4);
    insert_last(lista, 5);


    print_lista(lista);



    return 0;
}