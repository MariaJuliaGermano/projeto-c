/**
 * timer.h
 * Created on Aug, 23th 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"
 */

#ifndef __TIMER_H__
#define __TIMER_H__

/**
 * Inicializa o temporizador com um intervalo em milissegundos.
 * @param valueMilliSec O valor do intervalo em milissegundos.
 */
void timerInit(int valueMilliSec);

/**
 * Destrói o temporizador, liberando recursos associados.
 */
void timerDestroy();

/**
 * Atualiza o intervalo do temporizador.
 *  O novo valor do intervalo em milissegundos.
 */
void timerUpdateTimer(int valueMilliSec);

/**
 * Verifica se o tempo especificado pelo intervalo foi excedido.
 * @return 1 se o tempo foi excedido, 0 caso contrário.
 */
int timerTimeOver();

/**
 * Exibe o tempo decorrido desde a última atualização do temporizador.
 */
void timerPrint();

#endif /* __TIMER_H__ */
