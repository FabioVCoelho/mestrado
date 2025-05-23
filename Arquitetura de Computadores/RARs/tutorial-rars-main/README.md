# Tutorial do RARS (RISC-V Assembler and Runtime Simulator)

Este repositório contém um **tutorial completo** e **exercícios práticos** para uso do **RARS**, um simulador interativo para a arquitetura **RISC-V**.

## 🔗 Acesse o Simulador

Você pode baixar o RARS diretamente em: [https://github.com/TheThirdOne/rars](https://github.com/TheThirdOne/rars)

## Conteúdo do Repositório

- [`tutorial-rars.html`](tutorial-rars.html)  
  Página principal com explicações sobre o uso do simulador, montagem de programas, execução e visualização da memória.

- [`exercicio1.html`](exercicio1.html)  
  Exercício 01 baseado no livro do Patterson. Expressão em C: `f = (g + h) - (i + j)`

- [`exercicio2.html`](exercicio2.html)  
  Exercício 02 manipulando vetores na memória. Expressão em C: `A[12] = h + A[8]`

- [`exercicio3.html`](exercicio3.html)  
  Exercício 03 com instruções condicionais. Expressão em C:

  ```c
  if (i != j)
      f = g + h;
  f = f - i;
  ```

- [`exercicio4.html`](exercicio4.html)  
  Exercício 04 com instruções `if/else`. Expressão em C:

  ```c
  if (i == j)
      f = g + h;
  else
      f = g - h;
  ```

- [`exercicio5.html`](exercicio5.html)  
  Exercício 05 com laço `while`. Expressão em C:

  ```c
  while (save[i] == k) i = i + j;
  ```

- [`exercicio6.html`](exercicio6.html)  
  Exercício 06 com laço `for`. Expressão em C:

  ```c
  for (i = 0; i < 3; i++) j++;
  ```

- [`exercicio7.html`](exercicio7.html)  
  Exercício 06 com laço `for`. Expressão em C:

  ```c
  int f = (g + h) - (i + j);
  ```

- [`exercicio8.html`](exercicio8.html)  
  Exercício 06 com laço `for`. Expressão em C:
  ```c
  int f = (g + h) - (i + j);
  ```

## Como usar

1. Clone ou baixe este repositório:
   ```bash
   git clone https://github.com/eduardoMichell/tutorial-rars
   ```
2. Abra o arquivo tutorial-rars.html em um navegador moderno.

3. Siga o tutorial para entender o funcionamento do simulador.

4. Acesse os exercícios pelas páginas exercicio1.html até exercicio6.html para praticar os conceitos.

## Navegação entre páginas

Cada exercício possui um link no final para retornar ao tutorial principal, facilitando a continuidade dos estudos.

## Autoria

Autor: Eduardo Michel Deves de Souza

Revisão: Prof. Dr. Douglas Rossi de Melo
