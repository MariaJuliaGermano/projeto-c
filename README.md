# Jogo da Forca

## Membros da Equipe
- Maria Julia Germano - [GitHub](https://github.com/seu_usuario)
- Ricardo Block - [GitHub](https://github.com/seu_usuario)

## Informações do Projeto
- **Disciplina**: Programação Imperativa e Funcional - 2024.2
- **Instituição**: CESAR School

## Descrição do Jogo
Este é um jogo da forca desenvolvido em C utilizando a biblioteca CLI-lib, que permite interação via terminal com entrada de teclado e manipulação visual de elementos no console.

O objetivo do jogo é adivinhar uma palavra secreta, letra por letra. O jogador tem um número limitado de tentativas para acertar todas as letras antes que suas chances se esgotem. O jogo exibe o progresso a cada rodada, mostrando as letras corretas descobertas, a quantidade de tentativas restantes e a pontuação.

## Mecânica do Jogo
1. **Objetivo**: Adivinhar a palavra secreta antes de esgotar todas as tentativas.
2. **Progresso**: A cada tentativa, o jogo exibe o estado atual da palavra, mostrando as letras acertadas e `_` para letras ainda não descobertas.
3. **Tentativas**: Cada letra errada reduz o número de tentativas restantes.
4. **Pontuação**: O jogador ganha 10 pontos para cada letra correta e perde 5 pontos para cada tentativa incorreta.
5. **Condições de Vitória**: O jogador vence se adivinhar todas as letras antes de acabar as tentativas. Se as tentativas se esgotarem, o jogador perde, e a palavra correta é exibida.


## Estrutura de Pastas
- `src/`: Contém o código-fonte do jogo, em arquivos `.c`.
  - `main.c`: Arquivo principal que inicializa o jogo.
  - `game.c`: Implementa a lógica da mecânica do jogo da forca.
  - `keyboard.c`: Gerencia a captura da entrada do teclado.
  - `screen.c`: Gerencia a exibição visual no console.
- `include/`: Contém os cabeçalhos (.h) necessários para o projeto.
  - `game.h`: Declarações das funções do jogo e definição da `struct JogoForca`.
  - `keyboard.h`: Declarações das funções de captura do teclado.
  - `screen.h`: Declarações das funções de exibição visual.
- `build/`: Pasta destinada às saídas da compilação.
- `README.md`: Arquivo de descrição do projeto.
- `Makefile`: Arquivo de build.
- `LICENSE`: Licença do projeto.


## Instruções para Compilar e Executar
1. **Compilar o Jogo**:
   - No terminal, navegue até a pasta do projeto e execute:
     ```bash
     make
     ```
   - Isso criará o executável na pasta `build/`.

2. **Executar o Jogo**:
   - Para iniciar o jogo, execute o seguinte comando:
     ```bash
     ./build/jogo
     ```

3. **Limpar a Compilação**:
   - Para remover os arquivos de compilação, execute:
     ```bash
     make clean
     ```

