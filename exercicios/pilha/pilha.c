//  1) Dado duas pilhas P1 e P2 que armazenam números inteiros, faça um programa que tenha as seguintes funções:
//     - Uma função para testar se as duas pilhas P1 e P2 são iguais. Caso não forem iguais diga qual pilha é maior
//     - Uma função que forneça o maior, o menor e a média aritmética dos elementos de uma pilha.
//     - Uma função para transferir elementos de P1 para P2 (copia).
//     - Uma função para retornar o número de elementos de uma pilha que possuem valor impar.
//     - Uma função para retornar o número de elementos da uma pilha que possuem valor par


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

void iniciarPilha(struct Pilha* pilha) {
    (*pilha).top = NULL;
}

int vazio(struct Pilha* pilha) {
    return pilha->top == NULL;
}

void push(struct Pilha* pilha, int data) {
    struct No* novoNo = criarNo(data);
    novoNo->next = pilha->top;
    pilha->top = novoNo;
}

int pop(struct Pilha* pilha) {
    if (vazio(pilha)) {
        printf("\nErro: A pilha está vazia.\n");
        exit(1);
    }
    struct No* temp = pilha->top;
    int data = temp->data;
    pilha->top = temp->next;
    free(temp);
    return data;
}

int topo(struct Pilha* pilha) {
    if (vazio(pilha)) {
        printf("\nErro: A pilha está vazia.\n");
        exit(1);
    }
    return pilha->top->data;
}


// Funções para resolver as questões


int iguais(struct Pilha *pilha1, struct Pilha *pilha2) {
    if (vazio(pilha1)) {
        printf("\nErro: A pilha 1 está vazia.\n");
        exit(1);
    }
    if (vazio(pilha2)) {
        printf("\nErro: A pilha 2 está vazia.\n");
        exit(1);
    }
    
    struct No *no1 = pilha1->top;
    struct No *no2 = pilha2->top;
    
    while (1) {
        if (no1->next == NULL && no2->next == NULL) {
            printf("\nAs pilhas são iguais");
            return 1;
        }
        
        if (no1->next == NULL || no2->next == NULL) {
            printf("\nAs pilhas tem tamanhos diferentes");
            return 0;
        }
        
        if (no1->data != no2->data) {
            printf("\nAs pilhas tem valores diferentes");
            return 0;
        }
        
        no1 = no1->next;
        no2 = no2->next;
    }
}

int maior(struct Pilha *pilha) {
    if (vazio(pilha)) {
        printf("\nErro: A pilha 1 está vazia.\n");
        exit(1);
    }

    struct No *no = pilha->top;
    int maior = no->data;

    while (1) {
        if (no->data > maior) {
            maior = no->data;
        }

        if (no->next == NULL) {
            return maior;
        }

        no = no->next;
    }
}

int menor(struct Pilha *pilha) {
    if (vazio(pilha)) {
        printf("\nErro: A pilha 1 está vazia.\n");
        exit(1);
    }

    struct No *no = pilha->top;
    int menor = no->data;

    while (1) {
        if (no->data < menor) {
            menor = no->data;
        }

        if (no->next == NULL) {
            return menor;
        }

        no = no->next;
    }
}

float media(struct Pilha *pilha) {
    if (vazio(pilha)) {
        printf("\nErro: A pilha 1 está vazia.\n");
        exit(1);
    }

    struct No *no = pilha->top;
    int soma = 0;
    float quantidade = 0;

    while (1) {
        soma = soma + no->data;
        quantidade++;

        if (no->next == NULL) {
            return soma / quantidade;
        }

        no = no->next;
    }
}

void zerar(struct Pilha *pilha) {
    while (vazio(pilha)) {
        struct No* temp = pilha->top;
        pilha->top = temp->next;
        free(temp);
    }
}

void copia(struct Pilha *origem, struct Pilha *destino) {
    zerar(destino);
    destino->top = origem->top;
}

int quantpares(struct Pilha *pilha) {
    if (vazio(pilha)) {
        printf("\nErro: A pilha 1 está vazia.\n");
        exit(1);
    }

    struct No *no = pilha->top;
    float quantidade = 0;

    while (1) {
        if (no->data != 0 && no->data % 2 == 0) {
            quantidade++;
        }

        if (no->next == NULL) {
            return quantidade;
        }

        no = no->next;
    }
}

int quantImpares(struct Pilha *pilha) {
    if (vazio(pilha)) {
        printf("\nErro: A pilha 1 está vazia.\n");
        exit(1);
    }

    struct No *no = pilha->top;
    float quantidade = 0;

    while (1) {
        if (no->data != 0 && no->data % 2 == 1) {
            quantidade++;
        }

        if (no->next == NULL) {
            return quantidade;
        }

        no = no->next;
    }
}

int main() {
    struct Pilha pilha1, pilha2;
    iniciarPilha(&pilha1);
    iniciarPilha(&pilha2);
    
    for (int i = 0; i <= 10; i++) {
        push(&pilha1, i);   
    }
    for (int i = 100; i > 0; i--) {
        push(&pilha2, i);   
    }
    
    iguais(&pilha1, &pilha2);
    printf("\nMaior elemento da pilha 1: %d", maior(&pilha1));
    printf("\nMenor elemento da pilha 2: %d", menor(&pilha2));
    printf("\nMedia da pilha 1: %f", media(&pilha1));
    copia(&pilha1, &pilha2);
    iguais(&pilha1, &pilha2);
    printf("\nQuantidade de números pares na pilha 1: %d", quantpares(&pilha1));
    printf("\nQuantidade de números impares na pilha 2: %d", quantImpares(&pilha2));

    printf("\n");
    return 0;
}