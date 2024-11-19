#ifndef SCREEN_H
#define SCREEN_H

#include <stdio.h>

// Funções existentes
void clear_screen(); // Limpa a tela do terminal
void draw_maze(char **maze, int rows, int cols); // Desenha o labirinto na tela

// Funções da CLI-lib
void screenInit(int drawBorders);
void screenDestroy();
void screenGotoxy(int x, int y);
void screenSetColor(int fg, int bg);

#endif
