# ForC-ode 

## Membros da Equipe
- Maria Julia Germano - [GitHub](https://github.com/MariaJuliaGermano)
- Ricardo Block - [GitHub](https://github.com/RicardoBV)

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

### Requisitos do Sistema

Certifique-se de que o sistema possui:
- **Compilador `gcc`**: Utilizado para compilar o código C.
- **CLI-lib**: Biblioteca instalada para interação no terminal. A CLI-lib é compatível com sistemas Linux e macOS.

### Clonando o Repositório
Se você ainda não possui o projeto em sua máquina, clone o repositório Git onde o projeto está armazenado.

```bash
git clone https://github.com/MariaJuliaGermano/projeto-c.git
cd projeto-c
```

### Compilando o Jogo

O projeto utiliza um `Makefile` que facilita a compilação dos arquivos. Esse arquivo automatiza o processo de construção do executável, compilando todos os arquivos `.c` do projeto e criando o executável na pasta `build/`.

- Acessando o Diretório do Projeto  
  Navegue até o diretório raiz do projeto onde o `Makefile` está localizado:
  ```bash
  cd /projeto-c
  ```

- Compilando o Projeto com Make  
  Execute o comando `make` para iniciar o processo de compilação:
  ```bash
  make
  ```
  Esse comando irá:
  - Compilar todos os arquivos `.c` na pasta `src/`.
  - Gerar arquivos `.o` (objetos intermediários) para cada arquivo `.c`.
  - Linkar esses arquivos objetos e criar o executável `jogo` na pasta `build/`.

- Verificando o Sucesso da Compilação  
  - Se a compilação for bem-sucedida, o executável `jogo` será criado na pasta `build/`.

### Executando o Jogo

Após a compilação bem-sucedida, você pode iniciar o jogo diretamente pelo terminal.

- Navegar até o Diretório `build/`
  ```bash
  cd build
  ```

- Executar o Jogo  
  Para iniciar o jogo, use o seguinte comando:
  ```bash
  ./jogo
  ```
  - Importante: Certifique-se de que o terminal possui suporte para CLI-lib e que você está executando em um sistema Linux ou macOS.
  - O jogo será exibido no terminal, onde você poderá interagir usando o teclado.

### Limpando os Arquivos de Compilação

Para remover todos os arquivos de compilação e deixar o diretório `build/` vazio, utilize o comando `make clean`. Isso é útil para manter o projeto organizado e liberar espaço.

```bash
make clean
```

Esse comando:
- Remove todos os arquivos intermediários `.o` gerados durante a compilação.
- Exclui o executável `jogo` na pasta `build/`, caso você queira recompilar a partir de um ambiente limpo.