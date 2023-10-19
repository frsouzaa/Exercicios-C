#include <stdio.h>

struct DadosArray {
    int maior;
    int menor;
    int soma;
    float media;
};

void printArray(int tamanho, int array[tamanho]) {
    for (int i = 0; i < tamanho; i++) printf("%d  ", array[i]);
}

void printMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        printArray(colunas, matriz[i]);
        printf("\n");
    }
}

int len(char texto2[]) {
    int tamanho;
    for (int i = 0; texto2[i] != 0; i++) tamanho = i;
    tamanho++;
    return tamanho;
}

int soma(int num1, int num2) {
    return num1 + num2;
}

void trocar(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

float somaArr(int tamanho, int numeros[tamanho]) {
    float soma = 0;
    for (int i = 0; i < tamanho; i++) soma += numeros[i];
    return soma;
}

float media(int tamanho, int numeros[tamanho]) {
    return somaArr(tamanho, numeros) / tamanho;
}

int maximo(int tamanho, int numeros[tamanho]) {
    int max = numeros[0];
    for (int i = 1; i < tamanho; i++) {
        if (numeros[i] > max) max = numeros[i];
    }
    return max;
}

void inverter(char texto[]) {
    int tamanho;
    for (int i = 0; texto[i] != 0; i++) tamanho = i;
    for (int i = 0, j = tamanho; i < j; i++, j--) {
        char temp = texto[j];
        texto[j] = texto[i];
        texto[i] = temp;
    }
}

int somaMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    int soma = 0;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) soma += matriz[i][j];
    }
    return soma;
}

void copiaString(char texto1[], char texto2[]) {
    int tamanho = len(texto1);
    for (int i = 0; i < tamanho; i++) texto2[i] = texto1[i];
}

void ordenaArray(int tamanho, int numeros[tamanho]) {
    int i = 0;
    while (1) {
        if (numeros[i] > numeros[i+1]) {
            int temp = numeros[i];
            numeros[i] = numeros[i+1];
            numeros[i+1] = temp;
            i = 0;
        } else {
            i++;
            if (i == tamanho-1) return;
        }
    }
    return;
}

int fatorial(int num) {
    int fatorial = num;
    for (int i = 1; i < num; i++) fatorial *= i;
    return fatorial;
}

int calculaPotencia(int base, int expoente) {
    int potencia = base;
    for (int i = 1; i < expoente; i ++) potencia *= base;
    return potencia;
}

void inverteArray(int tamanho, int numeros[tamanho]) {
    for (int i = 0, j = tamanho-1; i < j; i++, j--) {
        char temp = numeros[j];
        numeros[j] = numeros[i];
        numeros[i] = temp;
    }
}

int calculaMDC(int num1, int num2) {
    int resto;
    while (resto != 0) {
        resto = num1 % num2;
        num1 = num2;
        num2 = resto;
        if (resto == 0) break;
    };
    return num1;
}

int calculaFibonacci(int posicao) {
    if (posicao == 1 || posicao == 0) return 0;
    if (posicao == 2) return 1;
    int num1 = 0, num2 = 1;
    for (int i = 0; i < posicao-2; i++) {
        int temp = num1;
        num1 = num2;
        num2 = num2 + temp;
    }
    return num2;
}

int contaCaracteres(char texto[], char letra) {
    int quantidade = 0;
    for (int i = 0; texto[i] != 0; i++) {
        if (texto[i] == letra) quantidade++;
    }
    return quantidade;
}

float calculaMediaMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    int soma = somaMatriz(linhas, colunas, matriz);
    return (float)soma / (linhas * colunas);
}

float calculaMediaPonderada(int tamanho, float notas[tamanho], float pesos[tamanho]) {
    float somaNotaPeso = 0;
    float somaPeso = 0;
    for (int i = 0; i < tamanho; i++) {
        somaNotaPeso += notas[i] * pesos[i];
        somaPeso += pesos[i];
    }
    return somaNotaPeso / somaPeso;
}

