Roteiro Aprimorado da Apresentação

(Referente ao Slide 1: Título)

"Bom dia a todos. Meu nome é Fábio Volkmann Coelho, e sou aluno da disciplina de Internet das Coisas. Hoje, vou apresentar uma análise de um artigo de revisão que considero fundamental para a minha área de interesse: a aplicação de drones e Deep Learning para a detecção de ervas daninhas na agricultura."

(Referente ao Slide 2: Artigo Escolhido)

"O artigo que selecionei para este seminário é o 'Weed detection based on deep learning from UAV imagery: A review', de Lucía Sandoval-Pillajo e colaboradores. Ele foi publicado no periódico Smart Agricultural Technology, em sua edição de 2025. É importante destacar que se trata de uma Revisão Sistemática da Literatura, ou seja, um estudo que mapeia e sintetiza o conhecimento mais avançado de dezenas de outros trabalhos, nos dando um panorama completo do estado da arte."


(Referente ao Slide 3: Qualidade e Relevância Estratégica)

"Antes de mergulhar no conteúdo, quero justificar por que essa escolha é academicamente estratégica. O Documento de Área da Computação da CAPES, que norteia nossa pós-graduação, valoriza publicações em veículos de alto impacto. Este artigo foi publicado no 'Smart Agricultural Technology', um periódico internacional classificado como Q1, o que significa que está no grupo dos 25% melhores do mundo em sua área. Pelos critérios da CAPES, isso garante uma classificação nos estratos mais altos, como A1 ou A2. Além da qualidade do veículo, o artigo demonstra uma forte interdisciplinaridade, aplicando a Computação para resolver um problema crítico do agronegócio, algo que a CAPES incentiva. Por fim, como veremos, ele é indiretamente relevante para o meu projeto de dissertação, ajudando a validar a arquitetura e a identificar os principais desafios."

(Referente ao Slide 4: Introdução)

"O artigo nos contextualiza sobre um desafio global: a necessidade de aumentar a produção agrícola em 70% até 2050 para alimentar uma população de 9 bilhões de pessoas. Esse esforço enfrenta obstáculos como mudanças climáticas e, principalmente, a competição com ervas daninhas. Essas plantas invasoras disputam recursos vitais como água, luz e nutrientes, causando perdas massivas. O método de controle mais comum é o químico, mas seu uso indiscriminado é insustentável. Por isso, a agricultura de precisão propõe uma abordagem mais inteligente. A ideia, conhecida como Site-Specific Weed Management, é usar tecnologias como drones para identificar e aplicar herbicidas apenas nos locais exatos onde as ervas daninhas estão, reduzindo custos e o impacto ambiental."

(Referente ao Slide 5: Objetivos do Trabalho)

"Com esse cenário em mente, os objetivos dos autores foram claros: primeiro, realizar essa Revisão Sistemática para consolidar o conhecimento. Segundo, analisar o ecossistema tecnológico completo por trás dessa solução de IoT, desde os drones e sensores no campo até as arquiteturas de IA e as métricas de avaliação. E, o mais importante, usar essa análise para identificar as tendências, os desafios e as lacunas na pesquisa, apontando caminhos para trabalhos futuros."

(Referente ao Slide 6: Metodologia da Revisão)

"Para garantir a qualidade da análise, a metodologia foi extremamente rigorosa. A busca foi ampla, cobrindo 5 das maiores bases de dados científicas do mundo em um período recente, de 2017 a junho de 2024. O critério de inclusão foi o ponto-chave: apenas artigos publicados em periódicos de alto impacto, classificados como Q1 e Q2, foram considerados. No final, 77 estudos foram selecionados para uma análise aprofundada, garantindo que as conclusões da revisão são baseadas na ciência de melhor qualidade disponível."

(Referente ao Slide 7: Drones e Sensores Mais Utilizados)

"Passando aos resultados, a revisão mostrou um domínio absoluto dos drones da marca DJI, que foram usados em 81% dos estudos, principalmente pela sua acessibilidade. A grande maioria dos trabalhos utiliza câmeras RGB comuns, que enxergam como nossos olhos. No entanto, a tendência clara é a migração para sensores Multiespectrais, que captam informações em bandas de luz invisíveis e são muito mais precisos para diferenciar tipos de vegetação."

