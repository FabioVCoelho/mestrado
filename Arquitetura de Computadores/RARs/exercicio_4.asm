    # ------------------------------------------------------------
    # Exercício 04 - Patterson pag. 65/66 (versão RISC-V)
    # if (i == j)
    #     f = g + h;
    # else
    #     f = g - h;
    # ------------------------------------------------------------
            
            .text
        main:
            addi s1, zero, 10     # g = 10
            addi s2, zero, 20     # h = 20
            addi s3, zero, 1      # i = 1
            addi s4, zero, 1      # j = 2
        
            bne  s3, s4, Else     # if (i != j) goto Else
            add  s0, s1, s2       # f = g + h
            j Exit                # goto Exit
        
        Else:
            sub  s0, s1, s2       # f = g - h
        
        Exit:
            nop