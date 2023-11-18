#include <stdio.h>

int obterValor(int *ptr) {
    return *ptr;
}

void atribuirValor10(int *ptr) {
    *ptr = 10;
}

void trocarValores(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int encontrarValorMaximo(int *matriz, int linhas, int colunas) {
    int maximo = matriz[0];

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i * colunas + j] > maximo) {
                maximo = matriz[i * colunas + j];
            }
        }
    }

    return maximo;
}

int contarZeros(int *matriz, int linhas, int colunas) {
    int count = 0;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i * colunas + j] == 0) {
                count++;
            }
        }
    }

    return count;
}


int main() {
    int numero1 = 5;
    int numero2 = 5;
    
    // Exercício 1: Escreva uma função que recebe um ponteiro para um inteiro e retorna o valor armazenado nesse ponteiro.
    printf("1)\n");
    printf("Valor: %d\n", obterValor(&numero1));
    printf("\n");

    // Exercício 2: Escreva uma função que recebe um ponteiro para um inteiro e atribui o valor 10 a esse ponteiro.
    printf("2)\n");
    atribuirValor10(&numero1);
    printf("Valor: %d\n", numero1);
    printf("\n");

    // Exercício 3: Escreva uma função que recebe dois ponteiros para inteiros e troca os valores armazenados nesses ponteiros.
    printf("3)\n");
    printf("Antes: %d %d\n", numero1, numero2);
    trocarValores(&numero1, &numero2);
    printf("Depois: %d %d\n", numero1, numero2);
    printf("\n");

    // Exercício 4: Escreva uma função que recebe um ponteiro para uma matriz de inteiros e retorna o valor máximo armazenado nessa matriz.
    printf("4)\n");
    int matriz[2][3] = {{7, 20, 13}, {4, 0, 16}};
    int *ptr_matriz = &matriz[0][0];
    printf("Valor máximo: %d\n", encontrarValorMaximo(ptr_matriz, 2, 3));
    printf("\n");

    // Exercício 5: Escreva uma função que recebe um ponteiro para uma matriz de inteiros e retorna o número de elementos iguais a 0.
    printf("5)\n");
    printf("Número de zeros: %d\n", contarZeros(ptr_matriz, 2, 3));
    printf("\n");

    // Exercício 11: Crie uma função que troque o valor de duas variáveis usando ponteiros.
    printf("11)\n");
    printf("Antes: %d %d\n", numero1, numero2);
    trocarValores(&numero1, &numero2);
    printf("Depois: %d %d\n", numero1, numero2);
    printf("\n");

    return 0;
}
