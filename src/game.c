#include <stdio.h>
#include <string.h>
#include "keyboard.h"
#include "screen.h"
#include "timer.h"
#include "game.h"

void inicializa_palavra(JogoForca *jogo) {
    int tamanho = strlen(jogo->palavra_secreta);
    for (int i = 0; i < tamanho; i++) {
        jogo->letras_acertadas[i] = '_';
    }
    jogo->letras_acertadas[tamanho] = '\0';
    jogo->pontuacao = 0;  
    jogo->tentativas_restantes = 6; 
}

void exibir_status(JogoForca *jogo) {
    screenSetColor(WHITE, BLACK);
    screenGotoxy(SCRSTARTX, SCRSTARTY);
    printf("Palavra: %s\n", jogo->letras_acertadas);
    screenGotoxy(SCRSTARTX, SCRSTARTY + 1);
    printf("Tentativas restantes: %d\n", jogo->tentativas_restantes);
    screenGotoxy(SCRSTARTX, SCRSTARTY + 2);
    printf("Pontuação: %d\n", jogo->pontuacao);
    screenUpdate();
}

int verifica_letra(char letra, JogoForca *jogo) {
    int acertou = 0;
    for (int i = 0; i < strlen(jogo->palavra_secreta); i++) {
        if (jogo->palavra_secreta[i] == letra && jogo->letras_acertadas[i] == '_') {
            jogo->letras_acertadas[i] = letra;
            acertou = 1;
            jogo->pontuacao += 10; 
        }
    }
    if (!acertou) {
        jogo->pontuacao -= 5; 
        jogo->tentativas_restantes--; 
    }
    return acertou;
}

int jogo_completo(JogoForca *jogo) {
    return strchr(jogo->letras_acertadas, '_') == NULL;
}

void start_game() {
    JogoForca jogo = {.palavra_secreta = "programacao"}; 
    inicializa_palavra(&jogo);
    screenInit(1); 

    while (jogo.tentativas_restantes > 0) {
        exibir_status(&jogo);

        if (keyhit()) {
            char letra = readch();
            verifica_letra(letra, &jogo);

            if (jogo_completo(&jogo)) {
                screenGotoxy(SCRSTARTX, SCRENDY - 2);
                printf("Parabéns! Você acertou a palavra: %s\n", jogo.palavra_secreta);
                printf("Pontuação final: %d\n", jogo.pontuacao);
                break;
            }
        }
        
        timerUpdateTimer(500);
        if (timerTimeOver()) {
            screenGotoxy(SCRSTARTX, SCRENDY - 3);
            timerPrint();
            screenUpdate();
        }
    }

    if (jogo.tentativas_restantes == 0) {
        screenGotoxy(SCRSTARTX, SCRENDY - 2);
        printf("Você perdeu! A palavra era: %s\n", jogo.palavra_secreta);
        printf("Pontuação final: %d\n", jogo.pontuacao);
    }

    screenDestroy();
}
