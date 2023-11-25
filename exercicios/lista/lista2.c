#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Node;

struct List
{
    Node *head;
};
typedef struct List List;

void initList(List *list)
{
    list->head = NULL;
}

Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int len(List *list)
{
    if (list->head == NULL)
    {
        return 0;
    }
    Node *aux = list->head;
    int count = 0;
    while (aux != NULL)
    {
        count++;
        aux = aux->next;
    }
    return count;
}

void printList(List *list)
{
    printf("\n");
    if (list->head == NULL)
    {
        return;
    }
    Node *aux = list->head;
    while (aux != NULL)
    {
        printf("%d ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

void append(List *list, int data)
{
    if (list->head == NULL)
    {
        list->head = createNode(data);
        return;
    }
    Node *aux = list->head;
    while (aux->next != NULL)
    {
        aux = aux->next;
    }
    aux->next = createNode(data);
}

void removeFirst(List *list)
{
    if (list->head == NULL)
    {
        return;
    }
    Node *aux = list->head;
    list->head = aux->next;
    free(aux);
}

void removeLast(List *list)
{
    if (list->head == NULL)
    {
        return;
    }
    Node *aux = list->head;
    if (aux->next == NULL)
    {
        free(aux);
        list->head = NULL;
        return;
    }
    while (aux->next->next != NULL)
    {
        aux = aux->next;
    }
    free(aux->next);
    aux->next = NULL;
}

void removeValue(List *list, int data)
{
    if (list->head == NULL)
    {
        return;
    }
    Node *aux = list->head;
    if (aux->data == data)
    {
        free(aux);
        list->head = NULL;
        return;
    }
    while (1)
    {
        if (aux->next == NULL)
        {
            return;
        }
        if (aux->next->data == data)
        {
            if (aux->next->next == NULL)
            {
                free(aux->next);
                aux->next = NULL;
                return;
            }
            else
            {
                Node *temp = aux->next;
                aux->next = temp->next;
                free(temp);
                return;
            }
        }
        aux = aux->next;
    }
}

void insert(List *list, int data, int posicao) {
    if (posicao < 0) {
        return;
    }
    if (posicao == 0 || list->head == NULL) {
        Node* node = createNode(data);
        node->next = list->head;
        list->head = node;
        return;
    }
    int count = 0;
    Node* aux = list->head;
    while (count < posicao-1 && aux->next != NULL) {
        aux = aux->next;
        count++;
    }
    Node* node = createNode(data);
    node->next = aux->next;
    aux->next = node;
}

int main()
{
    List list;

    initList(&list);

    // 1 - Escreva uma função que recebe uma lista encadeada e retorna o tamanho da lista.
    printf("Tamanho da lista: %d\n", len(&list));

    // 2 - Escreva uma função que recebe uma lista encadeada e imprime os elementos da lista na tela.
    printList(&list);

    // 3 - Escreva uma função que recebe uma lista encadeada e imprime os elementos da lista na tela.
    printList(&list);

    // 4 - Escreva uma função que recebe uma lista encadeada e insere um elemento no final da lista.
    printf("\nInserindo elementos na lista");
    append(&list, 1);
    append(&list, 1);
    append(&list, 2);
    append(&list, 3);
    append(&list, 5);
    append(&list, 8);
    append(&list, 13);
    printList(&list);
    printf("Tamanho da lista: %d\n", len(&list));

    // 5 - Escreva uma função que recebe uma lista encadeada e remove o primeiro elemento da lista.
    printf("\nRemovendo o primeiro elemento da lista");
    removeFirst(&list);
    printList(&list);
    printf("Tamanho da lista: %d\n", len(&list));

    // 6 - Escreva uma função que recebe uma lista encadeada e remove o último elemento da lista.
    printf("\nRemovendo o ultimo elemento da lista");
    removeLast(&list);
    printList(&list);
    printf("Tamanho da lista: %d\n", len(&list));

    // 7 - Escreva uma função que recebe uma lista encadeada e remove um elemento com um determinado valor.
    printf("\nRemovendo o elemento 5 da lista");
    removeValue(&list, 5);
    printList(&list);
    printf("Tamanho da lista: %d\n", len(&list));

    // 8 - Escreva uma função que recebe uma lista encadeada e insere um elemento em uma determinada posição.
    printf("\nInserindo elemento 9 na posicao 1 da lista");
    insert(&list, 9, 1);
    printList(&list);
    printf("Tamanho da lista: %d\n", len(&list));
}