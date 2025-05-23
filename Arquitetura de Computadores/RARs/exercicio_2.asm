    # ------------------------------------------------------------
    # Exercício 02 - Baseado em Patterson pags. 54/55/56 (versão RISC-V)
    # Expressão em C: A[12] = h + A[8]
    # ------------------------------------------------------------
        
        .data
        Array_A: .word 0, 10, 20, 30, 40, 50, 60, 70,
                       80, 90, 100, 110, 120, 130, 140, 150
        
        .text
    main:
        addi s2, zero, 1         # h = 1
        la   s3, Array_A         # s3 = endereço base do vetor A
        lw   t0, 32(s3)          # t0 = A[8] (32 = 4 * 8)
        add  t0, s2, t0          # t0 = h + A[8]
        sw   t0, 48(s3)          # A[12] = t0 (48 = 4 * 12)