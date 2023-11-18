#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

typedef struct Node Node;

struct List {
    Node *head;
    Node *tail;
};

typedef struct List List;

struct Node* criarNo(int data) {
    struct Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("\nErro: Não foi possível alocar memória para o novo nó.\n");
        exit(1);
    }
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void criarListaVazia(List *list) {
    list->head = NULL;
    list->tail = NULL;
}

void inserirNoInicio(List *list, int data) {
    Node *node = criarNo(data);
    if (list->head == NULL) {
        list->tail = node;
    } else {
        list->head->prev = node;
        node->next = list->head;
    }
    list->head = node;
}

void inserirNoFinal(List *list, int data) {
    Node *node = criarNo(data);
    if (list->head == NULL) {
        list->head = node;
    } else {
        node->prev = list->tail;
        list->tail->next = node;
    }
    list->tail = node;
}

void removerPrimeiro(List *list) {
    if (list->head == NULL) {
        printf("\nErro: A lista está vazia.\n");
        exit(1);
    }
    Node *temp = list->head;
    if (temp->next == NULL) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->head = temp->next;
        list->head->prev = NULL;
    }
    free(temp);
}

void removerUltimo(List *list) {
    if (list->tail == NULL) {
        printf("\nErro: A lista está vazia.\n");
        exit(1);
    }
    Node *temp = list->tail;
    if (temp->prev == NULL) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->tail->prev->next = NULL;
        list->tail = temp->prev;
    }
    free(temp);
}

int somaTodos(int tamanho, int list[tamanho]) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma = soma + list[i];
    }
    return soma;
}

int encontrarMaior(int tamanho, int list[tamanho]) {
    int maior = list[0];
    for (int i = 0; i < tamanho; i++) {
        if (list[i] > maior) {
            maior = list[i];
        }
    }
    return maior;
}

int contarVogais(char *string) {
    int count = 0;
    while (*string != '\0') {
        if (*string == 'a' || *string == 'e' || *string == 'i' || *string == 'o' || *string == 'u') {
            count++;
        }
        string++;
    }
    return count;
}

int main() {
    List List;
    int inteiros[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Exercício 6: Escreva uma função que cria uma lista vazia.
    printf("6)\n");
    criarListaVazia(&List);
    printf("\n");

    // Exercício 7: Escreva uma função que insere um elemento no início de uma lista.
    printf("7)\n");
    inserirNoInicio(&List, 2);
    inserirNoInicio(&List, 1);
    printf("\n");

    // Exercício 8: Escreva uma função que insere um elemento no final de uma lista.
    printf("8)\n");
    inserirNoFinal(&List, 3);
    inserirNoFinal(&List, 4);
    printf("\n");

    // Exercício 9: Escreva uma função que remove o primeiro elemento de uma lista.
    printf("9)\n");
    removerPrimeiro(&List);
    removerPrimeiro(&List);
    printf("\n");

    // Exercício 10: Escreva uma função que remove o último elemento de uma lista.
    printf("10)\n");
    removerUltimo(&List);
    removerUltimo(&List);
    printf("\n");

    // Exercício 12: Implemente uma função que receba um array de inteiros e retorne a soma de seus elementos.
    printf("12)\n");
    printf("Soma: %d\n", somaTodos(10, inteiros));
    printf("\n");

    // Exercício 13: Escreva um programa que use ponteiros para encontrar o maior elemento em um array de inteiros.
    printf("13)\n");
    printf("Maior: %d\n", encontrarMaior(10, inteiros));
    printf("\n");

    // Exercício 14: Crie uma função que receba uma string e retorne o número de vogais usando ponteiros.
    printf("14)\n");
    char string[10] = "aeiou";
    char *ptr_string = &string[0];
    printf("Número de vogais: %d\n", contarVogais(ptr_string));
    printf("\n");
    
    return 0;
}
