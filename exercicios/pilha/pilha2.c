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

void invertePilhaSemUmaPilhaAuxiliar(struct Pilha* pilha) {
    struct No* temp = pilha->top;
    struct No* temp2 = NULL;
    while (temp != NULL) {
        struct No* temp3 = temp->next;
        temp->next = temp2;
        temp2 = temp;
        temp = temp3;
    }
    pilha->top = temp2;
}

float calculaMediaPilha(struct Pilha* pilha) {
    float soma = 0, quant = 0;
    struct No* no = pilha->top;
    while (no != NULL) {
        soma += no->data;
        no = no->next;
        quant++;
    }
    return soma / quant;
}

void ordenaPilha(struct Pilha* pilha) {
    struct Pilha* pilhaOrd = criarPilha();
    while (pilha->top != NULL) {
        int temp = desempilha(pilha);
        while (!verificaPilhaVazia(pilhaOrd) && topoPilha(pilhaOrd) > temp) {
            empilha(pilha, desempilha(pilhaOrd));
        }
        empilha(pilhaOrd, temp);
    }
    pilha->top = pilhaOrd->top;
}

struct Pilha* copiaPilhaInvertida(struct Pilha* pilha) {
    struct Pilha* copiaInvertida = copiaPilha(pilha);
    invertePilha(copiaInvertida);
    return copiaInvertida;
}

struct Pilha* mesclaPilhas(struct Pilha* pilha1, struct Pilha* pilha2) {
    struct Pilha* pilhaMesclada = criarPilha();
    struct Pilha* copia1 = copiaPilha(pilha1);
    struct Pilha* copia2 = copiaPilha(pilha2);
    while (copia1->top != NULL && copia2->top != NULL) {
        empilha(pilhaMesclada, desempilha(copia1));
        empilha(pilhaMesclada, desempilha(copia2));
    }
    while (copia1->top != NULL) {
        empilha(pilhaMesclada, desempilha(copia1));
    }
    while (copia2->top != NULL) {
        empilha(pilhaMesclada, desempilha(copia2));
    }
    invertePilha(pilhaMesclada);
    return pilhaMesclada;
}

void removeElementoPilha(struct Pilha* pilha, int valor) {
    struct Pilha* pilhaTemp = criarPilha();
    while (pilha->top != NULL) {
        int temp = desempilha(pilha);
        if (temp != valor) {
            empilha(pilhaTemp, temp);
        }
    }
    while (pilhaTemp->top != NULL) {
        empilha(pilha, desempilha(pilhaTemp));
    }
}

struct Pilha* copiaNPrimeirosElementos(struct Pilha* pilha, int n) {
    struct Pilha* pilhaCopia = copiaPilhaInvertida(pilha);
    struct Pilha* pilhaTemp = criarPilha();
    for (int i = 0; i < n && pilhaCopia->top != NULL; i++) {
        empilha(pilhaTemp, desempilha(pilhaCopia));
    }
    return pilhaTemp;
}

struct Pilha* copiaElementosMaiores(struct Pilha* pilha, int limite){
    struct Pilha* pilhaCopia = copiaPilhaInvertida(pilha);
    struct Pilha* pilhaTemp = criarPilha();
    while (pilhaCopia->top != NULL) {
        int temp = desempilha(pilhaCopia);
        if (temp > limite) {
            empilha(pilhaTemp, temp);
        }
    }
    return pilhaTemp;
};

struct Pilha* copiaElementosMenores(struct Pilha* pilha, int limite){
    struct Pilha* pilhaCopia = copiaPilhaInvertida(pilha);
    struct Pilha* pilhaTemp = criarPilha();
    while (pilhaCopia->top != NULL) {
        int temp = desempilha(pilhaCopia);
        if (temp < limite) {
            empilha(pilhaTemp, temp);
        }
    }
    return pilhaTemp;
};

void insereOrdenadoPilha(struct Pilha* pilha, int valor) {
    empilha(pilha, valor);
    ordenaPilha(pilha);
}

