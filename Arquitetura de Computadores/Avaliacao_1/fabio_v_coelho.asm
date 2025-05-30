      # Disciplina: Arquitetura de Computadores
      # Atividade: Avaliação 01 – Programação em Linguagem de Montagem
      # Alunos: Fábio Volkamnn Coelho
      # ------------------------------------------------------------
      # Trecho em C: 
      # while(i < indices) {
      #    if(vetor[i] > maior_valor) {
      #        maior_valor = vetor[i];  
      #        k = i;                   
      #    }
      #    i = i + 1;
      # }
      # ------------------------------------------------------------

	.data
	vetor: .word 3, 3, 1, 3, 3, 1, 4, 3 # save[0] até save[7]
	
	.text
	main:
	    la   s6, vetor      # endereço base de save[]
	    addi s5, zero, 8    # indices = numero de valores no vetor
	    lw   s0, 0(s6)      # maior_valor = primeiro valor é o maior no momento, salvo em s0
	    addi s3, zero, 1    # i = inicializa contador do loop
	    addi s1, zero, 0    # k = inicializa o indice do maior valor
	
	Loop:
            slli t1, s3, 2          # t1 = i * 4
	    add  t1, t1, s6         # t1 = endereço de vetor[i]
	    lw   t0, 0(t1)          # t0 = vetor[i]
	    ble  t0, s0, continue   # se t0 <= s0, pula atualização do máximo
	    add  s0, t0, zero       # atualiza o maior valor (s0 = t0)
	    add  s1, s3, zero       # atualiza o indice do maior valor (s1 = s3)
	
	continue:
	    addi s3, s3, 1          # i++
	    blt  s3, s5, Loop       # se i < tamanho do vetor, continua loop
	    
	Exit:
	    nop                     # fim do laço (s0 contém o maior valor e s1 contém o valor do indice)