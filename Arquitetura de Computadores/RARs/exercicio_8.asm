
      # ------------------------------------------------------------
      # Exercício 08 - Versão RISC-V
      # Trecho em C: int f = (g + h) - (i + j);
      # ------------------------------------------------------------

              .text
              j main	

      leaf_example:
              addi sp, sp, -12      # ajusta a pilha para 3 registradores
              sw   t1, 8(sp)        # salva t1
              sw   t0, 4(sp)        # salva t0
              sw   s0, 0(sp)        # salva s0

              add  t0, a1, a2       # t0 = g + h
              add  t1, a3, a4       # t1 = i + j
              sub  s0, t0, t1       # f = t0 - t1
              add  a0, s0, zero     # retorno em a0

              lw   s0, 0(sp)        # restaura s0
              lw   t0, 4(sp)        # restaura t0
              lw   t1, 8(sp)        # restaura t1
              addi sp, sp, 12       # libera espaço na pilha
              jr   ra               # retorna da função

      main:
              addi t1, zero, 1
              addi t0, zero, 2
              addi s0, zero, 3

              addi a1, zero, 4      # g
              addi a2, zero, 7      # h
              addi a3, zero, 2      # i
              addi a4, zero, 1      # j

              jal leaf_example      # chama leaf_example
              nop                   # resultado em a0
    