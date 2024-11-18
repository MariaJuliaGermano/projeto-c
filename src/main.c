#include "keyboard.h"
#include "screen.h"
#include "timer.h"
#include <stdio.h>

int main() {
    char maze[5][5] = {
        {'#', '#', '#', '#', '#'},
        {'#', '@', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', 'E', '#'},
        {'#', '#', '#', '#', '#'}
    };

    int player_x = 1, player_y = 1;
    Timer timer;
    start_timer(&timer); // Inicia o temporizador

    while (1) {
        clear_screen();

        // Calcula o tempo restante
        int elapsed_time = get_elapsed_time(&timer);
        int time_limit = 30; // Limite de tempo em segundos
        int time_left = time_limit - elapsed_time;

        // Exibe o tempo restante e o labirinto
        printf("Tempo restante: %d segundos\n", time_left);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                printf("%c", maze[i][j]);
            }
            printf("\n");
        }

        // Verifica se o tempo acabou
        if (time_left <= 0) {
            printf("Tempo esgotado! Game Over.\n");
            break;
        }

        // Captura a entrada do jogador
        char key = get_key();

        int new_x = player_x;
        int new_y = player_y;

        if (key == 'w') new_x--;
        else if (key == 's') new_x++;
        else if (key == 'a') new_y--;
        else if (key == 'd') new_y++;

        // Valida o movimento
        if (maze[new_x][new_y] == ' ') {
            maze[player_x][player_y] = ' ';
            player_x = new_x;
            player_y = new_y;
            maze[player_x][player_y] = '@';
        } else if (maze[new_x][new_y] == 'E') {
            clear_screen();
            printf("Parabéns! Você venceu!\n");
            break;
        }
    }

    return 0;
}