int minimo(int tamanho, int numeros[tamanho]) {
    int min = numeros[0];
    for (int i = 1; i < tamanho; i++) {
        if (numeros[i] < min) min = numeros[i];
    }
    return min;
}

struct DadosArray maiorMenor(int tamanho, int numeros[tamanho]) {
    struct DadosArray dados;
    dados.maior = maximo(tamanho, numeros);
    dados.menor = minimo(tamanho, numeros);
    return dados;
}

struct DadosArray calculaSomaMedia(int tamanho, int numeros[tamanho]) {
    struct DadosArray dados;
    dados.soma = somaArr(tamanho, numeros);
    dados.media = media(tamanho, numeros);
    return dados;
}

void inverteMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    int i, j, k;
    for (i = 0, j = linhas-1; i < j; i++, j--) {
        for (k = 0; k < colunas; k++) {
            int temp = matriz[i][k];
            matriz[i][k] = matriz[j][k];
            matriz[j][k] = temp;
        }
    }
}

int contaPalavras(char *texto) {
    int tamanho = len(texto);
    if (tamanho == 0) return 0;
    int quant = 0;
    if (texto[0] != ' ') quant = 1;
    for (int i = 1; i < tamanho; i++) {
        if (texto[i] != ' ' && texto[i-1] == ' ') quant++;
    }
    return quant;
}

int calculaMaiorProduto(int tamanho, int numeros[tamanho]) {
    if (tamanho == 1) return numeros[0];
    if (tamanho == 2) return numeros[0] * numeros[1];
    int maior, maior2;
    if (numeros[0] > numeros[1]) {
        maior = numeros[0];
        maior2 = numeros[1];
    } else {
        maior = numeros[1];
        maior2 = numeros[0];
    }
    for(int i = 2; i < tamanho; i++) {
        if (numeros[i] > maior) {
            maior2 = maior;
            maior = numeros[i];
        } else if (numeros[i] > maior2) {
            maior2 = numeros[i];
        }
    }
    return maior * maior2;
}

int verificaPalindromo(char *texto) {
    int i, j;
    for (i = 0, j = len(texto) - 1; i < j; i++, j--) {
        if (texto[i] != texto[j]) {
            return 0;
        }
    }
    return 1;
}

void copiaMatriz(int linhas, int colunas, int original[linhas][colunas], int copia[linhas][colunas]) {
    int i, j;
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            copia[i][j] = original[i][j];
        }
    }
}

int contaCaracteresUnicos(char *texto) {
    int i, j;
    int soma = 0;
    int unico = 1;
    for (i = 0; i < len(texto); i++) {
        unico = 1;
        for (j = 0; j < len(texto); j++) {
            if (texto[i] == texto[j] && i != j) {
                unico = 0;
                break;
            }
        }
        if (unico) soma++;
    }
    return soma;
}

