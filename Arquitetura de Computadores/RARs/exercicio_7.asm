
      # ------------------------------------------------------------
      # Exercício 07 - Versão RISC-V
      # Trecho em C: int f = (g + h) - (i + j);
      # ------------------------------------------------------------

              .text
              j main

      leaf_example:
              add a5, a1, a2       # a5 = g + h
              add a6, a3, a4       # a6 = i + j
              sub a0, a5, a6       # f = (g + h) - (i + j), resultado em a0
              jr ra                # retorna para o chamador

      main:
              addi a1, zero, 4     # g = 4
              addi a2, zero, 7     # h = 7
              addi a3, zero, 2     # i = 2
              addi a4, zero, 1     # j = 1
              jal leaf_example     # chama a função
              nop                  # a0 agora tem o valor de retorno (f)
    