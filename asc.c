#include <stdio.h>

int main() {
    // Apenas uma variável char será usada
    unsigned char ascii;

    for (ascii = 32; ascii <= 126; ascii++) {
        // Imprime o código ASCII em decimal e seu caractere correspondente
        printf("Codigo: %d -> Caractere: %c\n", ascii, ascii);
    }

    return 0;
}