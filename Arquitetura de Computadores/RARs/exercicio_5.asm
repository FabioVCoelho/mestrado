
      # ------------------------------------------------------------
      # Exercício 05 - Baseado em Patterson pág. 67 (versão RISC-V)
      # Trecho em C: while (save[i] == k) i = i + 1;
      # ------------------------------------------------------------

      .data
      Array_save: .word 3, 3, 1, 3, 3, 1, 4, 3, 1  # save[0] até save[8]

      .text
      main:
          la   s6, Array_save     # endereço base de save[]
          addi s5, zero, 3        # k = 3
          addi s3, zero, 0        # i = 0

      Loop:
          add  t1, s3, s3         # t1 = s3 * 2
          add  t1, t1, t1         # t1 = s3 * 4
          add  t1, t1, s6         # t1 = endereço de save[i]
          lw   t0, 0(t1)          # t0 = save[i]
          bne  t0, s5, Exit       # se save[i] != k, vai para Exit
          addi  s3, s3, 1         # i = i + j
          j    Loop               # repete o laço

      Exit:
          nop                    # fim do laço
    