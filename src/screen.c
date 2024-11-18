#include "screen.h"
#include <stdio.h>

void clear_screen() {
    printf("\033[2J\033[H"); // Sequência ANSI para limpar a tela
}

void print_at(int x, int y, char *text) {
    printf("\033[%d;%dH%s", x, y, text); // Move o cursor e imprime o texto
}
