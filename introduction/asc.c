#include <stdio.h>

int main() {
    // Apenas uma variável char será usada
    unsigned char ascii; // Extensão do valor da variável

    for (ascii = 0; ascii < 255; ascii++) {
        // Imprime o código ASCII em decimal e seu caractere correspondente
        printf("Codigo: %d -> Caractere: %c\n", ascii, ascii);
    }
    printf("Codigo: %d -> Caractere: %c\n", ascii, ascii);

    return 0;
}