int calculaSomaPilha(struct Pilha* pilha) {
    int soma = 0;
    struct No* no = pilha->top;
    while (no != NULL) {
        soma += no->data;
        no = no->next;
    }
    return soma;
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
    empilha(pilha1, 7);
    empilha(pilha1, 6);
    empilha(pilha1, 5);
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
    empilha(pilha1, 2);
    empilha(pilha1, 1);
    empilha(pilha1, 3);
    printf("pilha1: ");
    printPilha(pilha1);
    printf("pilha2: ");
    printPilha(pilha2);
    printf("pilha1 + pilha2: ");
    concatenaPilhas(pilha1, pilha2);
    printPilha(pilha1);
    printf("\n\n");

    // Exercício 11: Crie uma função chamada invertePilhaSemUmaPilhaAuxiliar que recebe uma pilha como parâmetro e inverte a ordem dos elementos na pilha original, sem usar uma pilha auxiliar.
    printf("11)\n");
    printf("pilha original:  ");
    printPilha(pilha1);
    invertePilhaSemUmaPilhaAuxiliar(pilha1);
    printf("pilha invertida: ");
    printPilha(pilha1);
    printf("\n\n");

    // Exercício 12: Crie uma função chamada calculaMediaPilha que recebe uma pilha de números inteiros como parâmetro e retorna a média dos valores na pilha.
    printf("12)\n");
    printf("pilha: ");
    printPilha(pilha1);
    printf("média: %.2f", calculaMediaPilha(pilha1));
    printf("\n\n");
    
    // Exercício 13: Crie uma função chamada ordenaPilha que recebe uma pilha de números inteiros como parâmetro e a ordena em ordem crescente.
    printf("13)\n");
    printf("pilha: ");
    printPilha(pilha1);
    printf("pilha ordenada: ");
    ordenaPilha(pilha1);
    printPilha(pilha1);
    printf("\n\n");

    // Exercício 14: Crie uma função chamada copiaPilhaInvertida que recebe uma pilha como parâmetro e retorna uma cópia invertida da pilha.
    printf("14)\n");
    printf("pilha original:  ");
    printPilha(pilha1);
    struct Pilha* pilha3 = copiaPilhaInvertida(pilha1);
    printf("copia invertida: ");
    printPilha(pilha3);
    printf("\n\n");

    // Exercício 15: Crie uma função chamada mesclaPilhas que recebe duas pilhas como parâmetros e mescla os elementos das duas pilhas em uma terceira pilha.
    printf("15)\n");
    printf("pilha1: ");
    printPilha(pilha1);
    printf("pilha2: ");
    printPilha(pilha2);
    struct Pilha* pilha4 = mesclaPilhas(pilha1, pilha2);
    printf("pilha mesclada: ");
    printPilha(pilha4);
    printf("\n\n");

    // Exercício 16: Crie uma função chamada removeElementoPilha que recebe uma pilha e um valor como parâmetros e remove todas as ocorrências desse valor na pilha.
    printf("16)\n");
    printf("pilha: ");
    printPilha(pilha4);
    printf("removendo o valor 6 da pilha...\n");
    printf("pilha: ");
    removeElementoPilha(pilha4, 6);
    printPilha(pilha4);
    printf("\n\n");

    // Exercício 17: Crie uma função chamada copiaNPrimeirosElementos que recebe uma pilha e um número n como parâmetros e retorna uma cópia dos primeiros n elementos da pilha.
    printf("17)\n");
    printf("pilha: ");
    printPilha(pilha4);
    printf("copia dos 3 primeiros elementos: ");
    struct Pilha* pilha5 = copiaNPrimeirosElementos(pilha4, 3);
    printPilha(pilha5);
    printf("\n\n");

    // Exercício 18: Crie uma função chamada copiaElementosMaiores que recebe uma pilha e um valor limite como parâmetros e retorna uma cópia dos elementos maiores que o limite na pilha.
    printf("18)\n");
    printf("pilha: ");
    printPilha(pilha4);
    printf("copia dos elementos maiores que 3: ");
    struct Pilha* pilha6 = copiaElementosMaiores(pilha4, 3);
    printPilha(pilha6);
    printf("\n\n");

    // Exercício 19: Crie uma função chamada copiaElementosMenores que recebe uma pilha e um valor limite como parâmetros e retorna uma cópia dos elementos menores que o limite na pilha.
    printf("19)\n");
    printf("pilha: ");
    printPilha(pilha4);
    printf("copia dos elementos menores que 3: ");
    struct Pilha* pilha7 = copiaElementosMenores(pilha4, 3);
    printPilha(pilha7);
    printf("\n\n");

    //Exercício 20: Crie uma função chamada insereOrdenadoPilha que recebe uma pilha e um valor como parâmetros e insere o valor na pilha de forma ordenada em ordem crescente.
    printf("20)\n");
    printf("pilha: ");
    printPilha(pilha4);
    printf("inserindo o valor 4 na pilha...\n");
    printf("pilha: ");
    insereOrdenadoPilha(pilha4, 4);
    printPilha(pilha4);
    printf("\n\n");

    // Exercício 21: Crie uma função chamada somaElementosPilha que recebe uma pilha como parâmetro e retorna a soma de todos os elementos na pilha.
    printf("21)\n");
    printf("pilha: ");
    printPilha(pilha4);
    printf("soma dos elementos: %d", calculaSomaPilha(pilha4));
    printf("\n\n");

    // Exercício 22: Crie uma função chamada copiaPilha que recebe uma pilha como parâmetro e retorna uma cópia idêntica da pilha original.
    printf("22)\n");
    struct Pilha* pilha8 = copiaPilha(pilha4);
    printf("pilha4: ");
    printPilha(pilha4);
    printf("pilha8: ");
    printPilha(pilha8);
    printf("\n");

    return 0;
}