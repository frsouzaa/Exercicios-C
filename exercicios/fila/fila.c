#include <stdlib.h>
#include <stdio.h>

struct Node {
    int doc;
    char *nome;
    struct Node *next;
};

typedef struct Node Node;

struct List {
    Node *head;
    Node *tail;
};

typedef struct List List;

struct Node* criarNo(int doc, char *nome) {
    struct Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("\nErro: Não foi possível alocar memória para o novo nó.\n");
        exit(1);
    }
    node->doc = doc;
    node->nome = nome;
    node->next = NULL;
    return node;
}

void criarListaVazia(List *list) {
    list->head = NULL;
    list->tail = NULL;
}

void inserir(List *list, int doc, char *nome) {
    Node *node = criarNo(doc, nome);
    if (list->head == NULL) {
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
}

void remover(List *list) {
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
    }
    free(temp);
}

void inserirCliente(List *fila) {
    size_t len = 10;
    char *nome = malloc(len);
    char *doc = malloc(len);
    printf("Digite o nome do cliente: ");
    getline(&nome, &len, stdin);
    printf("Digite o numero do documento do cliente: ");
    getline(&doc, &len, stdin);
    inserir(fila, ((int)*doc) - 48, nome);
}

int main() {
    List fila;
    criarListaVazia(&fila);

    // Exercício 15: Escreva uma função para inserir um elemento em uma fila.
    printf("15)\n");
    inserir(&fila, 1, "teste");
    inserir(&fila, 1, "teste");
    inserir(&fila, 1, "teste");
    printf("\n");


    // Exercício 16: Implemente uma função para remover um elemento de uma fila.
    printf("16)\n");
    remover(&fila);
    remover(&fila);
    remover(&fila);
    printf("\n");

    // Exercício 17: Escreva um programa que use uma fila para simular o processo de atendimento em uma fila de banco.
    printf("17)");
    size_t len = 1;
    char *escolha = malloc(len);
    while (*escolha != '3') {
        printf("\n-------Menu-------\n1) Inserir cliente\n2) Atender cliente\n3) Sair\nEscolha: ");
        getline(&escolha, &len, stdin);
        switch (*escolha) {
            case '1':
                inserirCliente(&fila);
                printf("Cliente inserido.\n");
                break;
            case '2':
                remover(&fila);
                printf("Cliente atendido.\n");
                break;
            case '3':
                printf("Saindo...\n");
                break; 
            default:
                printf("Opção inválida.\n");
                break;
        }
    }
    

    
    return 0;
}