int main() {
    int num1 = 10; 
    int num2 = 20;
    int numeros[] = {9, 4, 7};
    char texto1[] = "abcdedcba";
    char texto2[] = "123456789";
    int matriz1[3][3] = {
        {1, 2, 4},
        {9, 3, 0},
        {6, 7, 5},
    };
    int matriz2[4][4] = {
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {3, 3, 3, 3},
    };
    float notas[] = {8.9, 9.2, 5.3, 0.2};
    float pesos[] = {10, 2, 1, 5.5};
    char texto3[] = "a b j b a h";

    // Exercício 1: Crie uma função chamada soma que recebe dois inteiros como parâmetros e retorna a soma deles.
    printf("1)\n");
    printf("num1 + num2 = %d", soma(num1, num2));
    printf("\n\n");

    // Exercício 2: Crie uma função chamada trocar que recebe dois inteiros como parâmetros e troca seus valores.
    printf("2)\n");
    printf("num1 = %d; num2 = %d", num1, num2);
    trocar(&num1, &num2);
    printf("\nnum1 = %d; num2 = %d", num1, num2);
    printf("\n\n");

    // Exercício 3: Crie uma função chamada media que recebe um array de números inteiros e seu tamanho como parâmetros e retorna a média dos valores no array
    printf("3)\n");
    printf("média = %f", media(3, numeros));
    printf("\n\n");

    // Exercício 4: Crie uma função chamada maximo que recebe um array de números inteiros e seu tamanho como parâmetros e retorna o valor máximo no array.
    printf("4)\n");
    printf("máximo = %d", maximo(3, numeros));
    printf("\n\n");

    // Exercício 5: Crie uma função chamada inverter que recebe uma string como parâmetro e a inverte (sem usar funções de string).
    printf("5)\n");
    printf("String original = %s", texto1);
    inverter(texto1);
    printf("\nString inversa = %s", texto1);
    printf("\n\n");

    // Exercício 6: Crie uma função chamada somaMatriz que recebe uma matriz de inteiros e suas dimensões como parâmetros e retorna a soma de todos os elementos da matriz.
    printf("6)\n");
    printf("soma da matriz = %d", somaMatriz(3, 3, matriz1));
    printf("\n\n");

    // Exercício 7: Crie uma função chamada copiaString que recebe duas strings como parâmetros e copia o conteúdo da primeira para a segunda.
    printf("7)\n");
    printf("texto1 = %s", texto1);
    printf("\ntexto2 = %s", texto2);
    copiaString(texto1, texto2);
    printf("\ntexto1 = %s", texto1);
    printf("\ntexto2 = %s", texto2);
    printf("\n\n");

    // Exercício 8: Crie uma função chamada ordenaArray que recebe um array de inteiros como parâmetro e o ordena em ordem crescente.
    printf("8)\n");
    printArray(3, numeros);
    printf("\n");
    ordenaArray(3, numeros);
    printArray(3, numeros);
    printf("\n\n");

    // Exercício 9: Crie uma função chamada fatorial que recebe um número inteiro como parâmetro e retorna o fatorial desse número.
    printf("9)\n");
    printf("o fatorial de %d é %d", num2, fatorial(num2));
    printf("\n\n");

    // Exercício 12: Crie uma função chamada calculaPotencia que recebe dois números inteiros como parâmetros, base e expoente, e retorna a base elevada ao expoente.
    printf("12)\n");
    printf("2 ^ 3 = %d", calculaPotencia(2, 3));
    printf("\n\n");

    // Exercício 13: Crie uma função chamada inverteArray que recebe um array de inteiros como parâmetro e inverte a ordem dos elementos no array.
    printf("13)\n");
    printArray(3, numeros);
    printf("\n");
    inverteArray(3, numeros);
    printArray(3, numeros);
    printf("\n\n");

    // Exercício 14: Crie uma função chamada calculaMDC que recebe dois números inteiros como parâmetros e retorna o máximo divisor comum (MDC) entre eles.
    printf("14)\n");
    printf("MDC 45 e 10 é %d", calculaMDC(45, 10));
    printf("\n\n");

    // Exercício 15: Crie uma função chamada calculaFibonacci que recebe um número inteiro positivo como parâmetro e retorna o número na sequência de Fibonacci correspondente à posição dada.
    printf("15)\n");
    printf("fibonacci na posição 13 é %d", calculaFibonacci(13));
    printf("\n\n");

    // Exercício 16: Crie uma função chamada contaCaracteres que recebe uma string e um caractere como parâmetros e retorna o número de vezes que o caractere aparece na string.
    printf("16)\n");
    printf("o caractere 'o' aparece %d vezes no texto \"%s\"", contaCaracteres(texto1, 'o'), texto1);
    printf("\n\n");
    
    // Exercício 17: Crie uma função chamada calculaMediaMatriz que recebe uma matriz de inteiros e suas dimensões como parâmetros e retorna a média de todos os elementos da matriz.
    printf("17)\n");
    printf("a média da matriz é %f", calculaMediaMatriz(3, 3, matriz1));
    printf("\n\n");

    // Exercício 18: Crie uma função chamada invertePalavra que recebe uma palavra (string) como parâmetro e inverte a ordem das letras na palavra.
    printf("18)\n");
    printf("String original = %s", texto1);
    inverter(texto1);
    printf("\nString inversa = %s", texto1);
    printf("\n\n");

    // Exercício 19: Crie uma função chamada calculaMediaPonderada que recebe dois arrays (um de notas e outro de pesos) e o número de elementos como parâmetros e retorna a média ponderada das notas.
    printf("19)\n");
    printf("média ponderada é %f", calculaMediaPonderada(4, notas, pesos));
    printf("\n\n");

    // Exercício 20: Crie uma função chamada maiorMenor que recebe um array de inteiros e seu tamanho como parâmetros e retorna o maior e o menor valor no array.
    printf("20)\n");
    struct DadosArray dados1 = maiorMenor(3, numeros);
    printf("maior = %d", dados1.maior);
    printf("\nmenor = %d", dados1.menor);
    printf("\n\n");

    // Exercício 21: Crie uma função chamada calculaSomaMedia que recebe um array de inteiros e seu tamanho como parâmetros e calcula a soma e a média dos valores no array, retornando ambos os resultados.
    printf("21)\n");
    struct DadosArray dados2 = calculaSomaMedia(3, numeros);
    printf("soma = %d", dados2.soma);
    printf("\nmedia = %f", dados2.media);
    printf("\n\n");

    // Exercício 22: Crie uma função chamada inverteMatriz que recebe uma matriz de inteiros e suas dimensões como parâmetros e inverte a ordem das linhas da matriz.
    printf("22)\n");
    printMatriz(4, 4, matriz2);
    printf("invertendo...\n");
    inverteMatriz(4, 4, matriz2);
    printMatriz(4, 4, matriz2);
    printf("\n");

    // Exercício 23: Crie uma função chamada contaPalavras que recebe uma string como parâmetro e retorna o número de palavras na string. Considere que as palavras são separadas por espaços em branco.
    printf("23)\n");
    printf("a string \"%s\" tem %d palavras", texto3, contaPalavras(texto3));
    printf("\n\n");

    // Exercício 24: Crie uma função chamada calculaMaiorProduto que recebe um array de inteiros como parâmetro e seu tamanho e retorna o maior produto entre quaisquer dois elementos do array.
    printf("24)\n");
    printArray(3, numeros);
    printf("\nO maior produto do array é %d", calculaMaiorProduto(3, numeros));
    printf("\n\n");

    // Exercício 25: Crie uma função chamada verificaPalindromo que recebe uma string como parâmetro e retorna 1 se a string for um palíndromo (ou seja, lê-se da mesma forma da esquerda para a direita e da direita para a esquerda) e 0 caso contrário.
    printf("25)\n");
    printf("a string %s ", texto1);
    if (verificaPalindromo(texto1) == 1) printf("é um palindromo");
    else printf("não é um palindromo");
    printf("\n\n");

    // Exercício 26: Crie uma função chamada copiaMatriz que recebe uma matriz de inteiros e suas dimensões como parâmetros e retorna uma cópia da matriz.
    printf("26)\n");
    printMatriz(3, 3, matriz1);
    printf("copiando...\n");
    int matriz3[3][3];
    copiaMatriz(3, 3, matriz1, matriz3);
    printMatriz(3, 3, matriz3);
    printf("\n\n");

    // Exercício 27: Crie uma função chamada contaCaracteresUnicos que recebe uma string como parâmetro e retorna o número de caracteres únicos na string.
    printf("27)\n");
    printf("a string \"%s\" possui %d caracteres unicos", texto3, contaCaracteresUnicos(texto3));
    printf("\n\n");
    
    return 0;
}