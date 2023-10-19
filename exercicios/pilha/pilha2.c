#include <stdio.h>
#include <stdlib.h>


// Funções básicas da Pilha
struct No {
    int data;
    struct No* next;
};

struct Pilha {
    struct No* top;
};

struct Pilha* criarPilha() {
    struct Pilha* pilha = (struct Pilha*)malloc(sizeof(struct Pilha));
    pilha->top = NULL;
    return pilha;
}

struct No* criarNo(int data) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    if (novoNo == NULL) {
        printf("\nErro: Não foi possível alocar memória para o novo nó.\n");
        exit(1);
    }
    novoNo->data = data;
    novoNo->next = NULL;
    return novoNo;
}

int tamanhoPilha(struct Pilha* pilha) {
    int tamanho = 0;
    struct No* temp = pilha->top;
    while (temp != NULL) {
        tamanho++;
        temp = temp->next;
    }
    return tamanho;
}

int verificaPilhaVazia(struct Pilha* pilha) {
    return pilha->top == NULL;
}

void empilha(struct Pilha* pilha, int data) {
    struct No* novoNo = criarNo(data);
    novoNo->next = pilha->top;
    pilha->top = novoNo;
}

int desempilha(struct Pilha* pilha) {
    if (verificaPilhaVazia(pilha)) {
        printf("\nErro: A pilha está vazia.\n");
        exit(1);
    }
    struct No* temp = pilha->top;
    int data = temp->data;
    pilha->top = temp->next;
    free(temp);
    return data;
}

int topoPilha(struct Pilha* pilha) {
    if (verificaPilhaVazia(pilha)) {
        printf("\nErro: A pilha está vazia.\n");
        exit(1);
    }
    return pilha->top->data;
}

void limpaPilha(struct Pilha* pilha) {
    while (!verificaPilhaVazia(pilha)) {
        desempilha(pilha);
    }
}

void invertePilha(struct Pilha* pilha) {
    struct Pilha* pilhaInvertida = criarPilha();
    while (pilha->top != NULL) {
        empilha(pilhaInvertida, desempilha(pilha));
    }
    pilha->top = pilhaInvertida->top;
}

struct Pilha* copiaPilha(struct Pilha* pilha) {
    struct Pilha* pilhaCopia = criarPilha();
    struct No* temp = pilha->top;
    while (temp != NULL) {
        empilha(pilhaCopia, temp->data);
        temp = temp->next;
    }
    invertePilha(pilhaCopia);
    return pilhaCopia;
}

void printPilha(struct Pilha* pilha) {
    struct No* temp = pilha->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void concatenaPilhas(struct Pilha* pilha1, struct Pilha* pilha2) {
    struct Pilha* copia1 = copiaPilha(pilha1);
    struct Pilha* copia2 = copiaPilha(pilha2);
    invertePilha(copia1);
    invertePilha(copia2);
    struct Pilha* final = criarPilha();
    while (copia2->top != NULL) {
        empilha(final, desempilha(copia2));
    }
    while (copia1->top != NULL) {
        empilha(final, desempilha(copia1));
    }
    pilha1->top = final->top;
}

int main() {
    // Exercício 1: Crie uma função chamada criarPilha que inicializa uma pilha vazia e a retorna como um ponteiro.
    printf("1)\n");
    struct Pilha* pilha1 = criarPilha();
    printf("\n");

    // Exercício 2: Crie uma função chamada empilha que recebe uma pilha e um valor inteiro como parâmetros e empilha o valor na pilha.
    printf("2)\n");
    empilha(pilha1, 1);
    empilha(pilha1, 7);
    empilha(pilha1, 2);
    printf("\n");

    // Exercício 3: Crie uma função chamada desempilha que recebe uma pilha como parâmetro e remove o elemento do topo da pilha.
    printf("3)\n");
    desempilha(pilha1);
    printf("\n");

    // Exercício 4: Crie uma função chamada topoPilha que recebe uma pilha como parâmetro e retorna o elemento do topo da pilha sem removê-lo.
    printf("4)\n");
    printf("topo da pilha: %d", topoPilha(pilha1));
    printf("\n\n");

    // Exercício 5: Crie uma função chamada tamanhoPilha que recebe uma pilha como parâmetro e retorna o número de elementos na pilha.
    printf("5)\n");
    printf("tamanho da pilha: %d", tamanhoPilha(pilha1));
    printf("\n\n");

    // Exercício 6: Crie uma função chamada limpaPilha que recebe uma pilha como parâmetro e a esvazia, removendo todos os elementos.
    printf("6)\n");
    limpaPilha(pilha1);
    printf("\n\n");

    // Exercício 7: Crie uma função chamada copiaPilha que recebe uma pilha como parâmetro e retorna uma cópia da pilha.
    printf("7)\n");
    empilha(pilha1, 4);
    empilha(pilha1, 5);
    empilha(pilha1, 6);
    struct Pilha* pilha2 = copiaPilha(pilha1);
    printf("pilha1: ");
    printPilha(pilha1);
    printf("pilha2: ");
    printPilha(pilha2);
    printf("\n");

    // Exercício 8: Crie uma função chamada invertePilha que recebe uma pilha como parâmetro e inverte a ordem dos elementos na pilha original.
    printf("8)\n");
    printf("pilha original:  ");
    printPilha(pilha2);
    invertePilha(pilha2);
    printf("pilha invertida: ");
    printPilha(pilha2);
    printf("\n");

    // Exercício 9: Crie uma função chamada verificaPilhaVazia que recebe uma pilha como parâmetro e retorna verdadeiro se a pilha estiver vazia e falso caso contrário.
    printf("9)\n");
    limpaPilha(pilha1);
    printf("pilha1 vazia? %s", verificaPilhaVazia(pilha1) ? "sim" : "não");
    printf("\npilha2 vazia? %s", verificaPilhaVazia(pilha2) ? "sim" : "não");
    printf("\n\n");

    // Exercício 10: Crie uma função chamada concatenaPilhas que recebe duas pilhas como parâmetros e concatena os elementos da segunda pilha no final da primeira pilha.
    printf("10)\n");
    empilha(pilha1, 3);
    empilha(pilha1, 2);
    empilha(pilha1, 1);
    printf("pilha1: ");
    printPilha(pilha1);
    printf("pilha2: ");
    printPilha(pilha2);
    printf("pilha1 + pilha2: ");
    concatenaPilhas(pilha1, pilha2);
    printPilha(pilha1);
    
    return 0;
}