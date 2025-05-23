    # ------------------------------------------------------------
    # Exercício 03 - Patterson pag. 65 (versão RISC-V)
    # if (i != j)
    #     f = g + h;
    # f = f - i;
    # ------------------------------------------------------------
        
        .text
    main:
        addi s0, zero, 15     # f = 15
        addi s1, zero, 10     # g = 10
        addi s2, zero, 20     # h = 20
        addi s3, zero, 1      # i = 1
        addi s4, zero, 1      # j = 2
    
        beq  s3, s4, L1       # if (i == j) goto L1
        add  s0, s1, s2       # f = g + h
    
    L1:
        sub  s0, s0, s3       # f = f - i