(Referente ao Slide 8: Parâmetros de Voo e Culturas)

"O estudo também revela que a coleta de dados é uma ciência. Os melhores resultados são obtidos em voos de baixa altitude, entre 2 e 10 metros , e a velocidades lentas, para garantir imagens de altíssima resolução e sem borrões. Até o horário do dia é um fator controlado, sendo o período entre 11h e 14h o ideal para minimizar sombras. As culturas mais estudadas foram as de grande escala, como beterraba, milho e arroz."

(Referente ao Slide 9: O Desafio da Preparação dos Dados)

"Aqui chegamos a um dos maiores gargalos da área: a preparação dos dados. O processo de 'ensinar' a IA, chamado de anotação manual, é onde humanos precisam desenhar caixas ao redor de cada erva daninha em milhares de imagens. Este é um trabalho extremamente lento, caro e propenso a erros, podendo levar até 10 horas para anotar uma única imagem complexa. A ferramenta mais popular para isso é a LabelImg. Para mitigar esse esforço, os pesquisadores usam estratégias como o Data Augmentation, para multiplicar artificialmente os dados, e a geração de dados sintéticos."

(Referente ao Slide 10: Arquiteturas de Deep Learning)

"Com os dados preparados, podemos treinar os modelos. A revisão mostra que, dependendo da tarefa, diferentes arquiteturas de IA se destacam: para Classificação, a família ResNet é a mais comum. Para Detecção, que é a tarefa de localizar a erva daninha, os modelos YOLO são dominantes por seu equilíbrio entre velocidade e precisão. E para a Segmentação, que define o contorno exato da planta, a arquitetura U-Net é o padrão. A grande tendência é a criação de modelos híbridos e mais leves, otimizados para rodar em tempo real."

(Referente ao Slide 11: Hardware e Métricas de Sucesso)

"Para executar esses modelos, o hardware é fundamental. O treinamento exige GPUs de alta performance, como a NVIDIA RTX 3090. Mas a tendência mais importante para IoT é o processamento no campo, usando Edge AI com dispositivos como o NVIDIA Jetson. Isso permite que o drone analise as imagens em tempo real, sem depender de internet. Para medir o sucesso, usamos métricas como Precisão, Recall e mAP para a detecção , e o IoU para a segmentação."

(Referente ao Slide 12: Principais Contribuições e Discussão)

"Sintetizando, a grande contribuição do artigo é consolidar o conhecimento e nos dar um mapa claro do estado da arte. E esse mapa nos mostra onde estão os três maiores gargalos que impedem a adoção em massa dessa tecnologia: o alto Custo Computacional do hardware ; a imensa dificuldade e o custo de obter dados de qualidade ; e a falta de robustez dos modelos para lidar com as condições imprevisíveis do mundo real." 

(Referente ao Slide 13: Conclusões e Perspectivas Futuras)

"A conclusão final dos autores é que a tecnologia é muito promissora, mas ainda não está totalmente madura para ser aplicada em larga escala. Para o futuro, a pesquisa precisa focar em três direções: otimizar os modelos para Edge AI, permitindo o processamento em tempo real ; um esforço comunitário para criar datasets públicos e diversificados ; e, o mais importante, a integração com sistemas de pulverização para fechar o ciclo de automação, transformando a detecção em ação."

(Referente ao Slide 14: Relevância para Minha Pesquisa - este é o ponto do slide 3 )

"E são justamente essas perspectivas futuras que se conectam diretamente com o meu projeto. Este artigo é fundamental para o meu trabalho, pois primeiro, ele valida a arquitetura que pretendo usar, com um drone DJI e um modelo YOLO. Segundo, ele me alerta que o meu maior desafio será a criação de um dataset de qualidade. E terceiro, a ênfase em Edge AI e na integração com atuadores reforça a visão do meu projeto de criar um sistema de IoT completo, de ponta a ponta, que não apenas detecta, mas também atua no ambiente."

(Referente ao Slide 15: Obrigado / Dúvidas?)

"Com essa reflexão, encerro minha apresentação. Agradeço a atenção de todos e fico agora à disposição para perguntas ou para discutirmos mais sobre o tema."