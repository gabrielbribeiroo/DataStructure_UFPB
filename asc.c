#include <stdio.h>

int main() {
    // Apenas uma variável será usada
    for (int ascii = 32; ascii <= 126; ascii++) {
        // Imprime o código ASCII em decimal e seu caractere correspondente
        printf("Codigo: %d -> Caractere: %c\n", ascii, ascii);
    }

    return 0;
}