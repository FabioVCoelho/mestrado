# Projeto: IA para Mitigar Estresse Hídrico no Milho

Data de entrega: 16/09/2025

Este repositório contém a proposta de sistema computacional a ser implementado na disciplina de Aprendizado de Máquina. O projeto envolve a aplicação de algoritmos de ML em um problema relevante na agricultura: detecção e previsão de estresse hídrico em lavouras de milho, usando dados multissafras coletados em campo.

## 1. Descrição do problema (contextualização e relevância)
O estresse hídrico é um dos principais fatores de queda de produtividade no milho no Brasil. Em regiões com chuvas irregulares e alta variabilidade climática, identificar precocemente o estresse e orientar ações de manejo (irrigação e adubação) pode evitar perdas significativas. Propomos construir um sistema de IA que:
- detecte sinais precoces de estresse hídrico ao longo do ciclo; e
- estime impactos esperados na produtividade, apoiando decisões de manejo.

## 2. Objetivos do trabalho
- Construir um dataset integrado a partir de medições de campo, clima e fenologia.  
- Desenvolver pipelines de pré-processamento e engenharia de atributos temporais.  
- Treinar e avaliar modelos de ML para:  
  - classificação de estresse hídrico (Sim/Não) por período;  
  - predição de produtividade ao final da safra.  
- Empregar validações cruzadas seguras (tempo e grupos) para evitar vazamento de informações.  
- Entregar código reprodutível e relatório de resultados.

## 3. Definição do dataset a ser utilizado
Os arquivos estão na pasta `data/` e incluem (amostras reais do projeto):
- Fenologia: `Fenologia inicial.xlsx`, `Fenologia completa.xlsx`, `Maturidade fisiologica.xlsx`
- Solo e clima: `Umidade de solo.xlsx`, `Umidade a partir do ponto pamonha.xlsx`
- Componentes de rendimento: `Espigas.xlsx`, `Pesos.xlsx`, `Dados de colheita.xlsx`
- Operacional e metadata: `Metadados.docx`

Chaves e granularidade esperadas:
- Safra/ano, talhão/parcela, data da medição, híbrido/variedade, localização.  
As tabelas serão integradas por essas chaves, respeitando ordem temporal.

## 4. Resultados preliminares do pré-processamento
- Mapeamento das variáveis e dicionário inicial de dados (ver seção 3).  
- Checagens planejadas: consistência de datas, unidades (mm, °C), normalização de nomes de talhões, remoção de duplicados.  
- Features temporais propostas: médias móveis, lags de umidade do solo por profundidade, acumulados de chuva por janelas (7/14/30 dias), graus-dia, indicadores por fase fenológica.  
- Tratamento de faltantes: imputação por forward-fill dentro do talhão e regressão auxiliar para clima quando disponível.  
- Padronização/escala e codificação via Pipeline do scikit-learn.

## 5. Algoritmo de ML, APIs e softwares
- Linguagem: Python 3.x.  
- Bibliotecas: pandas, numpy, scikit-learn, matplotlib/seaborn; opcional: xgboost, lightgbm.  
- Modelos candidatos: Regressão Linear Regularizada, Random Forest, Gradient Boosting, XGBoost/LightGBM; para classificação, Logistic Regression e Árvores/Ensembles.  
- Pipeline e validação: scikit-learn Pipeline + TimeSeriesSplit/GroupKFold.  
- Ambiente: Jupyter/VSCode/PyCharm.  

## 6. Resultados esperados
- Curvas de desempenho em validação cruzada realista (leave-one-season/location-out e forward-chaining).  
- Métricas: MAE/RMSE para produtividade; F1/AUC para estresse hídrico.  
- Análises de importância de variáveis e interpretação (SHAP/feature importance).  
- Entregáveis: código, README, figuras e relatório.

## 7. Escopo de dados que comporão o dataset
Fases fenológicas: emergência/estabelecimento, pendoamento, espigamento, enchimento de grãos.

Dados fisiológicos: redução de área foliar, fotossíntese (índice/taxa), abortamento floral e de grãos, altura de planta, número e tamanho de espigas, produtividade por hectare.

Sinais visuais de estresse: enrolamento de folhas, murchamento, coloração anormal, espigas pequenas/ausentes.

Manejo hídrico e agronômico: irrigação (volume e frequência), adubação (tipo, data, dose, modo), aplicação de nutrientes.

Clima/ambiente: precipitação diária, umidade de solo por profundidade, temperaturas (min/máx/média), radiação solar, vento, déficit de pressão de vapor.

Pré-plantio/solo: tipo de solo, matéria orgânica, pH, capacidade de retenção, profundidade do solo arável, método de preparo.

Sensoriamento remoto: NDVI/NDWI/SAVI, mapas de umidade, imagens multiespectrais/térmicas.

Operacional da fazenda: datas de plantio/colheita, híbrido, densidade de plantio, mapeamento de talhões, histórico de produtividade.

Sensores: umidade do solo por profundidade, estação climática local, sondas de CE.

Produtividade: número de espigas/planta, tamanho médio das espigas, peso médio de grãos por espiga, produtividade estimada e real (kg/ha).

Eventos extremos: geadas, veranicos, alagamentos.

Indicadores de solo ao longo da safra: compactação, condutividade elétrica, armazenamento de água.

Dados genéticos/híbridos: para treinar recomendações por zona agrícola.

## 8. Validação cruzada recomendada
- TimeSeriesSplit com janela crescente e gap para purgar vazamento quando houver janelas sobrepostas.  
- GroupKFold/Leave-One-Group-Out por safra/ano, talhão, híbrido ou localização.  
- Para classificação de estresse: StratifiedGroupKFold quando disponível.  
- Opção de validação aninhada: outer LOGO por safra/local; inner TSS para ajuste de hiperparâmetros.

## 9. Como reproduzir
- Organize os dados em `Machine Learning/Project_1/data/`.  
- Execute primeiro o notebook `notebooks/00_exploracao_dados.ipynb` para carregar as tabelas e ver os resumos/TODOs de pré-processamento.  
- Em seguida, crie/complete o notebook `notebooks/01_preprocess_e_modelagem.ipynb` com o pipeline descrito.  
- Execute as avaliações com os esquemas de validação da seção 8 e reporte as métricas da seção 6.