
# **Labirinto C**

## **Membros da Equipe**
- Maria Julia Germano - [GitHub](https://github.com/MariaJuliaGermano)
- Ricardo Block - [GitHub](https://github.com/RicardoBV)

## **Informações do Projeto**
- **Disciplina**: Programação Imperativa e Funcional - 2024.2
- **Instituição**: CESAR School

---

## **Descrição do Jogo**

Bem-vindo ao renovado Labirinto SI! Aqui você embarcará na jornada do bravo "S" (o estudante de Sistemas de Informação) em sua missão de alcançar o misterioso e poderoso "I". Não há atalhos, não há bônus: é dedicação pura, muito esforço, e algumas lágrimas de café para chegar ao final.

---

## **Mecânica do Jogo**

1. **Objetivo**:
   - Mover o personagem (`@`) até a saída (`E`) do labirinto.

2. **Regras**:
   - O jogador inicia com um número fixo de jogadas.
   - Cada movimento reduz o número de jogadas restantes.
   - O jogador perde se o número de jogadas chegar a zero.
   - O jogo termina imediatamente ao alcançar a saída.

3. **Comandos**:
   - `W`: Mover para cima.
   - `A`: Mover para a esquerda.
   - `S`: Mover para baixo.
   - `D`: Mover para a direita.
   - `Enter`: Encerrar o jogo.

---

## **Estrutura de Pastas**

- `src/`: Contém o código-fonte do jogo, em arquivos `.c`.
  - `main.c`: Arquivo principal que inicializa o jogo.
  - `maze.c`: Implementa a lógica do labirinto.
  - `keyboard.c`: Captura as entradas do teclado.
  - `screen.c`: Gerencia a exibição visual no console.
  - `timer.c`: Manipula o tempo do jogo (opcional para expansão futura).
- `include/`: Contém os cabeçalhos (.h) necessários para o projeto.
  - `maze.h`: Declarações das funções e estruturas do labirinto.
  - `keyboard.h`: Declarações das funções de entrada do teclado.
  - `screen.h`: Declarações das funções de exibição visual.
  - `timer.h`: Declarações das funções relacionadas ao temporizador.
- `build/`: Pasta destinada às saídas da compilação.
- `README.md`: Arquivo de descrição do projeto.
- `Makefile`: Arquivo de build.
- `LICENSE`: Licença do projeto.

---

## **Instruções para Compilar e Executar**

### **Requisitos do Sistema**

Certifique-se de que o sistema possui:
- **Compilador `gcc`**: Necessário para compilar o código C.

### **Clonando o Repositório**

Se ainda não possui o projeto em sua máquina, clone o repositório Git:

```bash
git clone https://github.com/MariaJuliaGermano/projeto-c.git
cd projeto-c
```

---

### **Compilando o Jogo**

Este projeto utiliza um **Makefile** para simplificar o processo de compilação:

1. **Compile o projeto**:
   ```bash
   make
   ```

2. **Verifique se a compilação foi bem-sucedida**:
   - O executável do jogo será criado na pasta `build/` com o nome `labirinto`.

---

### **Executando o Jogo**

1. Execute o jogo:
   ```bash
   ./build/labirinto
   ```

---