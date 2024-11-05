#ifndef GAME_H
#define GAME_H

typedef struct {
    char palavra_secreta[20];
    int tentativas_restantes;
    char letras_acertadas[20];
    int pontuacao;
} JogoForca;

void start_game();
void inicializa_palavra(JogoForca *jogo);
void exibir_status(JogoForca *jogo);
int verifica_letra(char letra, JogoForca *jogo);
int jogo_completo(JogoForca *jogo);

#endif
