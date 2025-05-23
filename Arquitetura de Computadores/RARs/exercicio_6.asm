      # ------------------------------------------------------------
      # Exercício 06 - Versão RISC-V
      # Trecho em C: for (i = 0; i < 3; i++) j++;
      # ------------------------------------------------------------
      
              .text
      main:   
              addi s0, zero, 0     # i = 0
      Loop:   
              slti t0, s0, 3      # se i < 3 então t0 = 1, senão t0 = 0
              beq  t0, zero, Exit  # se t0 == 0, pula para Exit
              addi s1, s1, 1       # j++
              addi s0, s0, 1       # i++
              j    Loop            # volta para o início do laço
      Exit:   
              nop                  # fim do programa
    